#ifndef PAIR_HPP
#define PAIR_HPP

//title: pair (KEY, VALUE) 
namespace ft
{
	template <typename T1,typename T2>
	class Pair
	{
		public:
			typedef T1 first_type;
			typedef T2 second_type;
		public:
			first_type first;
			second_type second;
		public:
			Pair() : first(first_type()), second(second_type()) {}
			Pair (const first_type& a, const second_type& b) :  first(a), second(b){}
			template<class U, class V>
			Pair (const Pair<U,V> &pr) : first(pr.first), second(pr.second) {}
			Pair& operator= (const Pair& pr)
			{
				first = pr.first;
				second = pr.second;
				return (*this);
			}
			~Pair() {}
	};

	template <typename T1, typename T2>
	bool operator == (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <typename T1, typename T2>
	bool operator != (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T1, typename T2>
	bool operator <  (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <typename T1, typename T2>
	bool operator <= (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <typename T1, typename T2>
	bool operator >  (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
	{
		return (rhs < lhs);
	}

	template <typename T1, typename T2>
	bool operator >= (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
	{
		return (!(lhs < rhs));
	}

	template <typename T1,typename T2>
	Pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return ( Pair<T1,T2>(x,y) );
	}
}//namespace ft end 

#endif