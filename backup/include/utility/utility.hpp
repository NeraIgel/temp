/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:04:49 by heha              #+#    #+#             */
/*   Updated: 2023/02/07 16:57:12 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILITY_HPP
# define FT_UTILITY_HPP

namespace ft
{
	template <typename T1, typename T2>
	struct pair {
		T1	first;
		T2	second;

		typedef T1	first_type;
		typedef T2	second_type;

		pair();
		pair(const T1& x, const T2& y);
		template <typename U1, typename U2>
		pair(const pair<U1, U2>& pr);
		pair& operator=(const pair& other);
	};

	template <typename T1, typename T2> bool	operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
	template <typename T1, typename T2> bool	operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
	template <typename T1, typename T2> bool	operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
	template <typename T1, typename T2> bool	operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
	template <typename T1, typename T2> bool	operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
	template <typename T1, typename T2> bool	operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);

	template <typename T1, typename T2>
	pair<T1, T2>	make_pair(T1 x, T2 y);
}

# include "utility.tpp"

#endif
