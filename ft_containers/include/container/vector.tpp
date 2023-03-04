/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:52:36 by heha              #+#    #+#             */
/*   Updated: 2023/03/04 15:15:18 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

template <typename T, typename Allocator>
ft::vector<T, Allocator>::vector()
	: 
{
}

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
	return (typename ft::vector<T, Allocator>::iterator(this->__begin));
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_iterator	ft::vector<T, Allocator>::begin() const
{
	return (typename ft::vector<T, Allocator>::const_iterator(this->__begin));
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator	ft::vector<T, Allocator>::end()
{
	return (typename ft::vector<T, Allocator>::iterator(this->__end));
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_iterator	ft::vector<T, Allocator>::end() const
{
	return (typename ft::vector<T, Allocator>::const_iterator(this->__end));
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::reverse_iterator	ft::vector<T, Allocator>::rbegin()
{
	return (typename ft::vector<T, Allocator>::reverse_iterator(end()));
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reverse_iterator	ft::vector<T, Allocator>::rbegin() const
{
	return (typename ft::vector<T, Allocator>::const_reverse_iterator(end()));
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::reverse_iterator	ft::vector<T, Allocator>::rend()
{
	return (typename ft::vector<T, Allocator>::reverse_iterator(begin()));
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reverse_iterator	ft::vector<T, Allocator>::rend() const
{
	return (typename ft::vector<T, Allocator>::const_reverse_iterator(begin()));
}

// ************************************************************************** //
//                                 Capacity                                   //
// ************************************************************************** //

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::size_type	ft::vector<T, Allocator>::size() const
{
	return (ft::distance(begin(), end()));
//	return (ft::distance(this->__begin, this->__end));	// TBD
//	return (static_cast<typename ft::vector<T, Allocator>::size_type>(this->__end - this->__begin));	// TBD
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::size_type	ft::vector<T, Allocator>::max_size() const
{
	return (ft::min<typename ft::vector<T, Allocator>::size_type>(
				this->__alloc.max_size(), std::numeric_limits<typename ft::vector<T, Allocator>::difference_type>::max()));
}

template <typename T, typename Allocator>
void	ft::vector<T, Allocator>::resize(typename ft::vector<T, Allocator>::size_type count, typename ft::vector<T, Allocator>::value_type value)
{
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::size_type	ft::vector<T, Allocator>::capacity() const
{
	return (__base::capacity());
//	return (this->capacity());	// TBD
}

template <typename T, typename Allocator>
bool	ft::vector<T, Allocator>::empty() const
{
	return (begin() == end());
//	return (this->__begin == this->__end);	// TBD
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
	return (this->__begin[pos]);
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reference	ft::vector<T, Allocator>::operator[](typename ft::vector<T, Allocator>::size_type pos) const
{
	return (this->__begin[pos]);
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::reference	ft::vector<T, Allocator>::at(typename ft::vector<T, Allocator>::size_type pos)
{
	if (!(pos < size()))
		throw std::out_of_range("ft::vector");	// TBD (__vector_base? __vector_base_common?)
	return (this->__begin[pos]);
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reference	ft::vector<T, Allocator>::at(typename ft::vector<T, Allocator>::size_type pos) const
{
	if (!(pos < size()))
		throw std::out_of_range("ft::vector");	// TBD (__vector_base? __vector_base_common?)
	return (this->__begin[pos]);
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::reference	ft::vector<T, Allocator>::front()
{
	return (*(this->__begin));
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reference	ft::vector<T, Allocator>::front() const
{
	return (*(this->__begin));
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::reference	ft::vector<T, Allocator>::back()
{
	return (*(this->__end - 1));
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reference	ft::vector<T, Allocator>::back() const
{
	return (*(this->__end - 1));
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::value_type	*ft::vector<T, Allocator>::data()
{
	return (this->__begin);
}

template <typename T, typename Allocator>
const typename ft::vector<T, Allocator>::value_type	*ft::vector<T, Allocator>::data() const
{
	return (this->__begin);
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
	return (typename ft::vector<T, Allocator>::allocator_type(this->__allocator));
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
inline
bool	ft::operator==(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	return (lhs.size() == rhs.size() &&
			ft::equal(lhs.begin(), lhs.end(), rhs.begin()));	// TBD (check if size_type member type exists?)
}

template <typename T, typename Allocator>
inline
bool	ft::operator!=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	return (!(lhs == rhs));
}

template <typename T, typename Allocator>
inline
bool	ft::operator<(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <typename T, typename Allocator>
inline
bool	ft::operator<=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	return (!(rhs < lhs));
}

template <typename T, typename Allocator>
inline
bool	ft::operator>(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	return (rhs < lhs);
}

template <typename T, typename Allocator>
inline
bool	ft::operator>=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	return (!(lhs < rhs));
}

template <typename T, typename Allocator>
inline
void	ft::swap(ft::vector<T, Allocator>& lhs, ft::vector<T, Allocator>& rhs)
{
	lhs.swap(rhs);
}
