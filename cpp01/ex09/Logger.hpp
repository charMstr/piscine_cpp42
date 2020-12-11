/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:49:11 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/11 13:39:59 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <string>

class Logger
{
	typedef void (Logger::*func)(std::string) const;
	public:
		Logger(std::string outputFile);
		~Logger(void);
		
		void log(std::string const &dest, std::string const &message) const;

	protected:

	private:
		//data
		std::string _outputFile;	
		std::string arrayFuncName[2];
		func		arrayFuncPtr[2];

		//funcs
		void		logToConsole(std::string str) const;
		void		logToFile(std::string str) const;
		std::string makeLogEntry(std::string message, int stdOutput) const;
};

#endif
