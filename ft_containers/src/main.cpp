/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:07:57 by heha              #+#    #+#             */
/*   Updated: 2023/02/24 16:26:47 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include <vector>
#include <map>
#include <utility>
#include <list>
#include <iterator.hpp>

class MyIterator : public ft::iterator<ft::input_iterator_tag, int> {

public:
	MyIterator(int* x) :p(x) {}
	MyIterator(const MyIterator& mit) : p(mit.p) {}
	MyIterator& operator++() {++p;return *this;}
	MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;}
	bool operator==(const MyIterator& rhs) const {return p==rhs.p;}
	bool operator!=(const MyIterator& rhs) const {return p!=rhs.p;}
	int& operator*() {return *p;}

private:
	int		*p;

};

int	main(void)
{
	{
		int			numbers[]={10,20,30,40,50};
		MyIterator	from(numbers);
		MyIterator	until(numbers+5);
		for (MyIterator it = from; it != until; it++)
			std::cout << *it << ' ';
		std::cout << '\n';
	}

	// ----

	{
		typedef ft::iterator_traits<int*>	traits;
		if (typeid(traits::iterator_category) == typeid(ft::random_access_iterator_tag))
			std::cout << "int* is a random-access iterator";
		std::cout << '\n';
	}
	
	// ----

	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;
		iter_type from (myvector.begin());
		iter_type until (myvector.end());
		ft::reverse_iterator<iter_type> rev_until (from);
		ft::reverse_iterator<iter_type> rev_from (until);

		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
	}

	// ----

	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;

		ft::reverse_iterator<iter_type> rev_end (myvector.begin());
		ft::reverse_iterator<iter_type> rev_begin (myvector.end());

		std::cout << "myvector:";
		for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	// ----
	
	{
		std::map<int,std::string> numbers;
		numbers.insert (std::make_pair(1,"one"));
		numbers.insert (std::make_pair(2,"two"));
		numbers.insert (std::make_pair(3,"three"));

		typedef std::map<int,std::string>::iterator map_iter;
		ft::reverse_iterator<map_iter> rev_end (numbers.begin());
		ft::reverse_iterator<map_iter> rev_iterator (numbers.end());

		for ( ; rev_iterator != rev_end ; ++rev_iterator )
			std::cout << rev_iterator->first << ' ' << rev_iterator->second << '\n';
	}

	// ----

	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;
		iter_type from (myvector.begin());
		iter_type until (myvector.end());
		ft::reverse_iterator<iter_type> rev_until (from);
		ft::reverse_iterator<iter_type> rev_from (until);

		std::cout << "myvector:";
		while (rev_from != rev_until) {
			std::cout << ' ' << *rev_from;
			++rev_from;
		}
		std::cout << '\n';
	}

	// ----

	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;

		ft::reverse_iterator<iter_type> rev_begin (myvector.end());
		ft::reverse_iterator<iter_type> rev_end (myvector.begin());

		ft::reverse_iterator<iter_type> rev_iterator = rev_begin;
		while ( rev_iterator != rev_end )
			std::cout << *rev_iterator++ << ' ';
		std::cout << '\n';

		while ( rev_iterator != rev_begin )
			std::cout << *(--rev_iterator) << ' ';
		std::cout << '\n';
	}

	// ----

	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;
		iter_type from (myvector.begin());
		iter_type until (myvector.end());
		ft::reverse_iterator<iter_type> rev_until (from);
		ft::reverse_iterator<iter_type> rev_from (until);

		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
	}

	// ----

	{
		std::list<int> mylist;
		for (int i=0; i<10; i++) mylist.push_back (i*10);

		std::list<int>::iterator it = mylist.begin();
		ft::advance (it,5);

		std::cout << "The sixth element in mylist is: " << *it << '\n';
	}

	// ----

	{
		std::list<int> mylist;
		for (int i=0; i<10; i++) mylist.push_back (i*10);

		std::list<int>::iterator first = mylist.begin();
		std::list<int>::iterator last = mylist.end();

		std::cout << "The distance is: " << ft::distance(first,last) << '\n';
	}

	return (0);
}
