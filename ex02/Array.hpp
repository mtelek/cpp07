/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:58:08 by mtelek            #+#    #+#             */
/*   Updated: 2025/08/02 16:33:40 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>
#include <string>

template <class T>
class Array
{
	private:
		T* _elements;
		unsigned int _size;

	public:
		Array() : _elements(NULL), _size(0) {}
		Array(unsigned int n) : _size(n)
		{
			_elements = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
				_elements[i] = T();
		}

		Array(const Array &other) : _size(other._size)
		{
			_elements = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
				_elements[i] = other._elements[i];
		}

		Array &operator=(const Array &other)
		{
			if (this != &other)
			{
				delete[] _elements;
				_size = other._size;
				_elements = new T[_size];
				for (unsigned int i = 0; i < _size; ++i)
					_elements[i] = other._elements[i];
			}
			return (*this);
		}
		~Array()
		{
			delete[] _elements;
		}

		T &operator[](unsigned int index)
		{
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return (_elements[index]);
		}

		const T &operator[](unsigned int index) const
		{
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return (_elements[index]);
		}

		unsigned int size() const
		{
			return (_size);
		}
};

#endif
