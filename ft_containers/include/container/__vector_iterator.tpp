/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __vector_iterator.tpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:57:01 by heha              #+#    #+#             */
/*   Updated: 2023/02/24 19:43:02 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

template <typename RandIt>
ft::__vector_iterator<RandIt>::__vector_iterator()
	: __current()
{}

template <typename RandIt>
template <typename U>
ft::__vector_iterator<RandIt>::__vector_iterator(const ft::__vector_iterator<U>& other)
	: __current(other.base())
{}

template <typename RandIt>
ft::__vector_iterator<RandIt>::__vector_iterator(typename ft::__vector_iterator<RandIt>::iterator_type it)
	: __current(it)
{}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

template <typename RandIt>
template <typename U>
ft::__vector_iterator<RandIt>&	ft::__vector_iterator<RandIt>::operator=(const ft::__vector_iterator<U>& other)
{
	__current = other.base();
	return (*this);
}

template <typename RandIt>
ft::__vector_iterator<RandIt>::~__vector_iterator()
{}

template <typename RandIt>
typename ft::__vector_iterator<RandIt>::iterator_type	ft::__vector_iterator<RandIt>::base() const
{
	return (__current);
}

template <typename RandIt>
typename ft::__vector_iterator<RandIt>::reference	ft::__vector_iterator<RandIt>::operator*() const
{
	return (*__current);
}

template <typename RandIt>
typename ft::__vector_iterator<RandIt>::pointer	ft::__vector_iterator<RandIt>::operator->() const
{
	return (&(operator*()));
}

template <typename RandIt>
typename ft::__vector_iterator<RandIt>::reference	ft::__vector_iterator<RandIt>::operator[](typename ft::__vector_iterator<RandIt>::difference_type n) const
{
	return (*(*this + n));
}

template <typename RandIt>
ft::__vector_iterator<RandIt>&	ft::__vector_iterator<RandIt>::operator++()
{
	++__current;
	return (*this);
}

template <typename RandIt>
ft::__vector_iterator<RandIt>&	ft::__vector_iterator<RandIt>::operator--()
{
	--__current;
	return (*this);
}

template <typename RandIt>
ft::__vector_iterator<RandIt>	ft::__vector_iterator<RandIt>::operator++(int)
{
	ft::__vector_iterator<RandIt>	tmp = *this;
	++(*this);
	return (tmp)
}

template <typename RandIt>
ft::__vector_iterator<RandIt>	ft::__vector_iterator<RandIt>::operator--(int)
{
	ft::__vector_iterator<RandIt>	tmp = *this;
	--(*this);
	return (tmp);
}

template <typename RandIt>
ft::__vector_iterator<RandIt>	ft::__vector_iterator<RandIt>::operator+(typename ft::__vector_iterator<RandIt>::difference_type n) const
{
	ft::__vector_iterator<RandIt>	tmp = *this;
	tmp += n;
	return (tmp);
}

template <typename RandIt>
ft::__vector_iterator<RandIt>	ft::__vector_iterator<RandIt>::operator-(typename ft::__vector_iterator<RandIt>::difference_type n) const
{
	ft::__vector_iterator<RandIt>	tmp = *this;
	tmp -= n;
	return (tmp);
}

template <typename RandIt>
ft::__vector_iterator<RandIt>&	ft::__vector_iterator<RandIt>::operator+=(typename ft::__vector_iterator<RandIt>::difference_type n)
{
	__current += n;
	return (*this);
}

template <typename RandIt>
ft::__vector_iterator<RandIt>&	ft::__vector_iterator<RandIt>::operator-=(typename ft::__vector_iterator<RandIt>::difference_type n)
{
	__current -= n;
	return (*this);
}

// ************************************************************************** //
//                             Non-member function                            //
// ************************************************************************** //

template <typename RandIt>
bool	ft::operator==(const ft::__vector_iterator<RandIt>& lhs, const ft::__vector_iterator<RandIt>& rhs)
{
	return (lhs.base() == rhs.base());
}

template <typename RandIt>
bool	ft::operator!=(const ft::__vector_iterator<RandIt>& lhs, const ft::__vector_iterator<RandIt>& rhs)
{
	return (!(lhs == rhs));
}

template <typename RandIt>
bool	ft::operator<(const ft::__vector_iterator<RandIt>& lhs, const ft::__vector_iterator<RandIt>& rhs)
{
	return (lhs.base() < rhs.base());
}

template <typename RandIt>
bool	ft::operator<=(const ft::__vector_iterator<RandIt>& lhs, const ft::__vector_iterator<RandIt>& rhs)
{
	return (!(rhs < lhs));
}

template <typename RandIt>
bool	ft::operator>(const ft::__vector_iterator<RandIt>& lhs, const ft::__vector_iterator<RandIt>& rhs)
{
	return (rhs < lhs);
}

template <typename RandIt>
bool	ft::operator>=(const ft::__vector_iterator<RandIt>& lhs, const ft::__vector_iterator<RandIt>& rhs)
{
	return (!(lhs < rhs));
}

template <typename RandIt>
ft::__vector_iterator<RandIt>	operator+(typename ft::__vector_iterator<RandIt>::difference_type n, const ft::__vector_iterator<RandIt>& it)
{
	return (ft::__vector_iterator<RandIt>(it.base() + n));
}

template <typename RandIt>
typename ft::__vector_iterator<RandIt>::difference_type	operator-(const ft::__vector_iterator<RandIt>& lhs, const ft::__vector_iterator<RandIt>& rhs)
{
	return (lhs.base() - rhs.base());
}
