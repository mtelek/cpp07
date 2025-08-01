/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 23:51:45 by mtelek            #+#    #+#             */
/*   Updated: 2025/08/02 00:52:21 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP

#include <iostream>
#include <string>

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T min(T &a, T &b)
{
	return (a < b ? a : b);
}

template <typename T>
const T max(T &a, T &b)
{
	return (a > b ? a : b);
}

#endif
