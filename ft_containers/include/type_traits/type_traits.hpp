/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:32:23 by heha              #+#    #+#             */
/*   Updated: 2023/02/21 12:58:14 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FT_TYPE_TRAITS_HPP
# define FT_TYPE_TRAITS_HPP

namespace ft
{
	template <bool Cond, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T> {
		typedef T	type;
	};

	template <typename T, T v>
	struct integral_constant {
		static const T					value = v;
		typedef T						value_type;
		typedef integral_constant<T, v>	type;
		operator T() const throw();
	};
	typedef integral_constant<bool, true>	true_type;
	typedef integral_constant<bool, false>	false_type;

	template <typename T> struct __libft_is_integral			: public false_type {};
	template <> struct __libft_is_integral<bool>				: public true_type {};
	template <> struct __libft_is_integral<char>				: public true_type {};
	template <> struct __libft_is_integral<wchar_t>				: public true_type {};
	template <> struct __libft_is_integral<signed char>			: public true_type {};
	template <> struct __libft_is_integral<short int>			: public true_type {};
	template <> struct __libft_is_integral<int>					: public true_type {};
	template <> struct __libft_is_integral<long int>			: public true_type {};
	template <> struct __libft_is_integral<unsigned char>		: public true_type {};
	template <> struct __libft_is_integral<unsigned short int>	: public true_type {};
	template <> struct __libft_is_integral<unsigned int>		: public true_type {};
	template <> struct __libft_is_integral<unsigned long int>	: public true_type {};

	template <typename T> struct remove_cv						{ typedef T type; };
	template <typename T> struct remove_cv<const T>				{ typedef T type; };
	template <typename T> struct remove_cv<volatile T>			{ typedef T type; };
	template <typename T> struct remove_cv<const volatile T>	{ typedef T type; };

	template <typename T> struct remove_const					{ typedef T type; };
	template <typename T> struct remove_const<const T>			{ typedef T type; };

	template <typename T> struct remove_volatile				{ typedef T type; };
	template <typename T> struct remove_volatile<volatile T>	{ typedef T type; };

	template <typename T>
	struct is_integral : public __libft_is_integral<typename remove_cv<T>::type> {};
}

# include "type_traits.tpp"

#endif
