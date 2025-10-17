/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_list.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 05:08:27 by arvoyer           #+#    #+#             */
/*   Updated: 2025/03/28 14:25:45 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::fill_list(char **argv)
{
	char		*end = NULL;
	long int	nb;

	for (int i = 0; argv[i] != NULL; i++)
	{
		nb = strtol(argv[i], &end, 10);
		if ((*end != '\0' || nb < 0) || !std::strlen(argv[i]))
			throw PmergeMe::InvalidInput();
		this->_list.push_back(nb);
	}
}

void PmergeMe::sort_list(size_t group_size)
{
    for (list_lint::iterator i = _list.begin(); i != _list.end(); )
    {
        list_lint::iterator j = i;
        size_t count = 0;
        while (count < group_size * 2 && j != _list.end()) {
            ++j;
            ++count;
        }

        if (count == group_size * 2) {
            list_lint::iterator first1 = i;
            list_lint::iterator first2 = i;
            for (size_t k = 0; k < group_size; ++k) ++first2;

            for (size_t k = 0; k < group_size; ++k) {
                std::swap(*first1, *first2);
                ++first1;
                ++first2;
            }
        }

		for (size_t k = 0; k < group_size * 2 && i != _list.end(); k++)
			i++;
    }
	
    if (group_size < _list.size() / 2)
        sort_list(group_size * 2);

    list_lint::iterator ignored_start = _list.end();
    size_t ignored_size = _list.size() % (group_size * 2);
    if (ignored_size > 0) {
        for (size_t i = 0; i < ignored_size; ++i)
            --ignored_start;
    }

    list_lint ignored(ignored_start, _list.end());
    _list.erase(ignored_start, _list.end());

    std::list<t_pair_l> unsort;
    int odd = 0;

    for (list_lint::iterator i = _list.begin(); i != _list.end(); )
    {
        list_lint::iterator j = i;
        size_t count = 0;
        while (count < group_size && j != _list.end()) {
            ++j;
            ++count;
        }

        if (count == group_size && odd % 2 == 1)
        {
            t_pair_l temp;
            temp.p1_value.insert(temp.p1_value.begin(), i, j);
            
            list_lint::iterator temp_it = i;
            for (size_t k = 0; k < group_size; ++k) {
                if (temp_it == _list.begin()) break;
                --temp_it;
            }
            temp.p2_it = temp_it;

            unsort.push_back(temp);
            i = _list.erase(i, j);
        }
        else {
            std::advance(i, group_size);
        }
        odd++;
    }

    int current_jacobsthal = 3;
    int previous_jacobsthal = 1;

    while (!unsort.empty())
    {
        size_t insertion = current_jacobsthal - previous_jacobsthal;
        if (insertion > unsort.size())
            insertion = unsort.size();

        while (insertion != 0)
        {
            std::list<t_pair_l>::iterator it = unsort.begin();
            for (size_t i = 0; i < insertion - 1; ++i) ++it;

            this->insert_binary_l(it->p1_value, it->p2_it, _list.end());
            unsort.erase(it);
            insertion--;
        }

        int temp = current_jacobsthal + 2 * previous_jacobsthal;
        previous_jacobsthal = current_jacobsthal;
        current_jacobsthal = temp;
    }

    current_jacobsthal = 3;
    previous_jacobsthal = 1;

    while (!ignored.empty())
    {
        size_t insertion = current_jacobsthal - previous_jacobsthal;
        if (insertion > ignored.size())
            insertion = ignored.size();

        while (insertion != 0)
        {   
            list_lint::iterator i = ignored.begin();
            for (size_t inc = 0; inc < insertion - 1; inc++)
                i++;
            list_lint temp_vec(1, *i);
            ignored.erase(i);
            this->insert_binary_l(temp_vec, _list.begin(), _list.end());
            insertion--;
        }

        int temp = current_jacobsthal + 2 * previous_jacobsthal;
        previous_jacobsthal = current_jacobsthal;
        current_jacobsthal = temp;

    }
    list_lint::iterator sw = _list.begin();
    ++sw;
    if (_list.size() > 1 && *_list.begin() > *sw)
        std::swap(*_list.begin(), *sw);
}

void PmergeMe::insert_binary_l(list_lint value, list_lint::iterator begin, list_lint::iterator end)
{
    int group_size = value.size();

    while (begin != end)
    {
        list_lint::iterator middle = begin;
        int nb_group = 0;

        for (list_lint::iterator it = begin; it != end; )
        {
            nb_group++;
            for (int i = 0; i < group_size && it != end; ++i)
                ++it;
        }

        for (int i = 0; i < (nb_group / 2) * group_size && middle != end; ++i)
            ++middle;

        if (*middle < value.front())
        {
            while (begin != middle)
                ++begin;

            for (int i = 0; i < group_size && begin != end; ++i)
                ++begin;
        }
        else
            end = middle;
    }

    _list.insert(begin, value.begin(), value.end());
}

void	PmergeMe::show_list()
{
	for (list_lint::iterator i = this->_list.begin(); i != this->_list.end(); i++)
		std::cout << *i << " ";
	std::cout << "list" << std::endl;
}
