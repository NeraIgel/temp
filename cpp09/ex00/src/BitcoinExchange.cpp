/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:06:53 by heha              #+#    #+#             */
/*   Updated: 2023/03/20 19:14:54 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

BitcoinExchange::BitcoinExchange() throw()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) throw()
{
	(void)other;
}

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

void	BitcoinExchange::execute(const std::string& datafile, const std::string& inputfile)
{
	(void)datafile;
	(void)inputfile;

	// data file open -> read -> vector push_back() -> close (if file open is fails, throw exception)
	// input file open -> read -> vector push_back() -> close (if file open is fails, throw exception)
	
	// input vector front check
	//	a. format check (e.g. "date | value")
	// 	b. date item check (e.g. "Year-Month-Day")
	// 	c. value item check (e.g. float or positive integer between 0 and 1000)
	// data vector search
	// 	a. find the index of the date before the input date
	// exchange
	// 	a. data value found * input value
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other) throw()
{
	(void)other;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() throw()
{}
