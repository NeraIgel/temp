/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:48:21 by heha              #+#    #+#             */
/*   Updated: 2023/03/21 19:29:25 by heha             ###   ########.fr       */
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

	void	_initDataMap(const std::stringstream& data);

	std::map<std::string, float>	_datamap;

};

#endif
