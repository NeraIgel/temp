/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:50:04 by heha              #+#    #+#             */
/*   Updated: 2023/03/21 13:56:07 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <exception>
#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	try
	{
		if (argc == 1)
			throw std::logic_error("Error: could not open file.");
		else if (argc > 2)
			throw std::logic_error("Error: invalid number of arguments.");

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
