#ifndef MAP_HPP
#define MAP_HPP

#include "AVL.hpp"
#include "../iterator/iterator.hpp"
#include "../iterator/reverse_iterator.hpp"
#include "../utilities/utilities.hpp"

namespace ft
{
	template < typename Key, typename T, typename Compare = std::less<Key>, typename Alloc = std::allocator<Pair<const Key, T> > >
	class map
	{
		public:
			typedef Key 										key_type;
			typedef T											mapped_type;
			typedef Pair<const Key, T>							value_type;
			typedef Compare										key_compare;

			typedef Alloc										allocator_type;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;

			typedef size_t 									size_type;
			typedef std::ptrdiff_t							difference_type;

			typedef treeIterator<value_type>				iterator;
			typedef treeIterator<const value_type>			const_iterator;
			typedef reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef reverse_iterator<iterator>				reverse_iterator;

		private:
			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}
				public:
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

		private:
			typedef AVLTree<value_type, key_compare, allocator_type >	AVL;
			typedef ft::Node<value_type>	Node;

		private:
			AVL				_tree;

		public:
			explicit map (const key_compare& comp = key_compare(),
            			const allocator_type& alloc = allocator_type()) : _tree(comp, alloc){}

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()) : _tree(comp, alloc)
			{
				insert(first, last);
			}
			
			map (const map	&mp) : _tree()
			{
				*this = mp;
			}

			map& operator= (const map& mp)
			{
				if (this != &mp)
				{
					clear();
					insert(mp.begin(), mp.end());
				}
				return (*this);
			}

			~map ()
			{
				clear();
			}

			bool empty() const
			{
				return (_tree.empty());
			}

			size_type size() const
			{
				return (_tree.size());
			}

			size_type max_size() const
			{
				return (_tree.max_size());
			}

			//title: Modifiers

			Pair<iterator,bool> insert (const value_type& val)
			{
				Node *temp = _tree.find(val);

				if (temp != _tree._end)
					return (Pair<iterator, bool>(iterator(temp, _tree._end), false));
				else
				{
					_tree._root = _tree.insertion(NULL, _tree._root, &val);
					temp = _tree.find(val);
					return (Pair<iterator, bool>(iterator(temp, _tree._end), true));
				}
			}
			
			iterator insert (iterator position, const value_type& val)
			{
				(void)position;
				return (insert(val).first);
			}
			
			template <class InputIterator>
  			void insert (InputIterator first, InputIterator last)
			{
				for (;first != last; ++first)
					insert(*first);
			}

			void erase (iterator position)
			{
				_tree._root = _tree.deletion(_tree._root, &(position.base()->pair));
			}
			
			size_type erase (const key_type& k)
			{
				if (count(k))
				{
					erase(find(k));
					return (1);
				}
				return (0);
			}

    		void erase (iterator first, iterator last)
			{
				std::vector <key_type> key_to_remove;
				while (first != last)
				{
					key_to_remove.push_back(first->first);
                    first++;
				}
				for (size_t i = 0; i < key_to_remove.size(); i++)
                    erase(key_to_remove[i]);
			}

			void swap (map& x)
			{
				_tree.swap(x._tree);
			}

			void clear()
			{
				_tree.clear(_tree._root);
			}


			//title: Iterators

			iterator begin()
			{
				iterator itre(_tree.minNode(_tree._root), _tree._end);
				return (itre);
			}
			
			const_iterator begin() const
			{
				iterator citre(_tree.minNode(_tree._root), _tree._end);
				return (citre);
			}

			iterator end()
			{
				iterator itre(_tree._end, _tree._end);
				return (itre);
			}

			const_iterator end() const
			{
				iterator citre(_tree._end, _tree._end);
				return (citre);
			}

			reverse_iterator rbegin()
			{
				reverse_iterator ritre(end());
				return (ritre);
			}

			const_reverse_iterator rbegin() const
			{
				const_reverse_iterator critre(end());
				return (critre);
			}

			reverse_iterator rend()
			{
				reverse_iterator ritre(begin());
				return (ritre);
			}

			const_reverse_iterator rend() const
			{
				const_reverse_iterator critre(begin());
				return (critre);
			}
	
			//title: Operations

			iterator find (const key_type& k)
			{
				value_type pair = ft::make_pair(k, mapped_type());
				iterator iter(_tree.find(pair), _tree._end);
				return (iter);
			}
			const_iterator find (const key_type& k) const
			{
				value_type pair = ft::make_pair(k, mapped_type());
				const_iterator iter(_tree.find(pair), _tree._end);
				return (iter);
			}
			
			size_type count (const key_type& k) const
			{
				value_type pair = ft::make_pair(k, mapped_type());
				if (_tree.find(pair) != _tree._end)
					return (1);
				return (0);
			}

			iterator lower_bound (const key_type& k)
			{
				return (iterator(_tree.lower_bound(ft::make_pair(k, mapped_type())), _tree._end));
			}

			const_iterator lower_bound (const key_type& k) const
			{
				return (iterator(_tree.lower_bound(ft::make_pair(k, mapped_type())), _tree._end));
			}

			iterator upper_bound (const key_type& k)
			{
				return (iterator(_tree.upper_bound(ft::make_pair(k, mapped_type())), _tree._end));
			}
			const_iterator upper_bound (const key_type& k) const
			{
				return (iterator(_tree.upper_bound(ft::make_pair(k, mapped_type())), _tree._end));
			}

			Pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				return (ft::make_pair<const_iterator,const_iterator> (lower_bound(k), upper_bound(k)));
			}
			Pair<iterator,iterator>             equal_range (const key_type& k)
			{
				return (ft::make_pair<iterator,iterator> (lower_bound(k), upper_bound(k)));
			}

			//title: Element access

			mapped_type& operator[] (const key_type& k)
			{
				value_type pair = ft::make_pair(k, mapped_type());
				return (insert(pair).first->second);
			}

			//title: Observers
			
			key_compare key_comp() const
			{
				return (_tree._comp);
			}
			value_compare value_comp() const
			{
				return (value_compare(_tree._comp));
			}
			
			//title: Allocator

			allocator_type get_allocator() const
			{
				return (_tree._allocator);
			}
		public:
			friend bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
			{
				if (lhs.size() == rhs.size())
					return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
				return (false);
			}
			friend bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
			{
				return (!(lhs == rhs));
			}
			friend bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
			{
				return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
			}
			friend bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
			{
				return (!(rhs < lhs));
			}
			friend bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
			{
				return (rhs < lhs);
			}
			friend bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
			{
				return (!(lhs < rhs));
			}
			friend void swap (map<Key,T,Compare,Alloc>& lhs, map<Key,T,Compare,Alloc>& rhs)
			{
				lhs.swap(rhs);
			}
	};

}//namespace ft end 

#endif