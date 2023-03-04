/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:36:35 by heha              #+#    #+#             */
/*   Updated: 2023/02/06 18:20:23 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALGORITHM_HPP
# define FT_ALGORITHM_HPP

namespace ft
{
	template <typename InputIt1, typename InputIt2>	// add template parameter type check
	bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2);
	template <typename InputIt1, typename InputIt2, typename BinaryPredicate>	// add template parameter type check
	bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate pred);

	template <typename InputIt1, typename InputIt2>	// add template parameter type check
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2);
	template <typename InputIt1, typename InputIt2, typename Compare>	// add template parameter type check
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp);
}

# include "algorithm.tpp"

#endif
