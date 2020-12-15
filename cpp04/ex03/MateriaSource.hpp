/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 11:23:15 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/15 12:53:11 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
# include "IMateriaSource.hpp"

# define MAX_MATERIA 4
class AMateria;

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
virtual	~MateriaSource(void);
		MateriaSource(MateriaSource const &src);
		MateriaSource &	operator=(MateriaSource const &rhs);
		
		virtual void		learnMateria(AMateria *m);
		virtual AMateria*	createMateria(std::string const & type);

	protected:
		AMateria	**_inventory;
		int			_fullnessInventory;
		void		_createAndInitInventory(void);
		void		_cleanInventory(void);

	private:
		
};

//std::ostream	&operator<<(std::ostream &o, MateriaSource const &rhs);

#endif
