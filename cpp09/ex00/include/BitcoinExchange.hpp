/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:48:21 by heha              #+#    #+#             */
/*   Updated: 2023/03/20 19:03:00 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

// ************************************************************************** //
//                            BitcoinExchange Class                           //
// ************************************************************************** //

# include <string>

class BitcoinExchange {

public:
	BitcoinExchange() throw();
	BitcoinExchange(const BitcoinExchange& other) throw();
	BitcoinExchange& operator=(const BitcoinExchange& other) throw();
	~BitcoinExchange() throw();

	static void	execute(const std::string& datafile, const std::string& inputfile);

private:

};

#endif
