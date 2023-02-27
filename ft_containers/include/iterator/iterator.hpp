/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:59:36 by heha              #+#    #+#             */
/*   Updated: 2023/02/27 19:20:08 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FT_ITERATOR_HPP
# define FT_ITERATOR_HPP

# include <cstddef>
# include "type_traits.hpp"

namespace ft
{
// For compatibility with the std::iterator_tag used by some std::algorithm functions
#if defined(_ITERATOR_) || defined(_LIBCPP_ITERATOR) || defined(__GLIBCPP_INTERNAL_ITERATOR_H)
	typedef std::input_iterator_tag				input_iterator_tag;
	typedef std::output_iterator_tag			output_iterator_tag;
	typedef std::forward_iterator_tag			forward_iterator_tag;
	typedef std::bidirectional_iterator_tag		bidirectional_iterator_tag;
	typedef std::random_access_iterator_tag		random_access_iterator_tag;
#else
	struct input_iterator_tag												{};
	struct output_iterator_tag												{};
	struct forward_iterator_tag			: public input_iterator_tag			{};
	struct bidirectional_iterator_tag	: public forward_iterator_tag		{};
	struct random_access_iterator_tag	: public bidirectional_iterator_tag	{};
#endif

	template <typename Category, typename T, typename Distance = std::ptrdiff_t, typename Pointer = T*, typename Reference = T&>
	struct iterator {
		typedef Category							iterator_category;
		typedef T									value_type;
		typedef Distance							difference_type;
		typedef Pointer								pointer;
		typedef Reference							reference;
	};

	template <typename Iter>	// TBD
	struct iterator_traits {
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};

	template <typename T>
	struct iterator_traits<T *> {
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef random_access_iterator_tag			iterator_category;
	};

	template <typename T>
	struct iterator_traits<const T *> {
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef const T*							pointer;
		typedef const T&							reference;
		typedef random_access_iterator_tag			iterator_category;
	};

	template <typename Iter>
	class reverse_iterator : public iterator<
							typename iterator_traits<Iter>::iterator_category,
							typename iterator_traits<Iter>::value_type,
							typename iterator_traits<Iter>::difference_type,
							typename iterator_traits<Iter>::pointer,
							typename iterator_traits<Iter>::reference> {
	
	public:
		typedef Iter												iterator_type;
		typedef typename iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iter>::value_type			value_type;
		typedef typename iterator_traits<Iter>::difference_type		difference_type;
		typedef typename iterator_traits<Iter>::pointer				pointer;
		typedef typename iterator_traits<Iter>::reference			reference;

		reverse_iterator();
		explicit reverse_iterator(iterator_type it);
		template <typename U>
		reverse_iterator(const reverse_iterator<U>& other);
		template <typename U>
		reverse_iterator& operator=(const reverse_iterator<U>& other);

		iterator_type		base() const;
		reference			operator*() const;
		pointer				operator->() const;
		reference			operator[](difference_type n) const;
		reverse_iterator&	operator++();
		reverse_iterator&	operator--();
		reverse_iterator	operator++(int);
		reverse_iterator	operator--(int);
		reverse_iterator	operator+(difference_type n) const;
		reverse_iterator	operator-(difference_type n) const;
		reverse_iterator&	operator+=(difference_type n);
		reverse_iterator&	operator-=(difference_type n);

	protected:
		iterator_type		current;

	};

	template <typename Iter> bool	operator==(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);
	template <typename Iter> bool	operator!=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);
	template <typename Iter> bool	operator<(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);
	template <typename Iter> bool	operator<=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);
	template <typename Iter> bool	operator>(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);
	template <typename Iter> bool	operator>=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);

	template <typename Iter>
	reverse_iterator<Iter>	operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& rit);
	template <typename Iter>
	typename reverse_iterator<Iter>::difference_type	operator-(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);

	template <typename InputIt>
	void	__advance(InputIt& it, typename iterator_traits<InputIt>::difference_type n, input_iterator_tag);
	template <typename BidirIt>
	void	__advance(BidirIt& it, typename iterator_traits<BidirIt>::difference_type n, bidirectional_iterator_tag);
	template <typename RandIt>
	void	__advance(RandIt& it, typename iterator_traits<RandIt>::difference_type n, random_access_iterator_tag);
	template <typename InputIt, typename Distance>
	void	advance(InputIt& it, Distance n);

	template <typename InputIt>
	typename iterator_traits<InputIt>::difference_type	__distance(InputIt first, InputIt last, input_iterator_tag);
	template <typename RandIt>
	typename iterator_traits<RandIt>::difference_type	__distance(RandIt first, RandIt last, random_access_iterator_tag);
	template <typename InputIt>
	typename iterator_traits<InputIt>::difference_type	distance(InputIt first, InputIt last);

	// __libft_has_iterator_category
	template <typename Iter>
	struct __libft_has_iterator_category {
	private:
		struct __two { char __lx; char __lxx; };
		template <typename U> static __two	__test(...);
		template <typename U> static char	__test(typename U::iterator_category* = 0);
	public:
		static const bool	value = sizeof(__test<Iter>(0)) == 1;
	};

	// __libft_has_iterator_category_convertible_to_input_iterator
	template <typename Iter, bool = __libft_has_iterator_category<iterator_traits<Iter> >::value>
	struct __libft_has_iterator_category_convertible_to_input_iterator
		: public integral_constant<bool,
			__libft_is_same<typename iterator_traits<Iter>::iterator_category, input_iterator_tag>::value ||
			 __libft_is_same<typename iterator_traits<Iter>::iterator_category, forward_iterator_tag>::value ||
			 __libft_is_same<typename iterator_traits<Iter>::iterator_category, bidirectional_iterator_tag>::value ||
			 __libft_is_same<typename iterator_traits<Iter>::iterator_category, random_access_iterator_tag>::value> {};
	template <typename Iter>
	struct __libft_has_iterator_category_convertible_to_input_iterator<Iter, false>
		: public false_type {};

	// __libft_has_iterator_category_convertible_to_forward_iterator
	template <typename Iter, bool = __libft_has_iterator_category<iterator_traits<Iter> >::value>
	struct __libft_has_iterator_category_convertible_to_forward_iterator
		: public integral_constant<bool,
			__libft_is_same<typename iterator_traits<Iter>::iterator_category, forward_iterator_tag>::value ||
			 __libft_is_same<typename iterator_traits<Iter>::iterator_category, bidirectional_iterator_tag>::value ||
			 __libft_is_same<typename iterator_traits<Iter>::iterator_category, random_access_iterator_tag>::value> {};
	template <typename Iter>
	struct __libft_has_iterator_category_convertible_to_forward_iterator<Iter, false>
		: public false_type {};

	// __libft_has_iterator_category_convertible_to_bidirectional_iterator
	template <typename Iter, bool = __libft_has_iterator_category<iterator_traits<Iter> >::value>
	struct __libft_has_iterator_category_convertible_to_bidirectional_iterator
		: public integral_constant<bool,
			__libft_is_same<typename iterator_traits<Iter>::iterator_category, bidirectional_iterator_tag>::value ||
			 __libft_is_same<typename iterator_traits<Iter>::iterator_category, random_access_iterator_tag>::value> {};
	template <typename Iter>
	struct __libft_has_iterator_category_convertible_to_bidirectional_iterator<Iter, false>
		: public false_type {};

	// __libft_has_iterator_category_convertible_to_random_access_iterator
	template <typename Iter, bool = __libft_has_iterator_category<iterator_traits<Iter> >::value>
	struct __libft_has_iterator_category_convertible_to_random_access_iterator
		: public integral_constant<bool,
			__libft_is_same<typename iterator_traits<Iter>::iterator_category, random_access_iterator_tag>::value> {};
	template <typename Iter>
	struct __libft_has_iterator_category_convertible_to_random_access_iterator<Iter, false>
		: public false_type {};

	// __libft_has_iterator_category_convertible_to_output_iterator
	template <typename Iter, bool = __libft_has_iterator_category<iterator_traits<Iter> >::value>
	struct __libft_has_iterator_category_convertible_to_output_iterator
		: public integral_constant<bool,
			__libft_is_same<typename iterator_traits<Iter>::iterator_category, output_iterator_tag>::value> {};
	template <typename Iter>
	struct __libft_has_iterator_category_convertible_to_output_iterator<Iter, false>
		: public false_type {};

	// __libft_is_iterator
	template <typename Iter, bool = __libft_has_iterator_category<iterator_traits<Iter> >::value>
	struct __libft_is_iterator
		: public true_type {};
	template <typename Iter>
	struct __libft_is_iterator<Iter, false>
		: public false_type {};

	// __libft_is_(x)_iterator
	template <typename Iter> struct __libft_is_input_iterator : public __libft_has_iterator_category_convertible_to_input_iterator<Iter> {};
	template <typename Iter> struct __libft_is_output_iterator : public __libft_has_iterator_category_convertible_to_output_iterator<Iter> {};
	template <typename Iter> struct __libft_is_forward_iterator : public __libft_has_iterator_category_convertible_to_forward_iterator<Iter> {};
	template <typename Iter> struct __libft_is_bidirectional_iterator : public __libft_has_iterator_category_convertible_to_bidirectional_iterator<Iter> {};
	template <typename Iter> struct __libft_is_random_access_iterator : public __libft_has_iterator_category_convertible_to_random_access_iterator<Iter> {};
}

# include "iterator.tpp"
# include "reverse_iterator.tpp"

#endif
