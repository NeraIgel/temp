/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:06:53 by heha              #+#    #+#             */
/*   Updated: 2023/03/21 19:32:00 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <stdexcept>
#include <algorithm>
#include "BitcoinExchange.hpp"

// ************************************************************************** //
//                                Internals                                   //
// ************************************************************************** //

static bool	_ends_with(const std::string& str, const std::string& suffix)
{
	return (str.size() >= suffix.size() &&
			std::equal(suffix.rbegin(), suffix.rend(), str.rbegin()));
}

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

BitcoinExchange::BitcoinExchange(const std::string& datafile)
	: _datamap()
{
	if (!_ends_with(datafile, ".csv"))
		throw std::logic_error("Error: bad csv file extension.");

	std::ifstream	inFile(datafile.c_str());
	if (!inFile.is_open())
		throw std::logic_error("Error: could not open file.");

	std::stringstream	ss;
	ss << inFile.rdbuf();
	inFile.close();

	_initDataMap(ss);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: _datamap(other._datamap)
{}

BitcoinExchange::BitcoinExchange()
	: _datamap()
{}

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

void	BitcoinExchange::execute(const std::string& inputfile) const
{
	std::ifstream	inFile(inputfile.c_str());
	if (!inFile.is_open())
		throw std::logic_error("Error: could not open file.");

	std::stringstream	ss;
	ss << inFile.rdbuf();
	inFile.close();
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_datamap = other._datamap;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() throw()
{
	_datamap.clear();
}

void	BitcoinExchange::_initDataMap(const std::stringstream& input)
{
	std::string	line;
	while (std::getline(input, line))
	{
		std::string::size_type	n = line.rfind(',');
		if (n == std::string::npos)
			throw std::logic_error(std::string("Error: bad input => ") + line);

		std::istringstream	iss(line.substr(n + 1));
		float				rate;
		iss >> rate;
		if (!iss)
			throw std::logic_error(std::string("Error: bad input => ") + line);

		_datamap.insert(std::pair<std::string, float>(line.substr(0, n - 1), rate));
		line.clear();
	}
}
