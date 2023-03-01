/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:10:56 by heha              #+#    #+#             */
/*   Updated: 2023/02/13 17:26:38 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

template <typename T, typename Allocator>
ft::vector<T, Allocator>::vector(const Allocator& alloc)
	: _allocator(alloc), _begin(NULL), _end(NULL)
{}

template <typename T, typename Allocator>
ft::vector<T, Allocator>::vector(typename ft::vector<T, Allocator>::size_type count, const T& value, const Allocator& alloc)
	: _allocator(alloc), _begin(NULL), _end(NULL)
{
	if (count > 0)
	{
		_allocate(count);
		_construct_at_end(count, value);
	}
}

template <typename T, typename Allocator>
template <typename InputIt>
ft::vector<T, Allocator>::vector(InputIt first, InputIt last, const Allocator& alloc)
	: _allocator(alloc), _begin(NULL), _end(NULL)
{
	for (; __first != __last; ++_first)
	{
		__emplace_back(*__first);
	}
	// Strong guarantee
	_data = _allocator.allocate(?);
}

template <typename T, typename Allocator>
ft::vector<T, Allocator>::vector(const ft::vector<T, Allocator>& other)
	: _allocator(other.get_allocator()), _begin(NULL), _end(NULL)
{
	typename ft::vector<T, Allocator>::size_type	count = other.size();

	if (count > 0)
	{
		_allocate(count);
		_construct_at_end(other._begin, other._end, count);
	}
}

// ************************************************************************** //
//                                 Iterators                                  //
// ************************************************************************** //

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator	ft::vector<T, Allocator>::begin()
{
	return (
			const_cast<typename ft::vector<T, Allocator>::iterator>(
				static_cast<const ft::vector<T, Allocator>&>(
					*this).begin()
				)
		   );
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_iterator	ft::vector<T, Allocator>::begin() const
{
	// No-throw guarantee
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator	ft::vector<T, Allocator>::end()
{
	return (
			const_cast<typename ft::vector<T, Allocator>::iterator>(
				static_cast<const ft::vector<T, Allocator>&>(
					*this).end()
				)
		   );
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_iterator	ft::vector<T, Allocator>::end() const
{
	// No-throw guarantee
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::reverse_iterator	ft::vector<T, Allocator>::rbegin()
{
	return (
			const_cast<typename ft::vector<T, Allocator>::reverse_iterator>(
				static_cast<const ft::vector<T, Allocator>&>(
					*this).rbegin()
				)
		   );
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reverse_iterator	ft::vector<T, Allocator>::rbegin() const
{
	// No-throw guarantee
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::reverse_iterator	ft::vector<T, Allocator>::rend()
{
	return (
			const_cast<typename ft::vector<T, Allocator>::reverse_iterator>(
				static_cast<const ft::vector<T, Allocator>&>(
					*this).rend()
				)
		   );
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reverse_iterator	ft::vector<T, Allocator>::rend() const
{
	// No-throw guarantee
}

// ************************************************************************** //
//                                 Capacity                                   //
// ************************************************************************** //

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::size_type	ft::vector<T, Allocator>::size() const
{
	// No-throw guarantee
	return (std::distance(begin(), end()));	// Replace with ft::distance()
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::size_type	ft::vector<T, Allocator>::max_size() const
{
	return (std::min<typename ft::vector<T, Allocator>::size_type>(
				_allocator.max_size(), std::numeric_limits<typename ft::vector<T, Allocator>::difference_type>::max()));
}

template <typename T, typename Allocator>
void	ft::vector<T, Allocator>::resize(typename ft::vector<T, Allocator>::size_type count, T value)
{
	// More research needed
	if (count > max_size())
		throw std::length_error("ft::vector<T, Allocator>::resize(size_type count, T value) 'count' exceeds maximum supported size");
	if (count < size())
	{
		value_type	*pOrig = _data;

		_data = _allocator.allocate(count);
		_allocator.construct(_data, value);
		_allocator.destroy(pOrig);
		_allocator.deallocate(pOrig, _capacity);
		_capacity = count;
	}
	else
	{
	}
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::size_type	ft::vector<T, Allocator>::capacity() const
{
	return (static_cast<typename ft::vector<T, Allocator>::size_type>(_end - _begin));
}

template <typename T, typename Allocator>
bool	ft::vector<T, Allocator>::empty() const
{
	return (begin() == end());
}

template <typename T, typename Allocator>
void	ft::vector<T, Allocator>::reserve(typename ft::vector<T, Allocator>::size_type new_cap)
{
	// More research needed
	if (new_cap > max_size())
		throw std::length_error("ft::vector<T, Allocator>::reserve(size_type new_cap) 'new_cap' exceeds maximum supported size");
	if (new_cap > capacity())
	{
		value_type	*pOrig = _data;

		_data = _allocator.allocate(new_cap);
		_allocator.deallocate(pOrig, _capacity);
		_capacity = new_cap;
	}
}

// ************************************************************************** //
//                              Element access                                //
// ************************************************************************** //

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::reference	ft::vector<T, Allocator>::operator[](typename ft::vector<T, Allocator>::size_type pos)
{
	return (
			const_cast<typename ft::vector<T, Allocator>::reference>(
				static_cast<const ft::vector<T, Allocator>&>(
					*this)[pos]
				)
		   );
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reference	ft::vector<T, Allocator>::operator[](typename ft::vector<T, Allocator>::size_type pos) const
{
	return (_data[pos]);
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::reference	ft::vector<T, Allocator>::at(typename ft::vector<T, Allocator>::size_type pos)
{
	return (
			const_cast<typename ft::vector<T, Allocator>::reference>(
				static_cast<const ft::vector<T, Allocator>&>(
					*this).at(pos)
				)
		   );
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reference	ft::vector<T, Allocator>::at(typename ft::vector<T, Allocator>::size_type pos) const
{
	if (!(pos < size()))
		throw std::out_of_range("ft::vector");
	return (_data[pos]);
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::reference	ft::vector<T, Allocator>::front()
{
	return (
			const_cast<typename ft::vector<T, Allocator>::reference>(
				static_cast<const ft::vector<T, Allocator>&>(
					*this).front()
				)
		   );
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reference	ft::vector<T, Allocator>::front() const
{
	return (_data[0]);
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::reference	ft::vector<T, Allocator>::back()
{
	return (
			const_cast<typename ft::vector<T, Allocator>::reference>(
				static_cast<const ft::vector<T, Allocator>&>(
					*this).back()
				)
		   );
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reference	ft::vector<T, Allocator>::back() const
{
	return (_data[size() - 1]);
}

template <typename T, typename Allocator>
T	*ft::vector<T, Allocator>::data()
{
	return (
			const_cast<T *>(
				static_cast<const ft::vector<T, Allocator>&>(
					*this).data()
				)
		   );
}

template <typename T, typename Allocator>
const T	*ft::vector<T, Allocator>::data() const
{
	return (_data);
}

// ************************************************************************** //
//                                 Modifiers                                  //
// ************************************************************************** //

template <typename T, typename Allocator>
void	ft::vector<T, Allocator>::assign(typename ft::vector<T, Allocator>::size_type count, const T& value)
{
	// Basic guarantee or undefined behavior
}

template <typename T, typename Allocator>
template <typename InputIt>
void	ft::vector<T, Allocator>::assign(InputIt first, InputIt last)
{
	// Basic guarantee or undefined behavior
}

template <typename T, typename Allocator>
void	ft::vector<T, Allocator>::push_back(const T& value)
{
	// strong guarante or basic guarantee or undefined behavior
}

template <typename T, typename Allocator>
void	ft::vector<T, Allocator>::pop_back()
{
	// no-throw guarantee or undefined behavior
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator	ft::vector<T, Allocator>::insert(typename ft::vector<T, Allocator>::iterator pos, const T& value)
{
	// strong guarantee or basic guarantee or undefined behavior
}

template <typename T, typename Allocator>
void	ft::vector<T, Allocator>::insert(typename ft::vector<T, Allocator>::iterator pos, typename ft::vector<T, Allocator>::size_type count, const T& value)
{
	// strong guarantee or basic guarantee or undefined behavior
}

template <typename T, typename Allocator>
template <typename InputIt>
void	ft::vector<T, Allocator>::insert(typename ft::vector<T, Allocator>::iterator pos, InputIt first, InputIt last)
{
	// strong guarantee or basic guarantee or undefined behavior
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator	ft::vector<T, Allocator>::erase(typename ft::vector<T, Allocator>::iterator pos)
{
	// no-throw guarantee or basic guarantee or undefined behavior
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator	ft::vector<T, Allocator>::erase(typename ft::vector<T, Allocator>::iterator first, typename ft::vector<T, Allocator>::iterator last)
{
	// no-throw guarantee or basic guarantee or undefined behavior
}

template <typename T, typename Allocator>
void	ft::vector<T, Allocator>::swap(ft::vector<T, Allocator>& other)
{
	// no-throw guarantee or undefined behavior
}

template <typename T, typename Allocator>
void	ft::vector<T, Allocator>::clear()
{
	// No-throw guarantee
	for (typename ft::vector<T, Allocator>::iterator it = begin(), typename ft::vector<T, Allocator>::iterator end = end(); it != end; ++it)
	{
		erase(*it);
	}
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
ft::vector<T, Allocator>::~vector()
{
	_allocaotr.destroy(_data);
	_allocator.deallocate(_data, _capacity);
}

template <typename T, typename Allocator>
ft::vector<T, Allocator>&	ft::vector<T, Allocator>::operator=(const ft::vector<T, Allocator>& other)
{
	// Basic guarantee
	if (this != &other)
	{
	}
	return (*this);
}

template <typename T, typename Allocator>
void	ft::vector<T, Allocator>::_allocate(typename ft::vector<T, Allocator>::size_type count)
{
	if (count > max_size())
		throw (std::length_error("ft::vector"));
	_begin = _allocator.allocate(count);
	_end = _begin + count;
}

template <typename T, typename Allocator>
void	ft::vector<T, Allocator>::_construct_at_end(typename ft::vector<T, Allocator>::size_type count, const T& value)
{
	for (typename ft::vector<T, Allocator>::pointer_type pos = _end, typename ft::vector<T, Allocator>::pointer_type new_end = _end + count; pos != end; ++pos)
	{
		_allocator.construct(pos, value);
	}
}

// ************************************************************************** //
//                             Non-member function                            //
// ************************************************************************** //

template <typename T, typename Allocator>
bool	operator==(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	else
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <typename T, typename Allocator>
bool	operator!=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	return (!(lhs == rhs));
}

template <typename T, typename Allocator>
bool	operator<(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <typename T, typename Allocator>
bool	operator<=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	return (!(rhs < lhs));
}

template <typename T, typename Allocator>
bool	operator>(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	return (rhs < lhs);
}

template <typename T, typename Allocator>
bool	operator>=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	return (!(lhs < rhs));
}

template <typename T, typename Allocator>
void	swap(ft::vector<T, Allocator>& lhs, ft::vector<T, Allocator>& rhs)
{
	lhs.swap(rhs);
}
