/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:09:02 by heha              #+#    #+#             */
/*   Updated: 2023/03/23 15:26:57 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

// ************************************************************************** //
//                            BitcoinExchange Class                           //
// ************************************************************************** //

# include <map>
# include <string>
# include <sstream>

class BitcoinExchange {

public:
	explicit BitcoinExchange(const std::string& datafile);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange() throw();

	void	execute(const std::string& inputfile) const;

private:
	BitcoinExchange();

	void	_initDatabase(std::stringstream& input);
	void	_validateInputfile(std::stringstream& input) const;
	void	_parseDatabaseLine(const std::string& line, char delimiter, std::string& date, float& n, float max) const;

	std::map<std::string, float>	_database;

};

#endif
