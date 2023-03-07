#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <cstddef>
#include <iterator>

namespace ft
{
	//title: ALGORITHMS

	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1!=last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1!=last1)
		{
			if (pred(*first1,*first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (!comp(*first1, *first2))
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	//title: ITERATOR

	//title: iterator base class 

	template <typename Category, typename T, typename Distance = std::ptrdiff_t,
							typename Pointer = T*, typename Reference = T& >
	class iterator
	{
		public:
			typedef	Category	iterator_category;
			typedef	T			value_type;
			typedef	Distance	difference_type;
			typedef	Pointer		pointer;
			typedef	Reference	reference;
	};

	//title: Iterator traits 

	template <typename Iterator>
	class iterator_traits 
	{
		public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};

	template< class T >
	struct iterator_traits<T*>
	{
		public:
			typedef std::random_access_iterator_tag iterator_category;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef std::ptrdiff_t					difference_type;
	};

	template< class T >
	struct iterator_traits<const T*>
	 {
		public:
			typedef std::random_access_iterator_tag iterator_category;
			typedef T								value_type;
			typedef const T*						pointer;
			typedef const T&						reference;
			typedef std::ptrdiff_t					difference_type;
	};

	//title: SFINAE

	template <bool Cond, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	template <class T, T v>
	struct integral_constant {
		static const T value = v;
		typedef T						value_type;
		typedef integral_constant<T,v>	type;
		operator T() { return v; }
	};

	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;

	template <typename T>
	struct is_integral : false_type {};

	
	template <>
	struct is_integral <bool> : true_type {};
	
	template <>
	struct is_integral <int> : true_type {};
	
	template <>
	struct is_integral <short int> : true_type {};
	
	template <>
	struct is_integral <long int> : true_type {};
	
	template <>
	struct is_integral <long long int> : true_type {};
	
	template <>
	struct is_integral <char> : true_type {};
	
	template <>
	struct is_integral <char16_t> : true_type {};
	
	template <>
	struct is_integral <char32_t> : true_type {};
	
	template <>
	struct is_integral <wchar_t> : true_type {};
	
	template <>
	struct is_integral <signed char> : true_type {};

	template <>
	struct is_integral <unsigned char> : true_type {};
	
	template <>
	struct is_integral <unsigned short int> : true_type {};
	
	template <>
	struct is_integral <unsigned int> : true_type {};
	
	template <>
	struct is_integral <unsigned long int> : true_type {};

	template <>
	struct is_integral <unsigned long long int> : true_type {};

}//namespace ft end 

#endif