/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:52:36 by heha              #+#    #+#             */
/*   Updated: 2023/02/24 17:19:49 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

template <typename T, typename Allocator>
ft::vector<T, Allocator>::vector(const typename ft::vector<T, Allocator>::allocator_type& alloc)
	: 
{
}

template <typename T, typename Allocator>
ft::vector<T, Allocator>::vector(typename ft::vector<T, Allocator>::size_type count, const typename ft::vector<T, Allocator>::value_type& value, const typename ft::vector<T, Allocator>::allocator_type& alloc)
	: 
{
}

template <typename T, typename Allocator>
template <typename InputIt>
ft::vector<T, Allocator>::vector(InputIt first, InputIt last, const typename ft::vector<T, Allocator>::allocator_type& alloc)
	: 
{
}

template <typename T, typename Allocator>
ft::vector<T, Allocator>::vector(const ft::vector<T, Allocator>& other)
	: 
{
}

// ************************************************************************** //
//                                 Iterators                                  //
// ************************************************************************** //

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator	ft::vector<T, Allocator>::begin()
{
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_iterator	ft::vector<T, Allocator>::begin() const
{
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator	ft::vector<T, Allocator>::end()
{
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_iterator	ft::vector<T, Allocator>::end() const
{
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::reverse_iterator	ft::vector<T, Allocator>::rbegin()
{
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reverse_iterator	ft::vector<T, Allocator>::rbegin() const
{
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::reverse_iterator	ft::vector<T, Allocator>::rend()
{
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reverse_iterator	ft::vector<T, Allocator>::rend() const
{
}

// ************************************************************************** //
//                                 Capacity                                   //
// ************************************************************************** //

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::size_type	ft::vector<T, Allocator>::size() const
{
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::size_type	ft::vector<T, Allocator>::max_size() const
{
}

template <typename T, typename Allocator>
void	ft::vector<T, Allocator>::resize(typename ft::vector<T, Allocator>::size_type count, typename ft::vector<T, Allocator>::value_type value)
{
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::size_type	ft::vector<T, Allocator>::capacity() const
{
}

template <typename T, typename Allocator>
bool	ft::vector<T, Allocator>::empty() const
{
}

template <typename T, typename Allocator>
void	ft::vector<T, Allocator>::reserve(typename ft::vector<T, Allocator>::size_type new_cap)
{
}

// ************************************************************************** //
//                              Element access                                //
// ************************************************************************** //

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::reference	ft::vector<T, Allocator>::operator[](typename ft::vector<T, Allocator>::size_type pos)
{
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reference	ft::vector<T, Allocator>::operator[](typename ft::vector<T, Allocator>::size_type pos) const
{
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::reference	ft::vector<T, Allocator>::at(typename ft::vector<T, Allocator>::size_type pos)
{
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reference	ft::vector<T, Allocator>::at(typename ft::vector<T, Allocator>::size_type pos) const
{
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::reference	ft::vector<T, Allocator>::front()
{
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reference	ft::vector<T, Allocator>::front() const
{
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::reference	ft::vector<T, Allocator>::back()
{
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reference	ft::vector<T, Allocator>::back() const
{
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::value_type	*ft::vector<T, Allocator>::data()
{
	return (
			const_cast<typename ft::vector<T, Allocator>::value_type *>(
				static_cast<const ft::vector<T, Allocator>&>(
					*this).data()
				)
		   );
}

template <typename T, typename Allocator>
const typename ft::vector<T, Allocator>::value_type	*ft::vector<T, Allocator>::data() const
{
}

// ************************************************************************** //
//                                 Modifiers                                  //
// ************************************************************************** //

template <typename T, typename Allocator>
void	ft::vector<T, Allocator>::assign(typename ft::vector<T, Allocator>::size_type count, const typename ft::vector<T, Allocator>::value_type& value)
{
}

template <typename T, typename Allocator>
template <typename InputIt>
void	ft::vector<T, Allocator>::assign(InputIt first, InputIt last)
{
}

template <typename T, typename Allocator>
void	ft::vector<T, Allocator>::push_back(const typename ft::vector<T, Allocator>::value_type& value)
{
}

template <typename T, typename Allocator>
void	ft::vector<T, Allocator>::pop_back()
{
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator	ft::vector<T, Allocator>::insert(typename ft::vector<T, Allocator>::iterator pos, const typename ft::vector<T, Allocator>::value_type& value)
{
}

template <typename T, typename Allocator>
void	ft::vector<T, Allocator>::insert(typename ft::vector<T, Allocator>::iterator pos, typename ft::vector<T, Allocator>::size_type count, const typename ft::vector<T, Allocator>::value_type& value)
{
}

template <typename T, typename Allocator>
template <typename InputIt>
void	ft::vector<T, Allocator>::insert(typename ft::vector<T, Allocator>::iterator pos, InputIt first, InputIt last)
{
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator	ft::vector<T, Allocator>::erase(typename ft::vector<T, Allocator>::iterator pos)
{
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator	ft::vector<T, Allocator>::erase(typename ft::vector<T, Allocator>::iterator first, typename ft::vector<T, Allocator>::iterator last)
{
}

template <typename T, typename Allocator>
void	ft::vector<T, Allocator>::swap(ft::vector<T, Allocator>& other)
{
}

template <typename T, typename Allocator>
void	ft::vector<T, Allocator>::clear()
{
}

// ************************************************************************** //
//                                 Allocator                                  //
// ************************************************************************** //

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::allocator_type	ft::vector<T, Allocator>::get_allocator() const
{
	return (_allocator);
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

template <typename T, typename Allocator>
ft::vector<T, Allocator>&	ft::vector<T, Allocator>::operator=(const ft::vector<T, Allocator>& other)
{
}

template <typename T, typename Allocator>
ft::vector<T, Allocator>::~vector()
{
}

// ************************************************************************** //
//                             Non-member function                            //
// ************************************************************************** //

template <typename T, typename Allocator>
bool	ft::operator==(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	const typename ft::vector<T, Allocator>::size_type	size = lhs.size();	// TBD
	return (size == rhs.size() &&
			ft_equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <typename T, typename Allocator>
bool	ft::operator!=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	return (!(lhs == rhs));
}

template <typename T, typename Allocator>
bool	ft::operator<(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <typename T, typename Allocator>
bool	ft::operator<=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	return (!(rhs < lhs));
}

template <typename T, typename Allocator>
bool	ft::operator>(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	return (rhs < lhs);
}

template <typename T, typename Allocator>
bool	ft::operator>=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	return (!(lhs < rhs));
}

template <typename T, typename Allocator>
void	ft::swap(ft::vector<T, Allocator>& lhs, ft::vector<T, Allocator>& rhs)
{
	lhs.swap(rhs);
}
