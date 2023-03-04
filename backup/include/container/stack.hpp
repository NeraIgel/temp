/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:03:00 by heha              #+#    #+#             */
/*   Updated: 2023/02/09 12:22:22 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_HPP
# define FT_STACK_HPP

# include <cstddef>
# include "vector.hpp"

// ************************************************************************** //
//                                 stack class                                //
// ************************************************************************** //

namespace ft
{
	template <typename T, typename Container = vector<T>>
	class stack {
	
	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef std::size_t	size_type;

		explicit stack(const Container& cont = Container());
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
