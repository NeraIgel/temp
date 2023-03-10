/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:01:57 by heha              #+#    #+#             */
/*   Updated: 2023/02/15 18:09:57 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

template <typename T, T v>
ft::integral_constant<T, v>::operator T() const throw()
{
	return (value);
}
