#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include "pair.hpp"

namespace ft
{
	//title: Node 
	template <typename T>
	class Node
	{
		public:
			typedef T	value_type;
		public:
			value_type		pair;
			Node			*parent;
			Node			*leftNode;
			Node			*rightNode;
			int				height;
		public:
			Node () : pair(), parent(NULL), leftNode(NULL), rightNode(NULL), height(0){}
			Node (Node *newParent, Node *newLeftNode , Node *newRightNode, T newPair)
				: pair(newPair), parent(newParent), leftNode(newLeftNode), rightNode(newRightNode), height(1){}
			~Node(){}
	};

	//title: AVL tree
	template < typename T, typename Compare, typename Allocator >
	class AVLTree
	{
		public:
			typedef T			value_type;
			typedef Node<T>		Node;
			typedef typename Allocator::template rebind<Node >::other	allocator_type;
			typedef Allocator	pair_allocator_type;
			typedef size_t		size_type;

		public:
			Compare				_comp;
			allocator_type		_allocator;
			pair_allocator_type	_pairAllocator;
			Node				*_root;
			Node				*_end;
			size_type			_size;
		public:
		 	AVLTree(const Compare& comp = Compare(), const allocator_type& allocator = allocator_type()) : _comp(comp), _allocator(allocator), _root(NULL), _size(0) 
			{
				_end = _allocator.allocate(1);
				_allocator.construct(_end, Node());
				_root = _end;
			} 

			~AVLTree()
			{
				_allocator.destroy(_end);
				_allocator.deallocate(_end, 1);
			}
	
			int max (int lhs, int rhs)
			{
				if (lhs > rhs)
					return (lhs);
				return (rhs);
			}

			int height(Node *node)
			{
				if (node == _end)
					return (0);
				return (node->height);
			}

			Node *createNode(Node *parent, const value_type *pair)
			{
				Node *newNode = _allocator.allocate(1);
				_allocator.construct(newNode, Node(parent, _end, _end, *pair));
				return (newNode);
			}

			int	balanceFactor(Node *node)
			{
				return (height(node->leftNode) - height(node->rightNode));
			}

			Node *maxNode(Node *node) const
			{
				if (node == _end)
					return (node);
				Node *tempNode = node;
				while (tempNode->rightNode != _end)
					tempNode = tempNode->rightNode;
				return (tempNode);
			}

			Node *minNode(Node *node) const
			{
				if (node == _end)
					return (node);
				Node *tempNode = node;
				while (tempNode->leftNode != _end)
					tempNode = tempNode->leftNode;
				return (tempNode);
			}

			Node *rightRotate(Node *nodeParent, Node *node)
			{
				Node *newRoot = node->leftNode;
				Node *newRootRight = newRoot->rightNode;

				newRoot->rightNode = node;
				node->leftNode = newRootRight;
				newRootRight->parent = node;
				node->parent = newRoot;
				newRoot->parent = nodeParent;

				node->height = max(height(node->leftNode), height(node->rightNode)) + 1;
				newRoot->height = max(height(newRoot->leftNode), height(newRoot->rightNode)) + 1;
				return (newRoot);
			}

			Node *leftRotate(Node *back, Node *node)
			{
				Node *newRoot = node->rightNode;
				Node *newRootLeft = newRoot->leftNode;

				newRoot->leftNode = node;
				node->rightNode = newRootLeft;
				newRootLeft->parent = node;
				node->parent = newRoot;
				newRoot->parent = back;

				node->height = max(height(node->leftNode), height(node->rightNode)) + 1;
				newRoot->height = max(height(newRoot->leftNode), height(newRoot->rightNode))+ 1;
				return (newRoot);
			}
	
			Node *insertion(Node *back, Node *current, const value_type *pair)
			{
				if (current == _end)
				{
					++_size;
					current = createNode(back, pair);
					_end->parent = maxNode(current);
					return (current);
				}
				
				if (_comp(pair->first, current->pair.first))
					current->leftNode = insertion(current, current->leftNode, pair);
				else if (_comp(current->pair.first, pair->first))
					current->rightNode = insertion(current, current->rightNode, pair);
				else
				{
					_end->parent = maxNode(current);
					return (current);
				}

				current->height = max(height(current->leftNode), height(current->rightNode)) + 1;
				int bFactor = balanceFactor(current);


				if (bFactor < -1 && _comp(current->rightNode->pair.first, pair->first))
					current = leftRotate(current->parent, current);
				else if (bFactor < -1 && !_comp(current->rightNode->pair.first, pair->first))
				{
					current->rightNode = rightRotate(current, current->rightNode);
					current = leftRotate(current->parent, current);
				}
				else if (bFactor > 1 && !_comp(current->leftNode->pair.first, pair->first))
					current = rightRotate(current->parent, current);
				else if (bFactor > 1 && _comp(current->leftNode->pair.first, pair->first))
				{
					current->leftNode = leftRotate(current, current->leftNode);
					current = rightRotate(current->parent, current);
				}
				_end->parent = maxNode(current);
				return (current);
			}

			Node *deletion(Node *current, value_type *pair)
			{
				if (current == _end)
				{
					_end->parent = maxNode(current);
					return (current);
				}

				if (_comp(pair->first, current->pair.first))
					current->leftNode = deletion(current->leftNode, pair);
				else if (_comp(current->pair.first, pair->first))
					current->rightNode = deletion(current->rightNode, pair);
				else
				{
					if (current->leftNode == _end || current->rightNode == _end)
					{
						Node *temp = current->leftNode != _end ? current->leftNode : current->rightNode;
						if (temp  == _end)
						{
							temp = current;
							current = _end;
						}
						else
						{
							current->leftNode = temp->leftNode;
							current->rightNode = temp->rightNode;
							current->height = temp->height;
							_pairAllocator.construct(&current->pair, temp->pair);
						}
						_allocator.destroy(temp);
						_allocator.deallocate(temp, 1);
						--_size;
					}
					else
					{
						Node *successor = minNode(current->rightNode);
						_pairAllocator.construct(&current->pair, successor->pair);
						current->rightNode =  deletion(current->rightNode, &successor->pair);
					}
				}
				if (current == _end)
				{
					_end->parent = maxNode(current);
					return (current);
				}

				current->height = max(height(current->leftNode), height(current->rightNode)) + 1;
				int bFactor = balanceFactor(current);
				if (bFactor < -1)
				{
					if (balanceFactor(current->rightNode) <= 0)
						current = leftRotate(current->parent, current);
					else
					{
						current->rightNode = rightRotate(current, current->rightNode);
						current = leftRotate(current->parent, current);
					}
				}
				else if (bFactor > 1)
				{
					if (balanceFactor(current->leftNode)  >= 1)
						current = rightRotate(current->parent, current);
					else
					{
						current->leftNode = leftRotate(current, current->leftNode);
						current = rightRotate(current->parent , current);
					}
				}
				_end->parent = maxNode(current);
				return (current);
			}
	
			bool empty() const
			{
				return (_size == 0);
			}
			
			size_type size() const
			{
				return (_size);
			}

			size_type max_size() const
			{
				return(_allocator.max_size());
			}

			Node *find (const value_type& k) const
			{
				Node *current = _root;
				while (current != _end)
				{
					if (_comp(k.first, current->pair.first))
						current = current->leftNode;
					else if (_comp(current->pair.first, k.first))
						current = current->rightNode;
					else
						return (current);
				}
				return (_end);
			}

			void swap (AVLTree &newTree)
			{
				Compare 		tpCompare = _comp;
				allocator_type	tpAllocator = _allocator;
				Node			*tpNode = _root;
				Node			*tpEnd = _end;
				size_type		tpSize = _size;

				_comp = newTree._comp;
				_allocator = newTree._allocator;
				_root = newTree._root;
				_end = newTree._end;
				_size = newTree._size;

				newTree._comp = tpCompare;
				newTree._allocator = tpAllocator;
				newTree._root = tpNode;
				newTree._end = tpEnd;
				newTree._size = tpSize;
			}

			void clear(Node *node)
			{
				if (node != _end && node)
				{
					Node *current = node;

					if (current->leftNode != _end)
						clear(current->leftNode);
					if (current->rightNode != _end)
						clear(current->rightNode);
					if (!current->parent)
						_root = _end;
					_allocator.destroy(current);
					_allocator.deallocate(current, 1);

				}
				_size = 0;
			}

			Node *lower_bound (const value_type& k) const
			{
				Node *currentNode = minNode(_root);

				while (!_comp(k.first , currentNode->pair.first))
				{
					if (k.first == currentNode->pair.first)
						break;
					currentNode = successor(currentNode);
					if (currentNode == _end)
						return (_end);
				}
				return (currentNode);
			}
			Node *upper_bound (const value_type& k) const
			{
				Node *currentNode = minNode(_root);

				while (!_comp(k.first , currentNode->pair.first))
				{
					currentNode = successor(currentNode);
					if (currentNode == _end)
						return (_end);
				}
				return (currentNode);
			}
		private:
			Node *successor (Node *node) const
			{
				if (node->rightNode != _end && node->rightNode)
					return (minNode(node->rightNode));
				Node *parent = node->parent;
				while (node != _end && parent && parent->rightNode == node)
				{
					node = parent;
					parent = node->parent;
				}
				if (!parent)
					return (_end);
				return (parent);
			}

	};
}//namespace ft end 

#endif