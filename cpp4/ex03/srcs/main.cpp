/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:31:54 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/10 15:10:28 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.h"
#include "MateriaSource.h"
#include "Cure.h"
#include "Ice.h"

#include <vector>
#include <iostream>

int	main()
{
	std::vector<AMateria*> ground;

	std::cout << "------------------------Constructor Message------------------------" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	Character *Bob0 = new Character("bob");
	Bob0->equip(src->createMateria("cure"));
    ICharacter *Bob1 = new Character(*Bob0);
	std::cout << "-------------------------------------------------------------------" << std::endl << std::endl;
	
	std::cout << "Subject test:" << std::endl;
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	std::cout << "Unequip test:" << std::endl;
	
	tmp = me->getMateria(1);
	if (tmp)
	{
		ground.push_back(tmp);
		me->unequip(1);
	}
	
	me->use(1, *bob);

	std::cout << "Deep Copy test:" << std::endl;

	Bob0->use(0, *bob);
	delete (Bob0);
	
	std::cout << Bob1->getName() << std::endl;
	Bob1->use(0, *bob);

	std::cout << std::endl << "------------------------Destructor Message-------------------------" << std::endl;
	
	while (!ground.empty())
	{
		tmp = ground.back();
		ground.pop_back();
		if (tmp)
			delete (tmp);
	}

	delete bob;
	delete Bob1;
	delete me;
	delete src;
}