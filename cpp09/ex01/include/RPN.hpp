/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:02:07 by heha              #+#    #+#             */
/*   Updated: 2023/03/20 19:06:08 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_HPP
# define RPN_HPP

// ************************************************************************** //
//                                  RPN Class                                 //
// ************************************************************************** //

# include <string>

class RPN {

public:
	RPN() throw();
	RPN(const RPN& other) throw();
	RPN& operator=(const RPN& other) throw();
	~RPN() throw();

	static int	execute(const std::string& expr);

private:
	static bool	_isOperand(char ch) throw();
	static bool	_isOperator(char ch) throw();
	static int	_calculate(int a, int b, char op);
	static int	_calculate(int n, char op);

};

#endif
