/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:24:53 by heha              #+#    #+#             */
/*   Updated: 2023/03/23 16:40:47 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

// ************************************************************************** //
//                                PmergeMe Class                              //
// ************************************************************************** //

# include <string>

class PmergeMe {

public:
	PmergeMe() throw();
	PmergeMe(const PmergeMe& other) throw();
	PmergeMe& operator=(const PmergeMe& other) throw();
	~PmergeMe() throw();

	static void	execute(const std::string& input);

private:
	template <typename Container>
	static void		_initSequence(Container& sequence, const std::string& input);
	template <typename Container>
	static void		_displaySequence(const Container& sequence);
	template <typename Container>
	static double	_sortSequence(Container& sequence);	// TBD

};

#endif
