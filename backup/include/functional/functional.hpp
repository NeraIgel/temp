/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:33:06 by heha              #+#    #+#             */
/*   Updated: 2023/02/06 18:34:24 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FUNCTIONAL_HPP
# define FT_FUNCTIONAL_HPP

namespace ft
{
	template <typename Arg1, typename Arg2, typename Result>
	struct binary_function {
		typedef Arg1	first_argument_type;
		typedef Arg2	second_argument_type;
		typedef Result	result_type;
	};

	template <typename T>
	struct less : public binary_function<T, T, bool> {
		bool	operator()(const T& lhs, const T& rhs) const;
	};
}

# include "functional.tpp"

#endif
