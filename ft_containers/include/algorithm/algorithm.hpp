/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:18:54 by heha              #+#    #+#             */
/*   Updated: 2023/03/03 18:14:53 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FT_ALGORITHM_HPP
# define FT_ALGORITHM_HPP

namespace ft
{
	template <typename InputIt1, typename InputIt2>
	bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2);
	template <typename InputIt1, typename InputIt2, typename BinaryPredicate>
	bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate pred);

	template <typename InputIt1, typename InputIt2>
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2);
	template <typename InputIt1, typename InputIt2, typename Compare>
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp);

	template <typename T>
	const T&	min(const T& a, const T& b);
	template <typename T, typename Compare>
	const T&	min(const T& a, const T& b, Compare comp);
}

# include "algorithm.tpp"

#endif
