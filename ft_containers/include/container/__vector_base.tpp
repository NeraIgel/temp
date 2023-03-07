/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __vector_base.tpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:53:17 by heha              #+#    #+#             */
/*   Updated: 2023/03/07 20:42:24 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

template <typename T, typename Allocator>
ft::__vector_base<T, Allocator>::__vector_base()
	: __allocator(), __end_cap(NULL), __begin(NULL), __end(NULL)
{}

template <typename T, typename Allocator>
ft::__vector_base<T, Allocator>::__vector_base(const typename ft::__vector_base<T, Allocator>::allocator_type& alloc)
	: __allocator(alloc), __end_cap(NULL), __begin(NULL), __end(NULL)
{}

// ************************************************************************** //
//                                 Capacity                                   //
// ************************************************************************** //

template <typename T, typename Allocator>
typename ft::__vector_base<T, Allocator>::size_type	ft::__vector_base<T, Allocator>::__capacity() const throw()
{
	return (static_cast<typename ft::__vector_base<T, Allocator>::size_type>(__end_cap - __begin));
}

// ************************************************************************** //
//                                 Modifiers                                  //
// ************************************************************************** //

template <typename T, typename Allocator>
void	ft::__vector_base<T, Allocator>::__copy_assign_alloc(const ft::__vector_base<T, Allocator>& other)
{
}

template <typename T, typename Allocator>
void	ft::__vector_base<T, Allocator>::__destruct_at_end(typename ft::__vector_base<T, Allocator>::pointer new_last) throw()
{
}

template <typename T, typename Allocator>
void	ft::__vector_base<T, Allocator>::__move_assign_alloc(ft::__vector_base<T, Allocator>& other)
{
}

template <typename T, typename Allocator>
void	ft::__vector_base<T, Allocator>::__clear() throw()
{
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

template <typename T, typename Allocator>
ft::__vector_base<T, Allocator>::~__vector_base()
{
}
