#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "../utilities/utilities.hpp"

namespace ft
{
	template <typename Iterator>
	class reverse_iterator{
		public:
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		private:
			iterator_type	_current;
		public:
			reverse_iterator() : _current(){}
			explicit reverse_iterator (iterator_type it) : _current(it){}
			template <class Iter>
  			reverse_iterator (const reverse_iterator<Iter>& rev_it)
			{
				_current = rev_it.base();
			}	
			
			iterator_type base() const{
				return _current;
			}
			reference operator * () const{
				iterator_type temp = _current;
				return (*(--temp));
			}
			pointer operator->() const {
				return (&operator*());
			}
			reverse_iterator operator + (difference_type n) const
			{
				reverse_iterator temp = *this;
				return	(reverse_iterator(temp._current - n));
			}
			reverse_iterator operator - (difference_type n) const
			{
				reverse_iterator temp = *this;
				return	(reverse_iterator(temp._current + n));
			}
			reverse_iterator &operator ++ ()
			{
				--_current;
				return (*this);
			}
			reverse_iterator  operator ++ (int)
			{
				reverse_iterator temp = *this;
				--_current;
				return (temp);
			}
			reverse_iterator &operator -- (){
				++_current;
				return (*this);
			}
			reverse_iterator  operator -- (int){
				reverse_iterator temp = *this;
				++_current;
				return (temp);
			}
			reverse_iterator &operator+=(difference_type n)
			{
				_current -= n;
				return	(*this);
			}
			reverse_iterator &operator -= (difference_type n)
			{
				_current += n;
				return	(*this);
			}
			reference operator [] (difference_type n)
			{
				return (_current[-n-1]);
			}

			
			friend bool operator == (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
				return (lhs.base() == rhs.base());
			}
			
			friend bool operator != (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
				return (lhs.base() != rhs.base());
			}
			
			friend bool operator < (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
				return (lhs.base() > rhs.base());
			}
			
			friend bool operator <= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
				return (lhs.base() >= rhs.base());
			}
			
			friend bool operator > (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
				return (lhs.base() < rhs.base());
			}
			
			friend bool operator >= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
				return (lhs.base() <= rhs.base());
			}
			
			friend reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n,
													const reverse_iterator<Iterator>& rev_it){
				return	(reverse_iterator<Iterator>(rev_it.base() - n));
			}
			
			friend typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, 
																	const reverse_iterator<Iterator>& rhs){
				return (rhs.base() - lhs.base());
			}
	};

}//namespace ft end 

#endif