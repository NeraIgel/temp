/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:16:34 by heha              #+#    #+#             */
/*   Updated: 2023/03/04 15:19:35 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <limits>
# include <memory>
# include <stdexcept>	// TBD (__vector_base? __vector_base_common?)
# include "algorithm.hpp"
# include "__vector_base.hpp"
# include "__vector_iterator.hpp"

// ************************************************************************** //
//                            vector class template                           //
// ************************************************************************** //

namespace ft
{
	template <typename T, typename Allocator = std::allocator<T> >
	class vector : private __vector_base<T, Allocator> {
	
	private:
		typedef __vector_base<T, Allocator>								__base;	// TBD (delete?)
	
	public:
		typedef T														value_type;
		typedef Allocator												allocator_type;
		typedef typename __base::reference								reference;
		typedef typename __base::const_reference						const_reference;
		typedef typename __base::pointer								pointer;
		typedef typename __base::const_pointer							const_pointer;
		typedef __vector_iterator<pointer>								iterator;
		typedef __vector_iterator<const_pointer>						const_iterator;
		typedef reverse_iterator<iterator>								reverse_iterator;
		typedef reverse_iterator<const_iterator>						const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type		difference_type;
		typedef typename __base::size_type								size_type;

		vector();
		explicit vector(const allocator_type& alloc);
		explicit vector(size_type count, const value_type& value = value_type(), const allocator_type& alloc = allocator_type());
		template <typename InputIt>
		vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type());	// TBD (SFINAE for template parameter)
		vector(const vector& other);
		vector& operator=(const vector& other);
		~vector();	// throw()

		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

		size_type				size() const;
		size_type				max_size() const;
		void					resize(size_type count, value_type value = value_type());
		size_type				capacity() const;
		bool					empty() const;
		void					reserve(size_type new_cap);

		reference				operator[](size_type pos);
		const_reference			operator[](size_type pos) const;
		reference				at(size_type pos);
		const_reference			at(size_type pos) const;
		reference				front();
		const_reference			front() const;
		reference				back();
		const_reference			back() const;
		value_type				*data();
		const value_type		*data() const;

		void					assign(size_type count, const value_type& value);
		template <typename InputIt>
		void					assign(InputIt first, InputIt last);	// TBD (SFINAE for template parameter)
		void					push_back(const value_type& value);
		void					pop_back();
		iterator				insert(iterator pos, const value_type& value);
		void					insert(iterator pos, size_type count, const value_type& value);
		template <typename InputIt>
		void					insert(iterator pos, InputIt first, InputIt last);	// TBD (SFINAE for template parameter)
		iterator				erase(iterator pos);
		iterator				erase(iterator first, iterator last);
		void					swap(vector& other);
		void					clear();	// throw()

		allocator_type			get_allocator() const;

	private:

	};

	template <typename T, typename Allocator> inline bool	operator==(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs);
	template <typename T, typename Allocator> inline bool	operator!=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs);
	template <typename T, typename Allocator> inline bool	operator<(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs);
	template <typename T, typename Allocator> inline bool	operator<=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs);
	template <typename T, typename Allocator> inline bool	operator>(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs);
	template <typename T, typename Allocator> inline bool	operator>=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs);

	template <typename T, typename Allocator> inline
	void	swap(vector<T, Allocator>& lhs, vector<T, Allocator>& rhs);
}

# include "vector.tpp"

#endif
