/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 04:18:28 by arvoyer           #+#    #+#             */
/*   Updated: 2025/03/28 14:25:09 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <list>
#include <vector>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <cstring>

typedef std::vector<long int> 	vec_lint;
typedef std::list<long int> 	list_lint;

typedef struct s_pair_v
{
	vec_lint 			p1_value;
	vec_lint::iterator	p2_it;
}	t_pair_v;

typedef struct s_pair_l
{
	list_lint 			p1_value;
	list_lint::iterator	p2_it;
}	t_pair_l;

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(PmergeMe &copy);
		PmergeMe& operator=(const PmergeMe &other);
		~PmergeMe(void);

		void	fill_vector(char **argv);
		void	sort_vector(size_t group_size);
		void	show_vector();
		void	insert_binary_v(vec_lint value, vec_lint::iterator begin, vec_lint::iterator end);

		void	fill_list(char **argv);
		void	sort_list(size_t group_size);
		void	show_list();
		void	insert_binary_l(list_lint value, list_lint::iterator begin, list_lint::iterator end);
	private:
		vec_lint	_vector;
		list_lint	_list;

		class InvalidInput: public std::exception
		{
				virtual const char* what(void) const throw();
		};
};

#endif