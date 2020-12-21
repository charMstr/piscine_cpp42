/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MindOpen.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 01:16:54 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/21 09:36:25 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINDOPEN_HPP
# define MINDOPEN_HPP

//#include <iostream>
# include <deque>
# include <vector>
#include <fstream>
# define NO_DEBUG 0
# define DEBUG 1

class Instructions;

class MindOpen
{
	public:
		MindOpen(std::ifstream &input_file);
virtual	~MindOpen(void);
		MindOpen(MindOpen const &src);
		MindOpen &	operator=(MindOpen const &rhs);

		int							dec_instPtr(void);
		int							inc_instPtr(void);
		std::deque<Instructions*>::iterator get_instPtr(void);
		std::deque<Instructions *>	&get_inst(void);
		std::vector<char>::iterator &get_dataPtr(void);

		void	debug_instructions();
		void	debug_data();
		void	debug_next_instruction(void);
		void	process(int debug);
	protected:

	private:
		std::deque<Instructions*>			_instructions;
		std::deque<Instructions*>::iterator _inst_ptr;
		std::vector<char>					_data;
		std::vector<char>::iterator			_data_ptr;

		void load_instructions(std::ifstream &input_file);
};

//std::ostream	&operator<<(std::ostream &o, MindOpen const &rhs);

#endif
