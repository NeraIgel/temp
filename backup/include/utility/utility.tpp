/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:00:15 by heha              #+#    #+#             */
/*   Updated: 2023/02/09 12:56:48 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

template <typename T1, typename T2>
ft::pair<T1, T2>::pair()
	: first(), second()
{}

template <typename T1, typename T2>
ft::pair<T1, T2>::pair(const T1& x, const T2& y)
	: first(x), second(y)
{}

template <typename T1, typename T2>
template <typename U1, typename U2>
ft::pair<T1, T2>::pair(const pair<U1, U2>& pr)
	: first(pr.first), second(pr.second)
{}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

template <typename T1, typename T2>
ft::pair<T1, T2>&	ft::pair<T1, T2>::operator=(const ft::pair<T1, T2>& other)
{
	if (this != &other)
	{
		first = other.first;
		second = other.second;
	}
	return (*this);
}

// ************************************************************************** //
//                             Non-member function                            //
// ************************************************************************** //

template <typename T1, typename T2>
bool	operator==(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template <typename T1, typename T2>
bool	operator!=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return (!(lhs == rhs));
}

template <typename T1, typename T2>
bool	operator<(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	if (lhs.first < rhs.first)
		return (true);
	else if (rhs.first < lhs.first)
		return (false);
	else
		return (lhs.second < rhs.second);
}

template <typename T1, typename T2>
bool	operator<=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return (!(rhs < lhs));
}

template <typename T1, typename T2>
bool	operator>(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return (rhs < lhs);
}

template <typename T1, typename T2>
bool	operator>=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return (!(lhs < rhs));
}

template <typename T1, typename T2>
ft::pair<T1, T2>	make_pair(T1 x, T2 y)
{
	return (ft::pair<T1, T2>(x, y));
}
