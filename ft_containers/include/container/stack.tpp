/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:01:09 by heha              #+#    #+#             */
/*   Updated: 2023/03/02 13:53:25 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

template <typename T, typename Container>
ft::stack<T, Container>::stack(const typename ft::stack<T, Container>::container_type& ctnr)
	: c(ctnr)
{}

template <typename T, typename Container>
ft::stack<T, Container>::stack(const ft::stack<T, Container>& other)
	: c(other.c)
{}

// ************************************************************************** //
//                                 Capacity                                   //
// ************************************************************************** //

template <typename T, typename Container>
bool	ft::stack<T, Container>::empty() const
{
	return (c.empty());
}

template <typename T, typename Container>
typename ft::stack<T, Container>::size_type	ft::stack<T, Container>::size() const
{
	return (c.size());
}

// ************************************************************************** //
//                              Element access                                //
// ************************************************************************** //

template <typename T, typename Container>
typename ft::stack<T, Container>::value_type&	ft::stack<T, Container>::top()
{
	return (c.back());
}

template <typename T, typename Container>
const typename ft::stack<T, Container>::value_type&	ft::stack<T, Container>::top() const
{
	return (c.back());
}

// ************************************************************************** //
//                                 Modifiers                                  //
// ************************************************************************** //

template <typename T, typename Container>
void	ft::stack<T, Container>::push(const typename ft::stack<T, Container>::value_type& value)
{
	c.push_back(value);
}

template <typename T, typename Container>
void	ft::stack<T, Container>::pop()
{
	c.pop_back();
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

template <typename T, typename Container>
ft::stack<T, Container>&	ft::stack<T, Container>::operator=(const ft::stack<T, Container>& other)
{
	if (this != &other)
	{
		c = other.c;
	}
	return (*this);
}

template <typename T, typename Container>
ft::stack<T, Container>::~stack()
{}

// ************************************************************************** //
//                             Non-member function                            //
// ************************************************************************** //

template <typename T, typename Container>
inline
bool	ft::operator==(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return (lhs.c == rhs.c);
}

template <typename T, typename Container>
inline
bool	ft::operator!=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return (!(lhs == rhs));
}

template <typename T, typename Container>
inline
bool	ft::operator<(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return (lhs.c < rhs.c);
}

template <typename T, typename Container>
inline
bool	ft::operator<=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return (!(rhs < lhs));
}

template <typename T, typename Container>
inline
bool	ft::operator>(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return (rhs < lhs);
}

template <typename T, typename Container>
inline
bool	ft::operator>=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return (!(lhs < rhs));
}
