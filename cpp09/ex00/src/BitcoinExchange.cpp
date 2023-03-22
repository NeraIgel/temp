/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:17:26 by heha              #+#    #+#             */
/*   Updated: 2023/03/22 21:17:37 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <limits>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
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
	: _database()
{
	if (!_ends_with(datafile, ".csv"))
		throw std::logic_error("Error: bad csv file extension.");

	std::ifstream	inFile(datafile.c_str());
	if (!inFile.is_open())
		throw std::logic_error("Error: could not open file.");

	std::stringstream	ss;
	ss << inFile.rdbuf();
	inFile.close();

	_initDatabase(ss);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: _database(other._database)
{}

BitcoinExchange::BitcoinExchange()
	: _database()
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

	_validateInputfile(ss);
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_database = other._database;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() throw()
{
	_database.clear();
}

void	BitcoinExchange::_initDatabase(std::stringstream& input)
{
	std::string	title;
	std::getline(input, title);

	std::string	line;
	std::string	date;
	float		rate;
	while (std::getline(input, line))
	{
		try
		{
			_parseDatabaseLine(line, ',', date, rate, std::numeric_limits<float>::max());
			_database.insert(std::pair<std::string, float>(date, rate));
		}
		catch (const std::exception& e)
		{
			throw;
		}
		line.clear();
	}
}

void	BitcoinExchange::_validateInputfile(std::stringstream& input) const
{
	std::string	title;
	std::getline(input, title);

	std::string	line;
	std::string	date;
	float		value;
	while (std::getline(input, line))
	{
		try
		{
			_parseDatabaseLine(line, '|', date, value, 1000.f);
			std::map<std::string, float>::const_iterator	it = _database.upper_bound(date);
			if (it != _database.begin())
				--it;
			//std::cout << "test: " << (*it).first << ", " << (*it).second << " / ";
			std::cout << date << " => " << value << " = " << (*it).second * value << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "\033[30;1m" << e.what() << "\033[0m" << std::endl;
		}
		line.clear();
	}
}

void	BitcoinExchange::_parseDatabaseLine(const std::string& line, char delimiter, std::string& date, float& n, float max) const
{
	std::string::size_type	pos = line.rfind(delimiter);
	if (pos == std::string::npos)
		throw std::logic_error(std::string("Error: bad input => ") + line);

	date.clear();
	date = line.substr(0, pos);
	date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
	struct tm	tm;
    if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
		throw std::logic_error(std::string("Error: bad input => ") + line);

	std::istringstream	iss(line.substr(pos + 1));
	n = 0.0f;
	iss >> n;
	if (!iss)
		throw std::logic_error(std::string("Error: bad input => ") + line);
	if (n < 0.0f)
		throw std::logic_error("Error: not a positive number.");
	else if (n > max)
		throw std::logic_error("Error: too large a number.");
}
