/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:08:49 by heha              #+#    #+#             */
/*   Updated: 2023/03/16 16:48:31 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

// ************************************************************************** //
//                            BitcoinExchange Class                           //
// ************************************************************************** //

# include <string>
# include <vector>

class BitcoinExchange {

public:
	explicit BitcoinExchange(const std::string& dataFileName, const std::string& inputFileName);
	~BitcoinExchange() throw();

	bool	execute();

private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);

	bool	_ends_with(const std::string& value, const std::string& ending);
	void	_data_parsing(const std::string& filename);

	std::vector<std::string>	_datas;
	std::vector<std::string>	_inputs;

};

#endif
