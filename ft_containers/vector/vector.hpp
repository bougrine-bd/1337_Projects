#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include "../iterator/iterator.hpp"
#include "../iterator/reverse_iterator.hpp"
#include "../utilities/utilities.hpp"
#include <stdexcept> // exception out_of_range 

namespace ft 
{
	template < typename T, typename Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T											value_type;

			typedef Alloc										allocator_type;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;

			typedef size_t										size_type;
			typedef std::ptrdiff_t								difference_type;

			typedef	VectorIterator<value_type>				iterator;
			typedef	VectorIterator<const value_type>		const_iterator;
			typedef	reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef	reverse_iterator<iterator>				reverse_iterator;
			
		private:
			pointer					_array;
			size_type				_size;
			size_type				_capacity;
			allocator_type			_allocator;
		
		private:
			void	moveElements(size_type start, size_type end)
			{
				size_type j = _size - 1;
				size_type i = end;

				while (&_array[j] >= &_array[start])
				{
					_allocator.construct(&_array[i], _array[j]);
					--j;
					--i;
				}
			}
			void	eraseElements(value_type *src, size_type start, size_type end, size_t n)
			{
				while (&src[start] < &src[end])
				{
					_allocator.construct(&src[start], src[start + n]);
					++start;
				}
			}
		
		public:
			explicit vector(const allocator_type& alloc = allocator_type())
			: _array(NULL), _size(0), _capacity(0), _allocator(alloc){}

			explicit vector(size_type n, value_type val = value_type(),
							const allocator_type& alloc = allocator_type())
							: _size(n), _capacity(n), _allocator(alloc)
			{
				_array = _allocator.allocate(n);
				for (size_type i = 0; i < n; ++i)
					_allocator.construct(&_array[i], val);
			}

			template <typename InputIterator>
			vector (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()
					, const allocator_type& alloc = allocator_type()): _allocator(alloc)
			{
				difference_type n = std::distance(first, last);
				size_t j = 0;

				_array = _allocator.allocate(n);
				for (InputIterator i = first; i != last; ++i, ++j)
					_allocator.construct(&_array[j], *i);
				_size = _capacity = n;
			}
			
			vector(const vector& obj) : _array(NULL), _size(0), _capacity(0), _allocator(allocator_type())
			{
				*this = obj;
			}

			vector& operator= (const vector& obj)
			{
				if (this != &obj)
				{
					clear();
					_allocator.deallocate(_array, _capacity);
					_size = obj._size;
					_capacity = obj._capacity;
					_allocator = obj._allocator;
					_array = _allocator.allocate(_capacity);
					for (size_type i = 0; i < _size; ++i)
						_allocator.construct(&_array[i], obj._array[i]);
				}
				return (*this);
			}

			~vector()
			{
				clear();
				_capacity = 0;
				_allocator.deallocate(_array, _capacity);
			}

			//title: Capacity
			size_type	size() const
			{
				return (_size);
			}

			size_type	max_size() const 
			{
				return (_allocator.max_size());
			}
			
			size_type	capacity() const
			{
				return (_capacity);
			}
			
			bool	empty() const
			{
				return (_size == 0);
			}

			void	resize (size_type n, value_type init_n = value_type())
			{
				size_type	oldcapacity = _capacity;
				if (n > _size)
				{
					if (n > _capacity)
					{
						_capacity *= 2;
						if (n > _capacity)
							_capacity = n;

						pointer		tmArray = _allocator.allocate(_capacity);
						for (size_type i = 0; i < n; ++i)
						{
							if (i < _size)
								_allocator.construct(&tmArray[i], _array[i]);
							else
								_allocator.construct(&tmArray[i], init_n);
						}
						if (_array)
						{
							_allocator.destroy(_array);
							_allocator.deallocate(_array, oldcapacity);
						}
						_array = tmArray;
					}
					else
					{
						for (size_type i = 0; i < n; ++i)
						{
							if (i >= _size)
								_allocator.construct(&_array[i], init_n);
						}
					}
				}
				else
				{
					for (size_type i = 0; i < _size; i++)
					{
						if (i > n)
							_allocator.destroy(&_array[i]);
					}
				}
				_size = n;
			}

			void	reserve (size_type n)
			{
				if (n > _capacity)
				{
					pointer tmArray = _allocator.allocate(n);
					for (size_type i = 0; i < _size; ++i)
						_allocator.construct(&tmArray[i], _array[i]);
					if (_array)
					{
						_allocator.destroy(_array);
						_allocator.deallocate(_array, _capacity);
					}
					_array = tmArray;
					_capacity = n;
				}
			}

			//title: Modifiers
			void push_back (const value_type& val)
			{
				if (_size + 1 > _capacity)
					resize(_size + 1, val);
				else
				{
					_allocator.construct(&_array[_size], val);
					++_size;
				}
			}

			void pop_back()
			{
				_allocator.destroy(&_array[_size]);
				--_size;
			}

			void clear()
			{

				for (size_type i = 0; i < _size; ++i)
					_allocator.destroy(&_array[i]);
				_size = 0;
			}

			void assign (size_type n, const value_type& val = value_type())
			{
				if (n > _capacity)
					reserve(n);
				for (size_type i = 0; i < n; ++i)
					_allocator.construct(&_array[i], val);
				_size = n;
			}

			template <typename InputIterator>
			void assign (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
			{
				size_type j = 0;
				difference_type n = std::distance(first, last);

				if (n > (difference_type)_capacity)
					reserve(n);
				for (InputIterator i = first; i != last ; ++i, ++j)
					_allocator.construct(&_array[j], *i);
				_size = n;
			}

			iterator insert (iterator position, const value_type& val)
			{
				difference_type iPosition = std::distance(begin(), position);
				if (_size + 1 > _capacity)
				{
					if (_capacity == 0)
						reserve(_size + 1);
					else
						reserve(_capacity * 2);
				}
				moveElements(iPosition, _size);
				_allocator.construct(&_array[iPosition], val);
				++_size;
				return (begin() + iPosition);
			}

			void insert (iterator position, size_type n, const value_type& val)
			{
				difference_type iPosition = std::distance(begin(), position);
				if (_size + n > _capacity)
				{
					size_type newcapacity = _capacity * 2;
					if (_size + n > newcapacity)
						reserve(_size + n);
					else
						reserve(_capacity * 2);
				}
				moveElements(iPosition , _size + n - 1);
				for (size_type i = 0; i < n; ++i)
				{
					_allocator.construct(&_array[iPosition], val);
					++iPosition;
				}
				_size += n;
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
			{
				difference_type n = std::distance(first, last);
				difference_type iPosition = std::distance(begin(), position);
				if (_size + n > _capacity)
				{
					size_type newcapacity = _capacity * 2;
					if (_size + n > newcapacity)
						reserve(_size + n);
					else
						reserve(_capacity * 2);
				}
				moveElements(iPosition, _size + n -1);
				for (InputIterator i = first; i != last ; ++i, ++iPosition)
					_allocator.construct(&_array[iPosition], *i);
				_size += n;
			}

			iterator erase (iterator position)
			{
				difference_type	iPosition = std::distance(begin(), position);
				eraseElements(_array, iPosition, _size - 1, 1);
				--_size;
				return (begin()+iPosition);
			}

			iterator erase (iterator first, iterator last)
			{
				difference_type n = std::distance(first, last);
				difference_type iPosition = first - begin();
				eraseElements(_array, iPosition, _size - n, n);
				_size -= n;
				return (begin()+iPosition);
			}

			void swap (vector& x)
			{
				pointer		temp_array    = x._array;
				size_type	temp_size  	  = x._size;
				size_type	temp_capacity = x._capacity;
				allocator_type	temp_allocator = x._allocator;
				
				x._array 	= _array;
				x._size 	= _size;
				x._capacity = _capacity;
				x._allocator = _allocator;

				_array		= temp_array;
				_size		= temp_size;
				_capacity	= temp_capacity;
				_allocator  = temp_allocator;
			}

			//title: Iterators
			iterator begin()
			{
				iterator iter(_array);
				return (iter);
			}
			const_iterator begin() const
			{
				const_iterator iter(_array);
				return (iter);
			}

			iterator end()
			{
				iterator iter(_array);
				return (iter + _size);
			}
			const_iterator end() const
			{
				const_iterator iter(_array);
				return (iter + _size);
			}

			reverse_iterator rbegin()
			{
				reverse_iterator riter(end());
				return (riter);
			}
			const_reverse_iterator rbegin() const
			{
				const_reverse_iterator riter(end());
				return (riter);
			}

			reverse_iterator rend()
			{
				reverse_iterator riter(begin());
				return (riter);
			}
			const_reverse_iterator rend() const
			{
				const_reverse_iterator riter(begin());
				return (riter);
			}

			//title: Element access
			
			reference operator[] (size_type n)
			{
				return _array[n];
			}

			const_reference operator[] (size_type n) const
			{
				return (_array[n]);
			}

			reference at (size_type n)
			{
				if (n > _size)
					throw std::out_of_range("OUT OF RANGE");
				return (_array[n]);
			}

			const_reference at (size_type n) const
			{
				if (n > _size)
					throw std::out_of_range("OUT OF RANGE");
				return (_array[n]);
			}

			reference front()
			{
				return (_array[0]);
			}

			const_reference front() const
			{
				return (_array[0]);
			}

			reference back()
			{
				return (_array[_size-1]);
			}

			const_reference back() const
			{
				return (_array[_size-1]);
			}

			allocator_type get_allocator() const
			{
				return(_allocator);
			}

			
			friend bool operator == (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
			{
				if (lhs.size() == rhs.size())
					return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
				return (false);
			}

			
			friend bool operator != (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
			{
				return (!(lhs == rhs));
			}

			
			friend bool operator < (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
			{
				return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
			}
			
			
			friend bool operator <= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
			{
				return (!(rhs < lhs));
			}

			
			friend bool operator > (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
			{
				return (rhs < lhs);
			}

			
			friend bool operator >= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
			{
				return (!(lhs < rhs));
			}

			
			friend void swap( ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs )
			{
				lhs.swap(rhs);
			}
	};


}//namespace ft end 

#endif