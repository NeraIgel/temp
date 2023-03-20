/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:04:03 by heha              #+#    #+#             */
/*   Updated: 2023/03/20 18:28:26 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include <iostream>
#include <exception>
#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	try
	{
		std::string	expr;
		for (int i = 1; i < argc; ++i)
			expr += argv[i];

		std::cout << RPN::execute(expr) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "\033[31;1m" << e.what() << "\033[0m" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
