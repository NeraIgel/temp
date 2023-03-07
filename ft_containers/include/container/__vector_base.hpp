/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __vector_base.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:51:49 by heha              #+#    #+#             */
/*   Updated: 2023/03/07 20:42:10 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FT_VECTOR_BASE_HPP
# define __FT_VECTOR_BASE_HPP

# include <cstddef>

namespace ft
{
	template <typename T, typename Allocator>
	class __vector_base {

	protected:
		typedef T											value_type;
		typedef Allocator									allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef std::size_t									size_type;

		__vector_base();
		explicit __vector_base(const allocator_type& alloc);	// TBD (explicit keyword)
		~__vector_base();

		size_type		__capacity() const throw();

		void			__copy_assign_alloc(const __vector_base& other);
		void			__destruct_at_end(pointer new_last) throw();
		void			__move_assign_alloc(__vector_base& other);
		void			__clear() throw();

	private:
		__vector_base(const __vector_base& other)				{ (void)other; }
		__vector_base& operator=(const __vector_base& other);	{ (void)other; return (*this); }
	
	protected:
		allocator_type	__allocator;
		pointer			__end_cap;
		pointer			__begin;
		pointer			__end;

	};
}

# include "__vector_base.tpp"

#endif
