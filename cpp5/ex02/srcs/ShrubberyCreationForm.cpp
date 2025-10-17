/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 06:06:04 by arvoyer           #+#    #+#             */
/*   Updated: 2025/01/10 06:56:17 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("none")
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) : AForm(copy), _target("none")
{
	
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);	
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (this->getIsSigned() == false)
		throw AForm::NotSignedException();

	std::string filename;

	filename = this->_target + "_shrubbery";
	std::ofstream	out(filename.c_str());
	if (out.is_open() == false)
	{
		std::cout << "Can't create the shrubbery outfile" << std::endl;
		return ;
	}

	out << "                                                     .\n"
    		"                                         .         ;\n"
        	"		     .              .              ;%     ;;\n"
            "		       ,           ,                :;%  %;\n"   
            "		        :         ;                   :;%;'     .,\n"   
        	"	   ,.        %;     %;            ;        %;'    ,;\n"
            "		 ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
            "		  %;       %;%;      ,  ;       %;  ;%;   ,%;'\n" 
            "		   ;%;      %;        ;%;        % ;%;  ,%;'\n"
            "		    `%;.     ;%;     %;'         `;%%;.%;'\n"
            "		     `:;%.    ;%%. %@;        %; ;@%;%'\n"
            "		        `:%;.  :;bd%;          %;@%;'\n"
            "		          `@%:.  :;%.         ;@@%;'\n"
            "		            `@%.  `;@%.      ;@@%;\n"    
            "		              `@%%. `@%%    ;@@%;\n"    
            "	   		            ;@%. :@%%  %@@%;\n"   
            "    		              %@bd%%%bd%%:;\n" 
            "        		            #@%%%%%:;;\n"
            "        		            %@@%%%::;\n"
            "            		        %@@@%(o);  . '\n"         
            "            		        %@@@o%;:(.,'\n"         
            "            		    `.. %@@@o%::;\n"         
            "            		       `)@@@o%::;\n"         
            "                		    %@@(o)::;\n"        
            "                		   .%@@@@%::;\n"         
            "                		   ;%@@@@%::;.\n"          
            "                		  ;%@@@@%%:;;;.\n" 
            "            		  ...;%@@@@@%%:;;;;,.. \n";

	out.close();
}