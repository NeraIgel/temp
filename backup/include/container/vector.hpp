/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:08:41 by heha              #+#    #+#             */
/*   Updated: 2023/02/13 17:25:15 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

// ************************************************************************** //
//                                vector class                                //
// ************************************************************************** //

# include <limits>
# include <memory>
# include <cstddef>
# include <stdexcept>
# include <iterator>	// Replace with ft::iterator
# include "algorithm.hpp"

namespace ft
{
	template <typename T, typename Allocator = std::allocator<T>>
	class vector {

	public:
		typedef T													value_type;
		typedef Allocator											allocator_type;
		typedef typename allocator_type::reference					reference;			// More research needed
		typedef typename allocator_type::const_reference			const_reference;	// More research needed
		typedef typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer				const_pointer;
		typedef std::random_access_iterator_tag<value_type>			iterator;			// More research needed
		typedef std::random_access_iterator_tag<const value_type>	const_iterator;		// More research needed
		typedef std::reverse_iterator<iterator>						reverse_iterator;	// Replace with ft::iterator
		typedef std::reverse_iterator<const_iterator>				const_reverse_iterator;	// Replace with ft::iterator
		typedef std::ptrdiff_t										difference_type;
		typedef std::size_t											size_type;

		explicit vector(const Allocator& alloc = Allocator());
		explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator());
		template <typename InputIt>	// add template parameter type check
		vector(InputIt first, InputIt last, const Allocator& alloc = Allocator());
		vector(const vector& other);
		vector& operator=(const vector& other);
		~vector();

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
		void					resize(size_type count, T value = T());
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
		T						*data();
		const T					*data() const;

		void					assign(size_type count, const T& value);
		template <typename InputIt>	// add template parameter type check
		void					assign(InputIt first, InputIt last);
		void					push_back(const T& value);
		void					pop_back();
		iterator				insert(iterator pos, const T& value);
		void					insert(iterator pos, size_type count, const T& value);	// More research needed
		template <typename InputIt>	// add template parameter type check
		void					insert(iterator pos, InputIt first, InputIt last);		// More research needed
		iterator				erase(iterator pos);
		iterator				erase(iterator first, iterator last);
		void					swap(vector& other);
		void					clear();

		allocator_type			get_allocator() const;

	private:
		void					_allocate(size_type count);
		void					_construct_at_end(size_type count, const T& value);

		allocator_type			_allocator;
		size_type				_capacity;	// More research needed
		pointer_type			_begin;
		pointer_type			_end;
		size_type				_size;	// More research needed

	};
	
	template <typename T, typename Alloc> bool	operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
	template <typename T, typename Alloc> bool	operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
	template <typename T, typename Alloc> bool	operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
	template <typename T, typename Alloc> bool	operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
	template <typename T, typename Alloc> bool	operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
	template <typename T, typename Alloc> bool	operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

	template <typename T, typename Alloc>
	void	swap(vector<T, Alloc>& lhs, vecotr<T, Alloc>& rhs);	// More research needed
}

# include "vector.tpp"

#endif
