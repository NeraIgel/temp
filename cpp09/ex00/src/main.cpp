/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:11:09 by heha              #+#    #+#             */
/*   Updated: 2023/03/24 14:00:49 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	try
	{
		if (argc == 1)
			throw std::runtime_error("Error: could not open file.");
		else if (argc != 2)
			throw std::runtime_error("Error: invalid number of arguments.");

		BitcoinExchange	btc("data.csv");
		btc.execute(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cout << "\033[31;1m" << e.what() << "\033[0m" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
