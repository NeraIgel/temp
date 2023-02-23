/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:22:53 by heha              #+#    #+#             */
/*   Updated: 2023/02/22 18:14:36 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

template <typename InputIt>
void	ft::__advance(InputIt& it, typename ft::iterator_traits<InputIt>::difference_type n, ft::input_iterator_tag)
{
	while (n > 0)
	{
		--n;
		++it;
	}
}

template <typename BiDirIt>
void	ft::__advance(BiDirIt& it, typename ft::iterator_traits<BiDirIt>::differece_type n, ft::bidirectional_iterator_tag)
{
	while (n > 0)
	{
		--n;
		++it;
	}
	while (n < 0)
	{
		++n;
		--it;
	}
}

template <typename RandIt>
void	ft::__advance(RandIt& it, typename ft::iterator_traits<RandIt>::difference_type n, ft::random_access_iteator_tag)
{
	it += n;
}

template <typename InputIt, typename Distance>
void	ft::advance(InputIt& it, Distance n)
{
	ft::__advance(it, typename ft::iterator_traits<InputIt>::difference_type(n), typename ft::iterator_traits<InputIt>::iterator_category());
}

template <typename InputIt>
typename ft::iterator_traits<InputIt>::difference_type	ft::__distance(InputIt first, InputIt last, ft::input_iterator_tag)
{
	typename ft::iterator_traits<InputIt>::difference_type	result = 0;
	while (first != last)
	{
		++first;
		++result;
	}
	return (result);
}

template <typename RandIt>
typename ft::iterator_traits<RandIt>::difference_type	ft::__distance(RandIt first, RandIt last, ft::random_access_iterator_tag)
{
	return (last - first);
}

template <typename InputIt>
typename ft::iterator_traits<InputIt>::difference_type	ft::distance(InputIt first, InputIt last)
{
	ft::__distance(first, last, typename ft::iterator_traits<InputIt>::iterator_category());
}
