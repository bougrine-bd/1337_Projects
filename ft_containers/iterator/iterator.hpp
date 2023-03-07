#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include <iterator>
#include <cstddef>
#include "../map/AVL.hpp"
#include "../utilities/utilities.hpp"

namespace ft{

	//title:  Random access iterator

	template <typename T, typename Category = std::random_access_iterator_tag>
	class VectorIterator
	{
		public:
			typedef typename ft::iterator<Category, T>::difference_type		difference_type;
			typedef typename ft::iterator<Category, T>::value_type			value_type;
			typedef typename ft::iterator<Category, T>::pointer				pointer;
			typedef typename ft::iterator<Category, T>::reference			reference;
			typedef typename ft::iterator<Category, T>::iterator_category	iterator_category;
		private:
			pointer _ptr;
		public:
			VectorIterator() : _ptr(NULL){}
			VectorIterator(pointer array) : _ptr(array){}
			VectorIterator(const VectorIterator &obj)
			{
				*this = obj;
			}
			VectorIterator &operator=(const VectorIterator &obj)
			{
				_ptr = obj._ptr;
				return *this;
			}
			~VectorIterator()
			{}

			operator VectorIterator<const value_type> ()
			{
				return (VectorIterator<const value_type>(_ptr));
			} 


			T		&operator * (){
				return (*_ptr);
			}
			pointer		operator-> (){
				return (this->_ptr);
			}

			VectorIterator	&operator++ (){
				++_ptr;
				return (*this);
			}
			VectorIterator	operator++ (int){
				VectorIterator temp = *this; 
				++_ptr;
				return (temp);
			}
			VectorIterator	&operator-- (){
				--_ptr;
				return (*this);
			}
			VectorIterator	operator-- (int){
				VectorIterator temp = *this;
				--_ptr;
				return (temp);
			}

			VectorIterator operator + (difference_type num)
			{
				VectorIterator iter(*this);
				iter._ptr += num;
				return (iter);
			}
			friend VectorIterator operator + (difference_type num, const VectorIterator &obj)
			{
				VectorIterator iter = obj;
				iter += num;
				return (iter);
			}

			VectorIterator operator - (difference_type num)
			{
				return (_ptr - num);
			}
			difference_type operator - (const VectorIterator &obj)
			{
				return (_ptr - obj._ptr);
			}
			VectorIterator &operator += (difference_type num)
			{
				_ptr += num;
				return *this;
			}
			VectorIterator &operator -= (difference_type num)
			{
				*this += -num;
				return *this;
			}
			
			value_type	&operator [] (size_t index){
				return (_ptr[index]);
			}

			friend bool	operator == (const VectorIterator &obj1, const VectorIterator &obj2)
			{
				return (obj1._ptr == obj2._ptr);
			}
			friend bool	operator != (const VectorIterator &obj1, const VectorIterator &obj2)
			{
				return (obj1._ptr != obj2._ptr);
			}
			friend bool	operator < (const VectorIterator &obj1, const VectorIterator &obj2)
			{
				return (obj1._ptr < obj2._ptr);
			}
			friend bool	operator <= (const VectorIterator &obj1, const VectorIterator &obj2)
			{
				return (obj1._ptr <= obj2._ptr);
			}
			friend bool	operator > (const VectorIterator &obj1, const VectorIterator &obj2)
			{
				return (obj1._ptr > obj2._ptr);
			}
			friend bool	operator >= (const VectorIterator &obj1, const VectorIterator &obj2)
			{
				return (obj1._ptr >= obj2._ptr);
			}
	};

	//title: bidirectional iterator 

	template <typename T, typename Category = std::bidirectional_iterator_tag>
	class treeIterator
	{
		public:
			typedef typename ft::iterator<Category, T>::value_type			value_type;
			typedef typename ft::iterator<Category, T>::pointer				pointer;
			typedef typename ft::iterator<Category, T>::reference			reference;
			typedef typename ft::iterator<Category, T>::difference_type		difference_type;
			typedef typename ft::iterator<Category, T>::iterator_category	iterator_category;
			typedef ft::Node<value_type>	Node;
			typedef ft::Node<value_type>*	ptrNode;
		private:
			ptrNode _root;
			ptrNode _end;
		private:
				ptrNode maxNode(ptrNode node)
				{
					ptrNode tempNode = node;
					while (tempNode->rightNode != _end)
						tempNode = tempNode->rightNode;
					return (tempNode);
				}

				ptrNode minNode(ptrNode node)
				{
					ptrNode tempNode = node;
					while (tempNode->leftNode != _end)
						tempNode = tempNode->leftNode;
					return (tempNode);
				}
				
				ptrNode successor (ptrNode node)
				{
					if (node->rightNode != _end && node->rightNode)
						return (minNode(node->rightNode));
					ptrNode parent = node->parent;
					while (node != _end && parent && parent->rightNode == node)
					{
						node = parent;
						parent = node->parent;
					}
					if (!parent)
						return (_end);
					return (parent);
				}

				ptrNode  predecessor(ptrNode node)
				{
					if (node->leftNode != _end && node->leftNode)
						return (maxNode(node->leftNode));
					ptrNode parent = node->parent;
					while (node != _end && parent && parent->leftNode == node)
					{
						node = parent;
						parent = node->parent;
					}
					if (!parent)
						return (_end);
					return (parent);
				}
		
		public:
			treeIterator() : _root(NULL), _end(NULL) {}
			treeIterator(ptrNode node, ptrNode endNode) : _root(node), _end(endNode){}

			~treeIterator(){}

			operator treeIterator<const value_type> () const
			{
				return (treeIterator<const value_type>(reinterpret_cast<typename treeIterator<const value_type>::ptrNode>(_root), reinterpret_cast<typename treeIterator<const value_type>::ptrNode>(_end)));
			} 

			ptrNode base()
			{
				return (_root);
			}
			reference operator * () const{
				return (_root->pair);
			}
			pointer operator -> () const{
				return (&_root->pair);
			}

			treeIterator &operator ++ (){
				_root = successor(_root);
				return (*this);
			}

			treeIterator operator ++ (int){
				treeIterator temp(_root, _end);
				++(*this);
				return (temp);
			}

			treeIterator &operator -- (){
				_root = predecessor(_root);
				return (*this);
			}

			treeIterator operator -- (int){
				treeIterator temp(_root, _end);
				--(*this);
				return (temp);
			}

			friend bool	operator == (const treeIterator &obj1, const treeIterator &obj2)
			{
				return (obj1._root == obj2._root);
			}
			friend bool	operator != (const treeIterator &obj1, const treeIterator &obj2)
			{
				return (obj1._root != obj2._root);
			}
	};

}//namespace ft end 

#endif