/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:29:13 by heha              #+#    #+#             */
/*   Updated: 2023/03/24 21:38:16 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include <iostream>
#include <exception>
#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	try
	{
		std::string	input;
		for (int i = 1; i < argc; ++i)
		{
			input += argv[i];
			input += ' ';
		}

		PmergeMe::execute(input);
	}
	catch (const std::exception& e)
	{
		std::cout << "\033[31;1m" << e.what() << "\033[0m" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
