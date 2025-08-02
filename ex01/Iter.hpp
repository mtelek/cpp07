/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:49:15 by mtelek            #+#    #+#             */
/*   Updated: 2025/08/02 14:51:42 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void iter(T *array, size_t l, void (*func)(T&))
{
	size_t i = 0;
	while(i < l)
		func(array[i++]);
}

template <typename T>
void iter(const T *array, size_t l, void (*func)(const T&))
{
	size_t i = 0;
	while(i < l)
		func(array[i++]);
}

#endif
