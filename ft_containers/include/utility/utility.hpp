/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:46:11 by heha              #+#    #+#             */
/*   Updated: 2023/03/02 13:49:44 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FT_UTILITY_HPP
# define FT_UTILITY_HPP

namespace ft
{
	template <typename T1, typename T2>
	struct pair {
		typedef T1	first_type;
		typedef T2	second_type;

		T1	first;
		T2	second;

		pair();
		pair(const T1& x, const T2& y);
		template <typename U1, typename U2>
		pair(const pair<U1, U2>& pr);
		pair& operator=(const pair& other);
	};

	template <typename T1, typename T2> inline bool	operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
	template <typename T1, typename T2> inline bool	operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
	template <typename T1, typename T2> inline bool	operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
	template <typename T1, typename T2> inline bool	operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
	template <typename T1, typename T2> inline bool	operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
	template <typename T1, typename T2> inline bool	operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);

	template <typename T1, typename T2> inline
	pair<T1, T2>	make_pair(T1 x, T2 y);
}

# include "utility.tpp"

#endif
