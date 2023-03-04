/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:02:14 by heha              #+#    #+#             */
/*   Updated: 2023/02/06 13:04:26 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

template <typename InputIt1, typename InputIt2>
bool	ft::equal<InputIt1, InputIt2>(InputIt1 first1, InputIt1 last1, InputIt2 first2)
{
	for (; first1 != last1; ++first1, ++first2)
	{
		if (!(*first1 == *first2))
			return (false);
	}
	return (true);
}

template <typename InputIt1, typename InputIt2, typename BinaryPredicate>
bool	ft::equal<InputIt1, InputIt2, BinaryPredicate>(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate pred)
{
	for (; first1 != last1; ++first1, ++first2)
	{
		if (!pred(*first1, *first2))
			return (false);
	}
	return (true);
}

template <typename InputIt1, typename InputIt2>
bool	ft::lexicographical_compare<InputIt1, InputIt2>(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
{
	for (; first1 != last1 && first2 != last2; ++first1, (void)++first2)	 // further research
	{
		if (*first1 < *first2)
			return (true);
		if (*first2 < *first1)
			return (false);
	}
	return (first1 == last1 && first2 != last2);
}

template <typename InputIt1, typename InputIt2, typename Compare>
bool	ft::lexicographical_compare<InputIt1, InputIt2, Compare>(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
{
	for (; first1 != last1 && first2 != last2; ++first1, (void)++first2)	 // further research
	{
		if (comp(*first1, *first2))
			return (true);
		if (comp(*first2, *first1))
			return (false);
	}
	return (first1 == last1 && first2 != last2);
}
