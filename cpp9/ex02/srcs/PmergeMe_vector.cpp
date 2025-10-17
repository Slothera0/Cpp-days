/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_vector.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 05:07:58 by arvoyer           #+#    #+#             */
/*   Updated: 2025/03/28 14:25:29 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::fill_vector(char **argv)
{
	char		*end = NULL;
	long int	nb;

	for (int i = 0; argv[i] != NULL; i++)
	{
		nb = strtol(argv[i], &end, 10);
		if ((*end != '\0' || nb < 0) || !std::strlen(argv[i]))
			throw PmergeMe::InvalidInput();
		this->_vector.push_back(nb);
	}
}

void	PmergeMe::sort_vector(size_t group_size)
{
	for (vec_lint::iterator i = _vector.begin(); i + group_size * 2 <= _vector.end(); i += group_size * 2)
	{
		if (*i > *(i + group_size))
			std::swap_ranges(i, i + group_size, i + group_size);
	}
	if (group_size < _vector.size() / 2)
		sort_vector(group_size * 2);
	
	vec_lint ignored(_vector.end() - (_vector.size() % (group_size * 2)), _vector.end());
	_vector.erase(_vector.end() - (_vector.size() % (group_size * 2)), _vector.end());

	std::vector<t_pair_v> 	unsort;
	int						odd = 0;

	for (vec_lint::iterator i = _vector.begin(); i + group_size <= _vector.end(); )
	{
		if (odd % 2 == 1)
		{
			t_pair_v temp;
			temp.p1_value.insert(temp.p1_value.begin(), i, i + group_size);
			temp.p2_it = i - group_size;
			unsort.push_back(temp);
			_vector.erase(i, i + group_size);
		}
		else
			i += group_size;
		odd++;
	}

	int	current_jacobsthal = 3;
	int	previous_jacobsthal = 1;

	while (unsort.size() != 0)
	{
		size_t	insertion = current_jacobsthal - previous_jacobsthal;
		if (insertion > unsort.size())
			insertion = unsort.size();
		while (insertion != 0)
		{
			this->insert_binary_v(unsort[insertion - 1].p1_value, unsort[insertion - 1].p2_it, _vector.end());
			unsort.erase(unsort.begin() + insertion - 1);
			insertion--;
		}
		int temp = current_jacobsthal + 2 * previous_jacobsthal;
		previous_jacobsthal = current_jacobsthal;
		current_jacobsthal = temp;
	}
	
	current_jacobsthal = 3;
	previous_jacobsthal = 1;
	while (ignored.size() != 0)
	{
		size_t	insertion = current_jacobsthal - previous_jacobsthal;
		if (insertion > ignored.size())
			insertion = ignored.size();
		while (insertion != 0)
		{
			vec_lint	temp_vec(1 , ignored[insertion - 1]);
			ignored.erase(ignored.begin() + insertion - 1);
			this->insert_binary_v(temp_vec, _vector.begin(), _vector.end());
			insertion--;
		}
		int temp = current_jacobsthal + 2 * previous_jacobsthal;
		previous_jacobsthal = current_jacobsthal;
		current_jacobsthal = temp;
	}
}

void	PmergeMe::insert_binary_v(vec_lint value, vec_lint::iterator begin, vec_lint::iterator end)
{
	int	group_size = value.size();
	
	while (begin < end)
	{
		int	nb_group = (end - begin) / group_size;
		vec_lint::iterator middle = begin + (nb_group / 2) * group_size;
		if (*middle < value[0])
			begin = middle + group_size;
		else
			end = middle;
	}
	_vector.insert(begin, value.begin(), value.end());
}

void	PmergeMe::show_vector()
{
	for (vec_lint::iterator i = this->_vector.begin(); i != this->_vector.end(); i++)
		std::cout << *i << " ";
	std::cout << "vector" << std::endl;
}
