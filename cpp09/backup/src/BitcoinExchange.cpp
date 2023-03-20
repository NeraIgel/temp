/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:16:24 by heha              #+#    #+#             */
/*   Updated: 2023/03/16 16:48:58 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "BitcoinExchange.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

BitcoinExchange::BitcoinExchange(const std::string& dataFileName, const std::string& inputFileName)
	: _data(), _input()
{
	std::string		dataFileExtension(".csv");
	if (!ends_with(dataFileName, dataFileExtension))
		std::logic_error("Error: bad file extension.");

	std::ifstream	dataFile(dataFileName.c_str());
	if (!dataFile.is_open())
		std::logic_error("Error: could not open file.");
	
	// data file open -> read -> vector push_back() -> close (if file open is fails, throw exception)
	// input file open -> read -> vector push_back() -> close (if file open is fails, throw exception)
}

BitcoinExchange::BitcoinExchange()
	: _data(), _input()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: _data(other._data), _input(other._input)
{}

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

bool	BitcoinExchange::execute()
{
	// input vector front check
	//	a. format check (e.g. "date | value")
	// 	b. date item check (e.g. "Year-Month-Day")
	// 	c. value item check (e.g. float or positive integer between 0 and 1000)
	// data vector search
	// 	a. find the index of the date before the input date
	// exchange
	// 	a. data value found * input value
	return (true);
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

BitcoinExchange::~BitcoinExchange() throw()
{
	_data.clear();
	_input.clear();
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_data = other._data;
		_input = other._input;
	}
	return (*this);
}

bool	BitcoinExchange::_ends_with(const std::string& value, const std::string& ending)
{
	return (ending.size() <= value.size() &&
			std::equal(ending.rbegin(), ending.rend(), value.rbegin()));
}
