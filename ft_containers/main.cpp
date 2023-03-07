# include <vector>
# include <sys/time.h>
# include <typeinfo>
# include <map>
# include <stack>
# include <iostream>
# include <list>
# include "vector/vector.hpp"
# include "stack/stack.hpp"
# include "map/map.hpp"

#define MY

# ifdef MY
	# define VECTOR_TYPE ft::vector
	# define IT_TRAITS ft::iterator_traits
	# define ENABLE_IF ft::enable_if
	# define IS_INTEGRAL ft::is_integral
	# define EQUAL ft::equal
	# define PAIR ft::Pair
	# define MAKE_PAIR ft::make_pair
	# define REVERSE_IT ft::reverse_iterator
	# define MAP_TYPE ft::map
	# define STACK_TYPE ft::stack
# else
	# define VECTOR_TYPE std::vector
	# define IT_TRAITS std::iterator_traits
	# define ENABLE_IF std::enable_if
	# define IS_INTEGRAL std::is_integral
	# define EQUAL std::equal
	# define PAIR std::pair
	# define MAKE_PAIR std::make_pair
	# define REVERSE_IT std::reverse_iterator
	# define MAP_TYPE std::map
	# define STACK_TYPE std::stack
# endif

template <typename T>
void	printVector(VECTOR_TYPE<T> const &vct)
{
	const typename VECTOR_TYPE<T>::size_type size = vct.size();
	const typename VECTOR_TYPE<T>::size_type capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	typename VECTOR_TYPE<T>::const_iterator it = vct.begin();
	typename VECTOR_TYPE<T>::const_iterator ite = vct.end();
	std::cout << std::endl << "Content is:" << std::endl;
	for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
}

void test_vector_contractor()
{
	VECTOR_TYPE<int> first;
	VECTOR_TYPE<int> second (4,100);
	VECTOR_TYPE<int> third (second.begin(),second.end());
	VECTOR_TYPE<int> fourth (third);
	int myints[] = {16,2,77,29};
	VECTOR_TYPE<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	std::cout << "The contents of fifth are:";
	for (VECTOR_TYPE<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void test_vector_equal_operator()
{
	VECTOR_TYPE<int> foo (3,0);
	VECTOR_TYPE<int> bar (5,0);
	bar = foo;
	foo = VECTOR_TYPE<int>();
	std::cout << "Size of foo: " << int(foo.size()) << '\n';
	std::cout << "Size of bar: " << int(bar.size()) << '\n';
}

void test_vector_begin_end_it()
{
	VECTOR_TYPE<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);
	std::cout << "myvector contains:";
	for (VECTOR_TYPE<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void test_vector_rbegin_rend_it()
{
	VECTOR_TYPE<int> myvector (5);
	int i=0;
	VECTOR_TYPE<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;
	std::cout << "myvector contains:";
	for (VECTOR_TYPE<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void test_vector_size()
{
	VECTOR_TYPE<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';
	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';
	myints.insert (myints.end(),10,100);
	std::cout << "2. size: " << myints.size() << '\n';
	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';
}

void test_vector_maxsize()
{
	VECTOR_TYPE<int> myvector;
	for (int i=0; i<100; i++) myvector.push_back(i);
	std::cout << "size: " << myvector.size() << "\n";
	std::cout << "capacity: " << myvector.capacity() << "\n";
	std::cout << "max_size: " << myvector.max_size() << "\n";
}

void test_vector_resize()
{
	VECTOR_TYPE<int> myvector;
	for (int i=1;i<10;i++) myvector.push_back(i);
	myvector.resize(5);
	myvector.resize(8,100);
	myvector.resize(12);
	std::cout << "myvector contains:";
	for (size_t i=0;i < myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void test_vector_capacity()
{
	VECTOR_TYPE<int> myvector;
	for (int i=0; i<100; i++) myvector.push_back(i);
	std::cout << "size: " << (int) myvector.size() << '\n';
	std::cout << "capacity: " << (int) myvector.capacity() << '\n';
	std::cout << "max_size: " << (int) myvector.max_size() << '\n';
}

void test_vector_empty()
{
	VECTOR_TYPE<int> myvector;
	int sum (0);
	for (int i=1;i<=10;i++) myvector.push_back(i);
	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}
	std::cout << "total: " << sum << '\n';
}

void test_vector_reserve()
{
	VECTOR_TYPE<int>::size_type sz;
	VECTOR_TYPE<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i)
	{
		foo.push_back(i);
		if (sz!=foo.capacity()) {
		sz = foo.capacity();
		std::cout << "capacity changed: " << sz << '\n';
		}
	}
	VECTOR_TYPE<int> bar;
	sz = bar.capacity();
	bar.reserve(100);
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
		sz = bar.capacity();
		std::cout << "capacity changed: " << sz << '\n';
		}
	}
}

void test_vector_square_brackets_operator()
{
	VECTOR_TYPE<int> myvector (10);
	VECTOR_TYPE<int>::size_type sz = myvector.size();
	for (unsigned i=0; i<sz; i++) myvector[i]=i;
	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = myvector[sz-1-i];
		myvector[sz-1-i]=myvector[i];
		myvector[i]=temp;
	}
	std::cout << "myvector contains:";
	for (unsigned i=0; i<sz; i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void test_vector_at() 
{
	{
		VECTOR_TYPE<int> myvector (10);
		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i;
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector.at(i);
	}
	{
		VECTOR_TYPE<int> vct(7);
		for (unsigned long int i = 0; i < vct.size(); ++i)
		{
			vct.at(i) = (vct.size() - i) * 3;
			std::cout << "vct.at(): " << vct.at(i) << " | ";
			std::cout << "vct[]: " << vct[i] << std::endl;
		}
		printVector(vct);
		VECTOR_TYPE<int> const vct_c(vct);
		std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
		std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

		try {
			vct.at(10) = 42;
		}
		catch (std::out_of_range &e) {
			std::cout << "Catch out_of_range exception!" << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Catch exception: " << e.what() << std::endl;
		}
	}
	{
		VECTOR_TYPE<int> vct(7);
		for (unsigned long int i = 0; i < vct.size(); ++i)
		{
			vct.at(i) = (vct.size() - i) * 3;
			std::cout << "vct[]: " << vct[i] << std::endl;
		}
		printVector(vct);
		VECTOR_TYPE<int> const vct_c(vct);
		std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
		std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;
		for (unsigned long int i = 0; i < vct_c.size(); ++i)
			std::cout << "vct_c.at(): " << vct_c.at(i) << std::endl;
		try {
			std::cout << vct_c.at(10) << std::endl;
		}
		catch (std::out_of_range &e) {
			std::cout << "Catch out_of_range exception!" << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Catch exception: " << e.what() << std::endl;
		}
		printVector(vct_c);
		std::cout << '\n';
	}
}

void test_vector_front()
{
	VECTOR_TYPE<int> myvector;
	myvector.push_back(78);
	myvector.push_back(16);
	myvector.front() -= myvector.back();
	std::cout << "myvector.front() is now " << myvector.front() << '\n';
}

void test_vector_back()
{
	VECTOR_TYPE<int> myvector;
	myvector.push_back(10);
	while (myvector.back() != 0)
	{
		myvector.push_back ( myvector.back() -1 );
	}
	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size() ; i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void test_vector_assign() 
{
	{
		VECTOR_TYPE<int> first;
		VECTOR_TYPE<int> second;
		VECTOR_TYPE<int> third;
		first.assign (7,100);
		VECTOR_TYPE<int>::iterator it;
		it=first.begin()+1;
		second.assign (it,first.end()-1);
		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);
		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
		std::cout << "Size of third: " << int (third.size()) << '\n';
	}
	{
		VECTOR_TYPE<int> vct(7);
		VECTOR_TYPE<int> vct_two(4);
		VECTOR_TYPE<int> vct_three;
		VECTOR_TYPE<int> vct_four;

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 3;
		for (unsigned long int i = 0; i < vct_two.size(); ++i)
			vct_two[i] = (vct_two.size() - i) * 5;
		printVector(vct);
		printVector(vct_two);
		vct_three.assign(vct.begin(), vct.end());
		vct.assign(vct_two.begin(), vct_two.end());
		vct_two.assign(2, 42);
		vct_four.assign(4, 21);
		std::cout << "\t### After assign(): ###" << std::endl;
		printVector(vct);
		printVector(vct_two);
		printVector(vct_three);
		printVector(vct_four);
		vct_four.assign(6, 84);
		printVector(vct_four);
		std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;
		vct.assign(5, 53);
		vct_two.assign(vct_three.begin(), vct_three.begin() + 3);
		printVector(vct);
		printVector(vct_two);
	}
}

void test_vector_push_back() {
	VECTOR_TYPE<int> myvector;

	for (int i = 1;i < 50;++i) {
		myvector.push_back (i);
	}

	std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
}

void test_vector_pop_back() {
	VECTOR_TYPE<int> myvector;
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	while (!myvector.empty())
	{
		sum+=myvector.back();
		myvector.pop_back();
	}

	std::cout << "The elements of myvector add up to " << sum << '\n';
}

void test_vector_insert() 
{
	{
		VECTOR_TYPE<int> myvector (3,100);
		VECTOR_TYPE<int>::iterator it;
		it = myvector.begin();
		it = myvector.insert ( it , 200 );
		myvector.insert (it,2,300);
		it = myvector.begin();
		VECTOR_TYPE<int> anothervector (2,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());
		int myarray [] = { 501,502,503 };
		myvector.insert (myvector.begin(), myarray, myarray+3);
		std::cout << "myvector contains:";
		for (it=myvector.begin(); it<myvector.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		std::list<int> lst;
		std::list<int>::iterator lst_it;
		for (int i = 1; i < 5; ++i)
			lst.push_back(i * 3);

		VECTOR_TYPE<int> vct(lst.begin(), lst.end());
		printVector(vct);

		lst_it = lst.begin();
		for (int i = 1; lst_it != lst.end(); ++i)
			*lst_it++ = i * 5;
		vct.assign(lst.begin(), lst.end());
		printVector(vct);

		vct.insert(vct.end(), lst.rbegin(), lst.rend());
		printVector(vct);
	}
}

void test_vector_erase()
{
	VECTOR_TYPE<int> myvector;
	for (int i=1; i<=10; i++) myvector.push_back(i);
	myvector.erase (myvector.begin()+5);
	myvector.erase (myvector.begin(),myvector.begin()+3);
	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void test_vector_swap() {
	VECTOR_TYPE<int> foo (3,100);   // three ints with a value of 100
	VECTOR_TYPE<int> bar (5,200);   // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << '\n';

}

void test_vector_clear() {
	VECTOR_TYPE<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void test_vector_get_allocator() {
	VECTOR_TYPE<int> myvector;
	int * p;
	unsigned int i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';

	// destroy and deallocate:
	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p,5);
}

void test_vector_relation_operators() {
	VECTOR_TYPE<int> foo (3,100);   // three ints with a value of 100
	VECTOR_TYPE<int> bar (2,200);   // two ints with a value of 200

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}

void test_vector() {
	struct timeval start, end;
	gettimeofday(&start, NULL);
	test_vector_contractor();
	test_vector_equal_operator();
	test_vector_begin_end_it();
	test_vector_rbegin_rend_it();
	test_vector_size();
	test_vector_maxsize();
	test_vector_resize();
	test_vector_capacity();
	test_vector_empty();
	test_vector_reserve();
	test_vector_square_brackets_operator();
	test_vector_at();
	test_vector_front();
	test_vector_back();
	test_vector_assign();
	test_vector_push_back();
	test_vector_pop_back();
	test_vector_insert();
	test_vector_erase();
	test_vector_swap();
	test_vector_clear();
	test_vector_get_allocator();
	test_vector_relation_operators();
	gettimeofday(&end, NULL);
	std::cout << "Time to execute in Milleseconds : " << ((end.tv_sec * 1e3) + (end.tv_usec / 1e3)) - ((start.tv_sec * 1e3) + (start.tv_usec / 1e3)) << std::endl;
}

void test_iterators_traits() {
	typedef IT_TRAITS<int*> traits;
	if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
		std::cout << "int* is a random-access iterator";
}

template <class T>
void fun(T a, typename ENABLE_IF<IS_INTEGRAL<T>::value, T>::type = T()) {
	(void)a;
	std::cout << "fun with int param" << std::endl;
}

void test_enable_if() {
	fun(120);
}

bool mypredicate (int i, int j) {
  return (i==j);
}

void test_equal() {
	int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
	VECTOR_TYPE<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100

	// using default comparison:
	if ( EQUAL (myvector.begin(), myvector.end(), myints) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";

	myvector[3]=81;                                 // myvector: 20 40 60 81 100

	// using predicate comparison:
	if ( EQUAL (myvector.begin(), myvector.end(), myints, mypredicate) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";
}

bool mycomp (char c1, char c2) { return std::tolower(c1)<std::tolower(c2); }

void test_lexicographical_compare() {
	char foo[]="Apple";
	char bar[]="apartment";

	std::cout << std::boolalpha;

	std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

	std::cout << "Using default comparison (operator<): ";
	std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9);
	std::cout << '\n';

	std::cout << "Using mycomp as comparison object: ";
	std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
	std::cout << '\n';
}

void test_make_pair() {
	PAIR <int,int> foo;
	PAIR <int,int> bar;

	foo = MAKE_PAIR (10,20);
	bar = MAKE_PAIR (10.5,'A'); // ok: implicit conversion from pair<double,char>

	std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
	std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
}

void test_reverse_it_constractor() {
	VECTOR_TYPE<int> myvector;
	for (int i=0; i<10; i++) myvector.push_back(i);

	typedef VECTOR_TYPE<int>::iterator iter_type;
															// ? 0 1 2 3 4 5 6 7 8 9 ?
	iter_type from (myvector.begin());                     //   ^
															//         ------>
	iter_type until (myvector.end());                      //                       ^
															//
	REVERSE_IT<iter_type> rev_until (from);     // ^
															//         <------
	REVERSE_IT<iter_type> rev_from (until);     //                     ^

	std::cout << "myvector:";
	while (rev_from != rev_until)
		std::cout << ' ' << *rev_from++;
	std::cout << '\n';
}

void test_revser_it_base() {
	VECTOR_TYPE<int> myvector;
	for (int i=0; i<10; i++) myvector.push_back(i);

	typedef VECTOR_TYPE<int>::iterator iter_type;

	REVERSE_IT<iter_type> rev_end (myvector.begin());
	REVERSE_IT<iter_type> rev_begin (myvector.end());

	std::cout << "myvector:";
	for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void test_reverse_it_star_operator() {
	VECTOR_TYPE<int> myvector;
	for (int i=0; i<10; i++) myvector.push_back(i);

	typedef VECTOR_TYPE<int>::iterator iter_type;
															// ? 9 8 7 6 5 4 3 2 1 0 ?
	iter_type from (myvector.begin());                     //   ^
															//         ------>
	iter_type until (myvector.end());                      //                       ^
															//
	REVERSE_IT<iter_type> rev_until (from);     // ^
															//         <------
	REVERSE_IT<iter_type> rev_from (until);     //                     ^

	std::cout << "myvector:";
	while (rev_from != rev_until)
		std::cout << ' ' << *rev_from++;
	std::cout << '\n';
}

void test_reverse_it_plus_operator() {
	VECTOR_TYPE<int> myvector;
	for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

	typedef VECTOR_TYPE<int>::iterator iter_type;

	REVERSE_IT<iter_type> rev_it;

	rev_it = myvector.rbegin() +3;

	std::cout << "The fourth element from the end is: " << *rev_it << '\n';
}

void test_reverse_it_incementation_operator() {
	VECTOR_TYPE<int> myvector;
	for (int i=0; i<10; i++) myvector.push_back(i);

	typedef VECTOR_TYPE<int>::iterator iter_type;
															// ? 9 8 7 6 5 4 3 2 1 0 ?
	iter_type from (myvector.begin());                     //   ^
															//         ------>
	iter_type until (myvector.end());                      //                       ^
															//
	REVERSE_IT<iter_type> rev_until (from);     // ^
															//         <------
	REVERSE_IT<iter_type> rev_from (until);     //                     ^

	std::cout << "myvector:";
	while (rev_from != rev_until) {
		std::cout << ' ' << *rev_from;
		++rev_from;
	}
	std::cout << '\n';
}

void test_reverse_it_plus_equal_operator() {
	VECTOR_TYPE<int> myvector;
	for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

	typedef VECTOR_TYPE<int>::iterator iter_type;

	REVERSE_IT<iter_type> rev_iterator = myvector.rbegin();

	rev_iterator += 2;

	std::cout << "The third element from the end is: " << *rev_iterator << '\n';
}

void test_reverse_it_minus_operator() {
	VECTOR_TYPE<int> myvector;
	for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

	typedef VECTOR_TYPE<int>::iterator iter_type;

	REVERSE_IT<iter_type> rev_iterator;

	rev_iterator = myvector.rend() - 3;

	std::cout << "myvector.rend()-3 points to: " << *rev_iterator << '\n';
}

void test_reverse_it_deceremntation_operator() {
	VECTOR_TYPE<int> myvector;
	for (int i=0; i<10; i++) myvector.push_back(i);

	typedef VECTOR_TYPE<int>::iterator iter_type;

	REVERSE_IT<iter_type> rev_begin (myvector.end());
	REVERSE_IT<iter_type> rev_end (myvector.begin());

	REVERSE_IT<iter_type> rev_iterator = rev_begin;
	while ( rev_iterator != rev_end )
		std::cout << *rev_iterator++ << ' ';
	std::cout << '\n';

	while ( rev_iterator != rev_begin )
		std::cout << *(--rev_iterator) << ' ';
	std::cout << '\n';
}

void test_reverse_it_minus_equal_operator() {
	VECTOR_TYPE<int> myvector;
	for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

	typedef VECTOR_TYPE<int>::iterator iter_type;

	REVERSE_IT<iter_type> rev_iterator = myvector.rend();

	rev_iterator -= 4;

	std::cout << "rev_iterator now points to: " << *rev_iterator << '\n';
}

void test_reverse_it_dereference_operator() {
	MAP_TYPE<int,std::string> numbers;
	numbers.insert (MAKE_PAIR(1,"one"));
	numbers.insert (MAKE_PAIR(2,"two"));
	numbers.insert (MAKE_PAIR(3,"three"));

	typedef MAP_TYPE<int,std::string>::iterator map_iter;

	REVERSE_IT<map_iter> rev_end (numbers.begin());

	REVERSE_IT<map_iter> rev_iterator (numbers.end());

	for ( ; rev_iterator != rev_end ; ++rev_iterator )
		std::cout << rev_iterator->first << ' ' << rev_iterator->second << '\n';
}

void test_reverse_it_square_brackets_operator() {
	VECTOR_TYPE<int> myvector;
	for (int i=0; i<10; i++) myvector.push_back(i);  // myvector: 0 1 2 3 4 5 6 7 8 9

	typedef VECTOR_TYPE<int>::iterator iter_type;

	REVERSE_IT<iter_type> rev_iterator = myvector.rbegin();

	std::cout << "The fourth element from the end is: " << rev_iterator[3] << '\n';
}

void test_reverse_it_relational_operators() {
	VECTOR_TYPE<int> myvector;
	for (int i=0; i<10; i++) myvector.push_back(i);

	typedef VECTOR_TYPE<int>::iterator iter_type;
															// ? 9 8 7 6 5 4 3 2 1 0 ?
	iter_type from (myvector.begin());                     //   ^
															//         ------>
	iter_type until (myvector.end());                      //                       ^
															//
	REVERSE_IT<iter_type> rev_until (from);     // ^
															//         <------
	REVERSE_IT<iter_type> rev_from (until);     //                     ^

	std::cout << "myvector:";
	while (rev_from != rev_until)
		std::cout << ' ' << *rev_from++;
	std::cout << '\n';
}

void test_reverse_it_Addition_operator() {
	VECTOR_TYPE<int> myvector;
	for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

	typedef VECTOR_TYPE<int>::iterator iter_type;

	REVERSE_IT<iter_type> rev_it;

	rev_it = 3 + myvector.rbegin();

	std::cout << "The fourth element from the end is: " << *rev_it << '\n';
}

void test_reverse_it_subtraction_operator() {
	VECTOR_TYPE<int> myvector;
	for (int i=0; i<10; i++) myvector.push_back(i);

	REVERSE_IT<VECTOR_TYPE<int>::iterator> from,until;

	from = myvector.rbegin();
	until = myvector.rend();

	std::cout << "myvector has " << (until-from) << " elements.\n";
}

void test_reverse_it() {
	test_reverse_it_constractor();
	test_revser_it_base();
	test_reverse_it_star_operator();
	test_reverse_it_plus_operator();
	test_reverse_it_incementation_operator();
	test_reverse_it_plus_equal_operator();
	test_reverse_it_minus_operator();
	test_reverse_it_deceremntation_operator();
	test_reverse_it_minus_equal_operator();
	test_reverse_it_dereference_operator();
	test_reverse_it_square_brackets_operator();
	test_reverse_it_relational_operators();
	test_reverse_it_Addition_operator();
	test_reverse_it_subtraction_operator();
}

void test_pair_construct() {
	PAIR <std::string,double> product1;                     // default constructor
	PAIR <std::string,double> product2 ("tomatoes",2.30);   // value init
	PAIR <std::string,double> product3 (product2);          // copy constructor

	product1 = MAKE_PAIR(std::string("lightbulbs"),0.99);   // using make_pair (move)

	product2.first = "shoes";                  // the type of first is string
	product2.second = 39.90;                   // the type of second is double

	std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
	std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
	std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
}

void test_pair_equal_operator() {
	PAIR <std::string,int> planet, homeplanet;

	planet = MAKE_PAIR("Earth",6371);

	homeplanet = planet;

	std::cout << "Home planet: " << homeplanet.first << '\n';
	std::cout << "Planet size: " << homeplanet.second << '\n';
}

void test_pair_relational_operators() {
	PAIR<int,char> foo (10,'z');
	PAIR<int,char> bar (90,'a');

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}

void test_pair() {
	test_pair_construct();
	test_pair_equal_operator();
	test_pair_relational_operators();
}

bool fncomp (char lhs, char rhs) {return (lhs < rhs);}

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const { return lhs<rhs; }
};


void test_map_construct() {
	MAP_TYPE<char,int> first;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;

	MAP_TYPE<char,int> second (first.begin(),first.end());

	MAP_TYPE<char,int> third (second);

	MAP_TYPE<char,int,classcomp> fourth;                 // class as Compare

	bool(*fn_pt)(char,char) = fncomp;
	MAP_TYPE<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
}

void test_map_copy_container_content() {
	MAP_TYPE<char,int> first;
	MAP_TYPE<char,int> second;

	first['x']=8;
	first['y']=16;
	first['z']=32;

	second=first;                // second now contains 3 ints
	first=MAP_TYPE<char,int>();  // and first is now empty

	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << second.size() << '\n';
}

void test_map_begin_end() {
	MAP_TYPE<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	// show content:
	for (MAP_TYPE<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void test_map_rbegin_rend() {
	MAP_TYPE<char,int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	// show content:
	MAP_TYPE<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';
}

void test_map_empty() {
	MAP_TYPE<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	while (!mymap.empty())
	{
		std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
	}
}

void test_map_size() {
	MAP_TYPE<char,int> mymap;
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;

	std::cout << "mymap.size() is " << mymap.size() << '\n';
}

void test_map_max_size() {
	int i;
	MAP_TYPE<int,int> mymap;

	if (mymap.max_size()>1000)
	{
		for (i=0; i<1000; i++) mymap[i]=0;
		std::cout << "The map contains 1000 elements.\n";
	}
	else std::cout << "The map could not hold 1000 elements.\n";
}

void test_map_square_brackets_operator() {
	MAP_TYPE<char,std::string> mymap;

	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	std::cout << "mymap now contains " << mymap.size() << " elements.\n";
}

void test_map_insert() {
	MAP_TYPE<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert ( PAIR<char,int>('a',100) );
	mymap.insert ( PAIR<char,int>('z',200) );

	PAIR<MAP_TYPE<char,int>::iterator,bool> ret;
	ret = mymap.insert ( PAIR<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	MAP_TYPE<char,int>::iterator it = mymap.begin();
	mymap.insert (it, PAIR<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, PAIR<char,int>('c',400));  // no max efficiency inserting

	// third insert function version (range insertion):
	MAP_TYPE<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

	// showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void test_map_erase() {
	MAP_TYPE<char,int> mymap;
	MAP_TYPE<char,int>::iterator it;

	// insert some values:
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator

	mymap.erase ('c');                  // erasing by key

	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range

	// show content:
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void test_map_swap() {
	MAP_TYPE<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	foo.swap(bar);

	std::cout << "foo contains:\n";
	for (MAP_TYPE<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (MAP_TYPE<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void test_map_clear() {
	MAP_TYPE<char,int> mymap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;

	std::cout << "mymap contains:\n";
	for (MAP_TYPE<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.clear();
	mymap['a']=1101;
	mymap['b']=2202;

	std::cout << "mymap contains:\n";
	for (MAP_TYPE<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void test_map_key_comp() {
	MAP_TYPE<char,int> mymap;

	MAP_TYPE<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	MAP_TYPE<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	std::cout << '\n';
}

void test_map_value_comp() {
	MAP_TYPE<char,int> mymap;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;

	std::cout << "mymap contains:\n";

	PAIR<char,int> highest = *mymap.rbegin();          // last element

	MAP_TYPE<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );
}

void test_map_find() {
	MAP_TYPE<char,int> mymap;
	MAP_TYPE<char,int>::iterator it;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase (it);

	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';
}

void test_map_count() {
	MAP_TYPE<char,int> mymap;
	char c;

	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;

	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c)>0)
		std::cout << " is an element of mymap.\n";
		else 
		std::cout << " is not an element of mymap.\n";
	}
}

void test_map_lower_bound() {
	MAP_TYPE<char,int> mymap;
	MAP_TYPE<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (MAP_TYPE<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void test_map_upper_bound() {
	MAP_TYPE<char,int> mymap;
	MAP_TYPE<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (MAP_TYPE<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void test_map_equal_range() {
	MAP_TYPE<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	PAIR<MAP_TYPE<char,int>::iterator,MAP_TYPE<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
}

void test_map_get_allocator() {
	int psize;
	MAP_TYPE<char,int> mymap;
	PAIR<const char,int>* p;

	// allocate an array of 5 elements using mymap's allocator:
	p=mymap.get_allocator().allocate(5);

	// assign some values to array
	psize = sizeof(MAP_TYPE<char,int>::value_type)*5;

	std::cout << "The allocated array has a size of " << psize << " bytes.\n";

	mymap.get_allocator().deallocate(p,5);
}

void test_map() {
	struct timeval start, end;
	gettimeofday(&start, NULL);
	test_map_construct();
	test_map_copy_container_content();
	test_map_begin_end();
	test_map_rbegin_rend();
	test_map_empty();
	test_map_size();
	test_map_max_size();
	test_map_square_brackets_operator();
	test_map_insert();
	test_map_erase();
	test_map_swap();
	test_map_clear();
	test_map_key_comp();
	test_map_value_comp();
	test_map_find();
	test_map_count();
	test_map_lower_bound();
	test_map_upper_bound();
	test_map_equal_range();
	test_map_get_allocator();
	gettimeofday(&end, NULL);
	std::cout << "Time to execute in Milleseconds : " << ((end.tv_sec * 1e3) + (end.tv_usec / 1e3)) - ((start.tv_sec * 1e3) + (start.tv_usec / 1e3)) << std::endl;
}

void test_stack_construct() {
	VECTOR_TYPE<int> myvector (2,200);        // vector with 2 elements
	
	STACK_TYPE<int, VECTOR_TYPE<int> > third;  // empty stack using vector
	STACK_TYPE<int, VECTOR_TYPE<int> > fourth (myvector);
	
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';
}

void test_stack_empty() {
	STACK_TYPE<int> mystack;
	int sum (0);

	for (int i=1;i<=10;i++) mystack.push(i);

	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}

	std::cout << "total: " << sum << '\n';
}

void test_stack_size() {
	STACK_TYPE<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';
}

void test_stack_top() {
	STACK_TYPE<int> mystack;

	mystack.push(10);
	mystack.push(20);

	mystack.top() -= 5;

	std::cout << "mystack.top() is now " << mystack.top() << '\n';
}

void test_stack_push() {
	STACK_TYPE<int> mystack;

	for (int i=0; i<5; ++i) mystack.push(i);

	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << '\n';
}

void test_stack_pop() {
	STACK_TYPE<int> mystack;

	for (int i=0; i<5; ++i) mystack.push(i);

	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << '\n';
}

void test_stack_relation_operator() {
	VECTOR_TYPE<int>	vec(100, 2);
	VECTOR_TYPE<int>	vec1(100, 2);

	std::cout << std::boolalpha;
	{
		STACK_TYPE<int, VECTOR_TYPE<int> > stack1(vec);
		STACK_TYPE<int, VECTOR_TYPE<int> > stack(vec1);
		std::cout << (stack == stack1) << std::endl;
	}
	{
		vec.push_back(300);
		STACK_TYPE<int, VECTOR_TYPE<int> > stack1(vec);
		STACK_TYPE<int, VECTOR_TYPE<int> > stack(vec1);
		std::cout << (stack == stack1) << std::endl;
	}
	{
		vec.pop_back();
		vec1.push_back(300);
		STACK_TYPE<int, VECTOR_TYPE<int> > stack1(vec);
		STACK_TYPE<int, VECTOR_TYPE<int> > stack(vec1);
		std::cout << (stack == stack1) << std::endl;
	}
}

void test_stack() {
	struct timeval start, end;
	gettimeofday(&start, NULL);
	test_stack_construct();
	test_stack_empty();
	test_stack_size();
	test_stack_top();
	test_stack_push();
	test_stack_pop();
	test_stack_relation_operator();
	gettimeofday(&end, NULL);
	std::cout << "Time to execute in Milleseconds : " << ((end.tv_sec * 1e3) + (end.tv_usec / 1e3)) - ((start.tv_sec * 1e3) + (start.tv_usec / 1e3)) << std::endl;
}

int main()
{
	test_iterators_traits(); 
	test_enable_if();
	test_equal();
	test_lexicographical_compare();
	test_make_pair();
	test_reverse_it();
	test_pair();
	test_vector();
	test_stack();
	test_map();
	// system("leaks containers.out");
	return (0);
}