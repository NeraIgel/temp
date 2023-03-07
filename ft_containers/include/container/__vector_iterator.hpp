/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __vector_iterator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:02:13 by heha              #+#    #+#             */
/*   Updated: 2023/03/07 13:04:30 by heha             ###   ########.fr       */
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

		__vector_iterator() throw();
		__vector_iterator(iterator_type it,
				typename enable_if<__libft_is_random_access_iterator<RandIt>::value>::type* = 0) throw();	// TBD (explicit keyword)
		__vector_iterator(const __vector_iterator& other) throw();
		__vector_iterator& operator=(const __vector_iterator& other) throw();
		~__vector_iterator() throw();

		iterator_type		base() const throw();
		reference			operator*() const throw();
		pointer				operator->() const throw();
		reference			operator[](difference_type n) const throw();
		__vector_iterator&	operator++() throw();
		__vector_iterator&	operator--() throw();
		__vector_iterator	operator++(int) throw();
		__vector_iterator	operator--(int) throw();
		__vector_iterator	operator+(difference_type n) const throw();
		__vector_iterator	operator-(difference_type n) const throw();
		__vector_iterator&	operator+=(difference_type n) throw();
		__vector_iterator&	operator-=(difference_type n) throw();
	
	private:
		iterator_type		__current;

	};

	template <typename RandIt> inline bool	operator==(const __vector_iterator<RandIt>& lhs, const __vector_iterator<RandIt>& rhs) throw();
	template <typename RandIt> inline bool	operator!=(const __vector_iterator<RandIt>& lhs, const __vector_iterator<RandIt>& rhs) throw();
	template <typename RandIt> inline bool	operator<(const __vector_iterator<RandIt>& lhs, const __vector_iterator<RandIt>& rhs) throw();
	template <typename RandIt> inline bool	operator<=(const __vector_iterator<RandIt>& lhs, const __vector_iterator<RandIt>& rhs) throw();
	template <typename RandIt> inline bool	operator>(const __vector_iterator<RandIt>& lhs, const __vector_iterator<RandIt>& rhs) throw();
	template <typename RandIt> inline bool	operator>=(const __vector_iterator<RandIt>& lhs, const __vector_iterator<RandIt>& rhs) throw();

	template <typename RandIt> inline
	__vector_iterator<RandIt>	operator+(typename __vector_iterator<RandIt>::difference_type n, __vector_iterator<RandIt> it) throw();
	template <typename RandIt> inline
	typename __vector_iterator<RandIt>::difference_type	operator-(const __vector_iterator<RandIt>& lhs, const __vector_iterator<RandIt>& rhs) throw();
}

# include "__vector_iterator.tpp"

#endif
