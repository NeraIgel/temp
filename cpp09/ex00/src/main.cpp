/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:53:14 by heha              #+#    #+#             */
/*   Updated: 2023/03/15 18:08:42 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <exception>
#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	bool	result = false;

	if (2 == argc)
	{
		try
		{
			BitcoinExchange	btc("data.csv", argv[1]);
			result = btc.execute();
		}
		catch (const std::exception& e)
		{
			std::cerr << "\033[30;1m" << e.what() << "\033[0m" << std::endl;
		}
	}
	else if (1 == argc)
		std::cerr << "\033[30;1m" << "Error: could not open file." << "\033[0m" << std::endl;
	else
		std::cerr << "\033[30;1m" << "Error: invalid number of arguments." << "\033[0m" << std::endl;
	return (result ? EXIT_SUCCESS : EXIT_FAILURE);
}
