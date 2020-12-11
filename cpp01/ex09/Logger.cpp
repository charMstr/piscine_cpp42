/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:49:11 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/11 13:45:07 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>      // std::put_time
#include <ctime>        // std::time_t, struct std::tm, std::localtime
#include <chrono>       // std::chrono::system_clock
#include <sstream>

Logger::Logger(std::string outputFile) :
	_outputFile(outputFile)
{
	arrayFuncPtr[0] = &Logger::logToConsole;
	arrayFuncPtr[1] = &Logger::logToFile;
	arrayFuncName[0] = "logToConsole";
	arrayFuncName[1] = "logToFile";
}

Logger::~Logger(void)
{
	return ;
}

void
Logger::logToConsole(std::string message) const
{
	std::cout << message << std::endl;	
}

void
Logger::logToFile(std::string message) const
{
	std::ofstream ofs;

	ofs.open (this->_outputFile, std::ofstream::out | std::ofstream::app);
	ofs << message;
	ofs.close();
}

std::string
Logger::makeLogEntry(std::string message, int stdOutput) const
{
	std::time_t tt = std::chrono::system_clock::to_time_t (std::chrono::system_clock::now());
	struct std::tm * ptm = std::localtime(&tt);

	std::stringstream ss;

	ss << "[";
	ss << std::put_time(ptm,"%Y"); //year
	ss << "/" << std::put_time(ptm,"%m"); //month
	ss << "/" << std::put_time(ptm,"%d"); //day of the month
	ss << "_";
	ss << std::put_time(ptm,"%H"); //hour
	ss << ":" << std::put_time(ptm,"%M"); //minutes
	ss << ":" << std::put_time(ptm,"%S"); //secondes
	ss << "]";
	ss << message;
	if (!stdOutput)
		ss << std::endl;

	return (ss.str());
}

void
Logger::log(std::string const &dest, std::string const &message) const
{
	int res = dest.compare("logToConsole");

	std::string logFormated = makeLogEntry(message, !res);

	for (int i = 0; i < 2; i++)
	{
		if (!dest.compare(this->arrayFuncName[i]))
		{ 
			(this->*this->arrayFuncPtr[i])(logFormated);
		}
	}
}
