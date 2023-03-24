/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:42:43 by heha              #+#    #+#             */
/*   Updated: 2023/03/24 21:45:44 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include "PmergeMe.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

PmergeMe::PmergeMe() throw()
{}

PmergeMe::PmergeMe(const PmergeMe& other) throw()
{
	(void)other;
}

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

void	PmergeMe::execute(const std::string& input)
{
	if (input.empty())
		throw std::runtime_error("Error: argument string is empty.");

	std::vector<int>	vector;
	std::list<int>		list;

	PmergeMe::_initSequence(vector, input);
	PmergeMe::_initSequence(list, input);

	std::cout << "Before:" << '\t';
	PmergeMe::_displaySequence(vector);

	double	sortingTime1 = PmergeMe::_sortSequence(vector);
	double	sortingTime2 = PmergeMe::_sortSequence(list);

	std::cout << "After:" << '\t';
	PmergeMe::_displaySequence(vector);

	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << sortingTime1 << " us" << std::endl;
	std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << sortingTime2 << " us" << std::endl;
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

PmergeMe&	PmergeMe::operator=(const PmergeMe& other) throw()
{
	(void)other;
	return (*this);
}

PmergeMe::~PmergeMe() throw()
{}

template <typename Container>
void	PmergeMe::_initSequence(Container& sequence, const std::string& input)
{
	std::istringstream	iss(input);
	int					n;

	while (iss >> n)
	{
		if (n <= 0)
			throw std::runtime_error("Error");
		sequence.push_back(n);
	}
	if (!iss.eof())
		throw std::runtime_error("Error");
}

template <typename Container>
void	PmergeMe::_displaySequence(const Container& sequence)
{
	for (typename Container::const_iterator it = sequence.begin(), ite = sequence.end(); it != ite; ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
}

template <typename Container>
double	PmergeMe::_sortSequence(Container& sequence)
{
	struct timespec	begin;
	clock_gettime(CLOCK_REALTIME, &begin);

	PmergeMe::_sortSequenceImpl(sequence);

	struct timespec	end;
	clock_gettime(CLOCK_REALTIME, &end);

	double	seconds = end.tv_sec - begin.tv_sec;
	double	nanoseconds = end.tv_nsec - begin.tv_nsec;
	return (seconds + nanoseconds * 1e-9 * 1000.0);
}

void	PmergeMe::_sortSequenceImpl(std::vector<int>& sequence)
{
	if (sequence.size() > 5)
	{
		std::vector<int>	v1(sequence.begin(), sequence.begin() + sequence.size() / 2);
		std::vector<int>	v2(sequence.begin() + sequence.size() / 2, sequence.end());

		//std::cout << "test<v1>: ";
		//PmergeMe::_displaySequence(v1);
		//std::cout << "test<v2>: ";
		//PmergeMe::_displaySequence(v2);
		//std::cout << "test<vector>: ";
		//PmergeMe::_displaySequence(sequence);

		std::sort(v1.begin(), v1.end());
		std::sort(v2.begin(), v2.end());

		sequence.clear();
		std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(sequence));
	}
	else
	{
		for (std::vector<int>::iterator it = sequence.begin(), ite = sequence.end(); it != ite; ++it)
			std::rotate(std::upper_bound(sequence.begin(), it, *it), it, it + 1);
	}
}

void	PmergeMe::_sortSequenceImpl(std::list<int>& sequence)
{
	if (sequence.size() > 5)
	{
		std::list<int>	lst1;
		std::list<int>	lst2;

		lst1.splice(lst1.begin(), sequence, sequence.begin(), std::next(sequence.begin(), sequence.size() / 2));
		lst2.splice(lst2.begin(), sequence, sequence.begin(), sequence.end());

		//std::cout << "test<lst1>: ";
		//PmergeMe::_displaySequence(lst1);
		//std::cout << "test<lst2>: ";
		//PmergeMe::_displaySequence(lst2);
		//std::cout << "test<list>: ";
		//PmergeMe::_displaySequence(sequence);

		lst1.sort();
		lst2.sort();

		sequence = lst1;
		sequence.merge(lst2);
	}
	else
	{
		for (std::list<int>::iterator it = sequence.begin(), ite = sequence.end(); it != ite; ++it)
			std::rotate(std::upper_bound(sequence.begin(), it, *it), it, std::next(it));
	}
}
