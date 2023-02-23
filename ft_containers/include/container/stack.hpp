/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:40:08 by heha              #+#    #+#             */
/*   Updated: 2023/02/21 18:39:28 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FT_STACK_HPP
# define FT_STACK_HPP

# include "vector.hpp"

// ************************************************************************** //
//                             stack class template                           //
// ************************************************************************** //

namespace ft
{
	template <typename T, typename Container = vector<T> >
	class stack {

		template <typename _T1, typename _C1>
		friend bool	operator==(const stack<_T1, _C1>&, const stack<_T1, _C1>&);
		template <typename _T1, typename _C1>
		friend bool	operator<(const stack<_T1, _C1>&, const stack<_T1, _C1>&);
	
	public:
		typedef Container							container_type;
		typedef typename container_type::value_type	value_type;
		typedef typename container_type::size_type	size_type;

		explicit stack(const container_type& ctnr = container_type());
		stack(const stack& other);
		stack& operator=(const stack& other);
		~stack();

		bool				empty() const;
		size_type			size() const;

		value_type&			top();
		const value_type&	top() const;

		void				push(const value_type& value);
		void				pop();

	protected:
		Container			c;

	};

	template <typename T, typename Container> bool	operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	template <typename T, typename Container> bool	operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	template <typename T, typename Container> bool	operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	template <typename T, typename Container> bool	operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	template <typename T, typename Container> bool	operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	template <typename T, typename Container> bool	operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
}

# include "stack.tpp"

#endif
