/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:28:55 by heha              #+#    #+#             */
/*   Updated: 2023/03/24 14:06:08 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <stack>
#include <stdexcept>
#include "RPN.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

RPN::RPN() throw()
{}

RPN::RPN(const RPN& other) throw()
{
	(void)other;
}

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

int	RPN::execute(const std::string& expr)
{
	if (expr.empty())
		throw std::runtime_error("Error: argument string is empty.");

	std::stack<int>	stack;
	for (std::string::const_iterator it = expr.begin(), ite = expr.end(); it != ite; ++it)
	{
		if (RPN::_isOperator(*it))
		{
			if ((*it == '+' || *it == '-') && stack.size() == 1)
			{
				int	n = stack.top(); stack.pop();
				stack.push(RPN::_calculate(n, *it));
			}
			else
			{
				if (stack.size() < 2)
					throw std::runtime_error("Error");
				int	b = stack.top(); stack.pop();
				int	a = stack.top(); stack.pop();
				stack.push(RPN::_calculate(a, b, *it));
			}
		}
		else if (RPN::_isOperand(*it))
			stack.push(*it - '0');
		else if (!std::isspace(static_cast<unsigned char>(*it)))
			throw std::runtime_error("Error");
	}
	if (stack.size() != 1)
		throw std::logic_error("Error");
	return (stack.top());
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

RPN&	RPN::operator=(const RPN& other) throw()
{
	(void)other;
	return (*this);
}

RPN::~RPN() throw()
{}

bool	RPN::_isOperand(char ch) throw()
{
	return (std::isdigit(static_cast<unsigned char>(ch)));
}

bool	RPN::_isOperator(char ch) throw()
{
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int	RPN::_calculate(int a, int b, char op)
{
	if (op == '+')	return (a + b);
	if (op == '-')	return (a - b);
	if (op == '*')	return (a * b);
	if (op == '/')
	{
		if (b == 0)
			throw std::runtime_error("Error");
		return (a / b);
	}
	throw std::logic_error("Error");
}

int	RPN::_calculate(int n, char op)
{
	if (op == '+')	return (n);
	if (op == '-')	return (-n);
	throw std::logic_error("Error");
}
