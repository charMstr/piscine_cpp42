/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MindOpen.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 01:16:54 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/21 09:38:37 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "MindOpen.hpp"
#include <fstream>
#include <iostream>
#include "Instructions.hpp"
#include "Inst_dataPtrInc.hpp"
#include "Inst_dataPtrDec.hpp"
#include "Inst_dataInc.hpp"
#include "Inst_dataDec.hpp"
#include "Inst_dataPrint.hpp"
#include "Inst_instPtrFwdJump.hpp"

MindOpen::MindOpen(std::ifstream &input_file)
{
	load_instructions(input_file);
	_inst_ptr = _instructions.begin();
	_data = std::vector<char>(30000);
	_data_ptr = _data.begin();
	//std::cout << "\033[33mconstructor called for MindOpen\033[0m" << std::endl;
	return ;
}

void 
MindOpen::load_instructions(std::ifstream &input_file)
{
	char c = input_file.get();

	while (input_file.good())
	{
		std::cout << c;
		if (c == '>')
			_instructions.push_back(new Inst_dataPtrInc);	
		else if (c == '<')
			_instructions.push_back(new Inst_dataPtrDec);	
		else if (c == '+')
			_instructions.push_back(new Inst_dataInc);	
		else if (c == '-')
			_instructions.push_back(new Inst_dataDec);	
		else if (c == 'w')
			_instructions.push_back(new Inst_dataPrint);	
		else if (c == '[')
			_instructions.push_back(new Inst_instPtrFwdJump);
		else if (c == ']')
			_instructions.push_back(new Inst_instPtrBackJump);
		c = input_file.get();
	}
}

MindOpen::~MindOpen(void)
{
	//std::cout << "\033[31m[~]\033[33mdestructor called for MindOpen\033[0m" << std::endl;
	std::deque<Instructions*>::iterator it = _instructions.begin();
	while (it != _instructions.end())
	{
		delete *it;	
		it++;
	}
	return ;
}

MindOpen::MindOpen(MindOpen const &src)
{
	//std::cout << "\033[33m[COPY]constructor called for MindOpen\033[0m" << std::endl;
	*this = src;
	return ;
}

MindOpen	&
MindOpen::operator=(MindOpen const &rhs)
{
	//std::cout << "\033[33m'=' operator called for MindOpen\033[0m" << std::endl;
	if (this != &rhs)
	{
		;//put code here
	}
	return *this;
}


/*
** we avoid the underflow here, returning 0 when we cannot go back anymore
*/

int 
MindOpen::dec_instPtr(void)
{ 
	if (_inst_ptr == _instructions.begin())
		return (0);
	--_inst_ptr;	
	return (1);
}

/*
** we avoid overflow of instructions deque here. returning zero when we
** cannot increment the pointer any further.
*/

int
MindOpen::inc_instPtr(void)
{
	++_inst_ptr;	
	if (_inst_ptr == _instructions.end())
		return (0);
	return (1);
}

std::deque<Instructions*>::iterator
MindOpen::get_instPtr(void)
{
	return (_inst_ptr);	
}

std::deque<Instructions *> &
MindOpen::get_inst(void)
{
	return (_instructions);	
}

std::vector<char>::iterator &
MindOpen::get_dataPtr(void)
{
	return (_data_ptr);
}

void
MindOpen::debug_instructions(void)
{
	std::deque<Instructions*>::iterator tmp = _inst_ptr;
	std::cout << std::endl << "debuging list of instructions:" << std::endl;
	while (_inst_ptr != _instructions.end())
	{
		debug_next_instruction();
		++_inst_ptr;
	}
	_inst_ptr = tmp;
}

void
MindOpen::debug_next_instruction(void)
{
	std::cout << "\033[34m";
	if (dynamic_cast<Inst_dataDec*>(*_inst_ptr))
		std::cout << "'-' ==> --Data" << std::endl;
	else if (dynamic_cast<Inst_dataInc*>(*_inst_ptr))
		std::cout << "'+' ==> ++Data" << std::endl;
	else if (dynamic_cast<Inst_dataPtrDec*>(*_inst_ptr))
		std::cout << "'<' ==> --pointer" << std::endl;
	else if (dynamic_cast<Inst_dataPtrInc*>(*_inst_ptr))
		std::cout << "'>' ==> ++pointer" << std::endl;
	else if (dynamic_cast<Inst_instPtrFwdJump*>(*_inst_ptr))
		std::cout << "'[' ==> if !Data, go to ']'" << std::endl;
	else if (dynamic_cast<Inst_instPtrBackJump*>(*_inst_ptr))
		std::cout << "']' ==> if Data != 0, go back to '['" << std::endl;
	else if (dynamic_cast<Inst_dataPrint*>(*_inst_ptr))
		std::cout << "'w' ==> Print data" << std::endl;
	std::cout << "\033[0m";
}

//just debug the 10 first char
void
MindOpen::debug_data(void)
{
	std::vector<char>::iterator it = _data.begin();
	int i(0);

	std::cout << "\033[33m DATA: ";
	while (it != _data.end() && i < 10)
	{
		std::cout << "[" << static_cast<int>(*it) << "]";
		it++;
		i++;
		if (it != _data.end() && i != 10)
			std::cout  << ", ";
		else
			std::cout  << std::endl;
	}
	std::cout << "\033[0m";
}

//process all the instructions
void
MindOpen::process(int debug)
{
	std::cout << std::endl << \
		"\033[32m******** PROCESSING START: ********\033[m" << std::endl;
	while (_inst_ptr != _instructions.end())
	{
		if (debug)
		{
			debug_data();
			debug_next_instruction();
		}
		(*_inst_ptr)->execute(*this);	
		_inst_ptr++;
	}
	std::cout << "\033[32m********* PROCESSING END: *********\033[m" \
		<< std::endl << std::endl;
}
