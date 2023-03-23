/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:42:43 by heha              #+#    #+#             */
/*   Updated: 2023/03/23 16:40:58 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>
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
		throw std::logic_error("Error: argument string is empty.");

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
			throw std::logic_error("Error");
		sequence.push_back(n);
	}
	if (!iss.eof())
		throw std::logic_error("Error");
}

template <typename Container>
void	PmergeMe::_displaySequence(const Container& sequence)
{
	typedef typename Container::const_iterator	const_iterator;
	for (const_iterator it = sequence.begin(), ite = sequence.end(); it != ite; ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
}

template <typename Container>
double	PmergeMe::_sortSequence(Container& sequence)
{
	// TBD
	(void)sequence;
	return (0.0);
}
