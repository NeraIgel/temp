/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __vector_iterator.tpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:57:01 by heha              #+#    #+#             */
/*   Updated: 2023/03/02 12:56:58 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

template <typename RandIt>
ft::__vector_iterator<RandIt>::__vector_iterator() throw()
	: __current()
{}

template <typename RandIt>
ft::__vector_iterator<RandIt>::__vector_iterator(typename ft::__vector_iterator<RandIt>::iterator_type it) throw()
	: __current(it)
{}

template <typename RandIt>
ft::__vector_iterator<RandIt>::__vector_iterator(const ft::__vector_iterator<RandIt>& other) throw()
	: __current(other.base())
{}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

template <typename RandIt>
ft::__vector_iterator<RandIt>&	ft::__vector_iterator<RandIt>::operator=(const ft::__vector_iterator<Rand>& other) throw()
{
	if (this != &other)
	{
		__current = other.base();
	}
	return (*this);
}

template <typename RandIt>
ft::__vector_iterator<RandIt>::~__vector_iterator() throw()
{}

template <typename RandIt>
typename ft::__vector_iterator<RandIt>::iterator_type	ft::__vector_iterator<RandIt>::base() const throw()
{
	return (__current);
}

template <typename RandIt>
typename ft::__vector_iterator<RandIt>::reference	ft::__vector_iterator<RandIt>::operator*() const throw()
{
	return (*__current);
}

template <typename RandIt>
typename ft::__vector_iterator<RandIt>::pointer	ft::__vector_iterator<RandIt>::operator->() const throw()
{
	return (&(operator*()));
}

template <typename RandIt>
typename ft::__vector_iterator<RandIt>::reference	ft::__vector_iterator<RandIt>::operator[](typename ft::__vector_iterator<RandIt>::difference_type n) const throw()
{
	return (__current[n]);
}

template <typename RandIt>
ft::__vector_iterator<RandIt>&	ft::__vector_iterator<RandIt>::operator++() throw()
{
	++__current;
	return (*this);
}

template <typename RandIt>
ft::__vector_iterator<RandIt>&	ft::__vector_iterator<RandIt>::operator--() throw()
{
	--__current;
	return (*this);
}

template <typename RandIt>
ft::__vector_iterator<RandIt>	ft::__vector_iterator<RandIt>::operator++(int) throw()
{
	ft::__vector_iterator<RandIt>	tmp = *this;
	++(*this);
	return (tmp)
}

template <typename RandIt>
ft::__vector_iterator<RandIt>	ft::__vector_iterator<RandIt>::operator--(int) throw()
{
	ft::__vector_iterator<RandIt>	tmp = *this;
	--(*this);
	return (tmp);
}

template <typename RandIt>
ft::__vector_iterator<RandIt>	ft::__vector_iterator<RandIt>::operator+(typename ft::__vector_iterator<RandIt>::difference_type n) const throw()
{
	ft::__vector_iterator<RandIt>	tmp = *this;
	tmp += n;
	return (tmp);
}

template <typename RandIt>
ft::__vector_iterator<RandIt>	ft::__vector_iterator<RandIt>::operator-(typename ft::__vector_iterator<RandIt>::difference_type n) const throw()
{
	ft::__vector_iterator<RandIt>	tmp = *this;
	tmp -= n;
	return (tmp);
}

template <typename RandIt>
ft::__vector_iterator<RandIt>&	ft::__vector_iterator<RandIt>::operator+=(typename ft::__vector_iterator<RandIt>::difference_type n) throw()
{
	__current += n;
	return (*this);
}

template <typename RandIt>
ft::__vector_iterator<RandIt>&	ft::__vector_iterator<RandIt>::operator-=(typename ft::__vector_iterator<RandIt>::difference_type n) throw()
{
	__current -= n;
	return (*this);
}

// ************************************************************************** //
//                             Non-member function                            //
// ************************************************************************** //

template <typename RandIt>
inline
bool	ft::operator==(const ft::__vector_iterator<RandIt>& lhs, const ft::__vector_iterator<RandIt>& rhs) throw()
{
	return (lhs.base() == rhs.base());
}

template <typename RandIt>
inline
bool	ft::operator!=(const ft::__vector_iterator<RandIt>& lhs, const ft::__vector_iterator<RandIt>& rhs) throw()
{
	return (!(lhs == rhs));
}

template <typename RandIt>
inline
bool	ft::operator<(const ft::__vector_iterator<RandIt>& lhs, const ft::__vector_iterator<RandIt>& rhs) throw()
{
	return (lhs.base() < rhs.base());
}

template <typename RandIt>
inline
bool	ft::operator<=(const ft::__vector_iterator<RandIt>& lhs, const ft::__vector_iterator<RandIt>& rhs) throw()
{
	return (!(rhs < lhs));
}

template <typename RandIt>
inline
bool	ft::operator>(const ft::__vector_iterator<RandIt>& lhs, const ft::__vector_iterator<RandIt>& rhs) throw()
{
	return (rhs < lhs);
}

template <typename RandIt>
inline
bool	ft::operator>=(const ft::__vector_iterator<RandIt>& lhs, const ft::__vector_iterator<RandIt>& rhs) throw()
{
	return (!(lhs < rhs));
}

template <typename RandIt>
inline
ft::__vector_iterator<RandIt>	operator+(typename ft::__vector_iterator<RandIt>::difference_type n, ft::__vector_iterator<RandIt> it) throw()
{
	it += n;
	return (it);
}

template <typename RandIt>
inline
typename ft::__vector_iterator<RandIt>::difference_type	operator-(const ft::__vector_iterator<RandIt>& lhs, const ft::__vector_iterator<RandIt>& rhs) throw()
{
	return (lhs.base() - rhs.base());
}
