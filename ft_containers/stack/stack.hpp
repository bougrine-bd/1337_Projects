#ifndef STACK_HPP
#define STACK_HPP

#include "../vector/vector.hpp"
#include <vector>

namespace ft 
{
	template <typename T, typename Container = ft::vector<T> > 
	class stack
	{
		public:
			typedef typename Container::value_type value_type;
			typedef	Container container_type;
			typedef typename Container::size_type size_type;

		protected:
			Container c;

		public:
			explicit stack (const container_type &ctnr = container_type())
			{
				c = ctnr;
			}
			stack (const stack &obj)
			{
				*this = obj;
			}
			stack &operator = (const stack &obj)
			{
				if (this != &obj)
					c = obj.c;
				return (*this);
			}
			~stack() {}

			bool empty() const
			{
				return (c.empty());
			}

			size_type size() const
			{
				return (c.size());
			}

			value_type& top()
			{
				return (c[c.size() - 1]);
			}
			const value_type& top() const
			{
				return (c[c.size() - 1]);
			}

			void push (const value_type& val)
			{
				c.push_back(val);
			}
			void pop()
			{
				c.pop_back();
			}

			friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs.c == rhs.c);
			}
			friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs.c != rhs.c);
			}
			friend bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs.c < rhs.c);
			}
			friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs.c <= rhs.c);
			}
			friend bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs.c > rhs.c);
			}
			friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs.c >= rhs.c);
			}
	};
}//namespace ft end 

#endif