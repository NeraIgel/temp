/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:32:25 by heha              #+#    #+#             */
/*   Updated: 2023/02/24 17:00:52 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

template <typename Iter>
ft::reverse_iterator<Iter>::reverse_iterator()
	: current()
{}

template <typename Iter>
ft::reverse_iterator<Iter>::reverse_iterator(typename ft::reverse_iterator<Iter>::iterator_type it)
	: current(it)
{}

template <typename Iter>
template <typename U>
ft::reverse_iterator<Iter>::reverse_iterator(const ft::reverse_iterator<U>& other)
	: current(other.base())
{}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

template <typename Iter>
template <typename U>
ft::reverse_iterator<Iter>&	ft::reverse_iterator<Iter>::operator=(const ft::reverse_iterator<U>& other)
{
	current = other.base();
	return (*this);
}

template <typename Iter>
typename ft::reverse_iterator<Iter>::iterator_type	ft::reverse_iterator<Iter>::base() const
{
	return (current);
}

template <typename Iter>
typename ft::reverse_iterator<Iter>::reference	ft::reverse_iterator<Iter>::operator*() const
{
	Iter	tmp = current;
	return (*--tmp);
}

template <typename Iter>
typename ft::reverse_iterator<Iter>::pointer	ft::reverse_iterator<Iter>::operator->() const
{
	return (&(operator*()));
}

template <typename Iter>
typename ft::reverse_iterator<Iter>::reference	ft::reverse_iterator<Iter>::operator[](typename ft::reverse_iterator<Iter>::difference_type n) const
{
	//return (base()[-n - 1]);
	return (*(*this + n));
}

template <typename Iter>
ft::reverse_iterator<Iter>&	ft::reverse_iterator<Iter>::operator++()
{
	--current;
	return (*this);
}

template <typename Iter>
ft::reverse_iterator<Iter>&	ft::reverse_iterator<Iter>::operator--()
{
	++current;
	return (*this);
}

template <typename Iter>
ft::reverse_iterator<Iter>	ft::reverse_iterator<Iter>::operator++(int)
{
	ft::reverse_iterator<Iter>	tmp = *this;
	++(*this);
	return (tmp);
}

template <typename Iter>
ft::reverse_iterator<Iter>	ft::reverse_iterator<Iter>::operator--(int)
{
	ft::reverse_iterator<Iter>	tmp = *this;
	--(*this);
	return (tmp);
}

template <typename Iter>
ft::reverse_iterator<Iter>	ft::reverse_iterator<Iter>::operator+(typename ft::reverse_iterator<Iter>::difference_type n) const
{
	return (ft::reverse_iterator<Iter>(current - n));
}

template <typename Iter>
ft::reverse_iterator<Iter>	ft::reverse_iterator<Iter>::operator-(typename ft::reverse_iterator<Iter>::difference_type n) const
{
	return (ft::reverse_iterator<Iter>(current + n));
}

template <typename Iter>
ft::reverse_iterator<Iter>&	ft::reverse_iterator<Iter>::operator+=(typename ft::reverse_iterator<Iter>::difference_type n)
{
	current -= n;
	return (*this);
}

template <typename Iter>
ft::reverse_iterator<Iter>&	ft::reverse_iterator<Iter>::operator-=(typename ft::reverse_iterator<Iter>::difference_type n)
{
	current += n;
	return (*this);
}

// ************************************************************************** //
//                             Non-member function                            //
// ************************************************************************** //

template <typename Iter>
bool	ft::operator==(const ft::reverse_iterator<Iter>& lhs, const ft::reverse_iterator<Iter>& rhs)
{
	return (lhs.base() == rhs.base());
}

template <typename Iter>
bool	ft::operator!=(const ft::reverse_iterator<Iter>& lhs, const ft::reverse_iterator<Iter>& rhs)
{
	return (lhs.base() != rhs.base());
}

template <typename Iter>
bool	ft::operator<(const ft::reverse_iterator<Iter>& lhs, const ft::reverse_iterator<Iter>& rhs)
{
	return (lhs.base() > rhs.base());
}

template <typename Iter>
bool	ft::operator<=(const ft::reverse_iterator<Iter>& lhs, const ft::reverse_iterator<Iter>& rhs)
{
	return (lhs.base() >= rhs.base());
}

template <typename Iter>
bool	ft::operator>(const ft::reverse_iterator<Iter>& lhs, const ft::reverse_iterator<Iter>& rhs)
{
	return (lhs.base() < rhs.base());
}

template <typename Iter>
bool	ft::operator>=(const ft::reverse_iterator<Iter>& lhs, const ft::reverse_iterator<Iter>& rhs)
{
	return (lhs.base() <= rhs.base());
}

template <typename Iter>
ft::reverse_iterator<Iter>	ft::operator+(typename ft::reverse_iterator<Iter>::difference_type n, const ft::reverse_iterator<Iter>& rit)
{
	return (ft::reverse_iterator<Iter>(rit.base() - n));
}

template <typename Iter>
typename ft::reverse_iterator<Iter>::difference_type	ft::operator-(const ft::reverse_iterator<Iter>& lhs, const ft::reverse_iterator<Iter>& rhs)
{
	return (rhs.base() - lhs.base());
}
