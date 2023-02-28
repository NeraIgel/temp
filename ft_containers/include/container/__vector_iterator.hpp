/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __vector_iterator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:02:13 by heha              #+#    #+#             */
/*   Updated: 2023/02/28 15:42:52 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FT_VECTOR_ITERATOR_HPP
# define __FT_VECTOR_ITERATOR_HPP

# include "iterator.hpp"
# include "type_traits.hpp"

namespace ft
{
	template <typename RandIt>
	class __vector_iterator {
	
	public:
		typedef RandIt												iterator_type;
		typedef typename iterator_traits<RandIt>::iterator_category	iterator_category;
		typedef typename iterator_traits<RandIt>::value_type		value_type;
		typedef typename iterator_traits<RandIt>::difference_type	difference_type;
		typedef typename iterator_traits<RandIt>::pointer			pointer;
		typedef typename iterator_traits<RandIt>::reference			reference;

		explicit __vector_iterator();
		explicit __vector_iterator(iterator_type it, typename enable_if<__libft_is_random_access_iterator<U>::value>::type* = 0);
		__vector_iterator(const __vector_iterator<RandIt>& other);
		__vector_iterator& operator=(const __vector_iterator& other);
		~__vector_iterator();

		iterator_type		base() const;
		reference			operator*() const;
		pointer				operator->() const;
		reference			operator[](difference_type n) const;
		__vector_iterator&	operator++();
		__vector_iterator&	operator--();
		__vector_iterator	operator++(int);
		__vector_iterator	operator--(int);
		__vector_iterator	operator+(difference_type n) const;
		__vector_iterator	operator-(difference_type n) const;
		__vector_iterator&	operator+=(difference_type n);
		__vector_iterator&	operator-=(difference_type n);
	
	private:
		iterator_type		__current;

	};

	template <typename RandIt> bool	operator==(const __vector_iterator<RandIt>& lhs, const __vector_iterator<RandIt>& rhs);
	template <typename RandIt> bool	operator!=(const __vector_iterator<RandIt>& lhs, const __vector_iterator<RandIt>& rhs);
	template <typename RandIt> bool	operator<(const __vector_iterator<RandIt>& lhs, const __vector_iterator<RandIt>& rhs);
	template <typename RandIt> bool	operator<=(const __vector_iterator<RandIt>& lhs, const __vector_iterator<RandIt>& rhs);
	template <typename RandIt> bool	operator>(const __vector_iterator<RandIt>& lhs, const __vector_iterator<RandIt>& rhs);
	template <typename RandIt> bool	operator>=(const __vector_iterator<RandIt>& lhs, const __vector_iterator<RandIt>& rhs);

	template <typename RandIt>
	__vector_iterator<RandIt>	operator+(typename __vector_iterator<RandIt>::difference_type n, __vector_iterator<RandIt> it);
	template <typename RandIt>
	typename __vector_iterator<RandIt>::difference_type	operator-(const __vector_iterator<RandIt>& lhs, const __vector_iterator<RandIt>& rhs);
}

# include "__vector_iterator.tpp"

#endif
