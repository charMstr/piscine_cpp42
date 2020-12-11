/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:49:03 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/11 13:36:41 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
//del me
#include <iostream>

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	Logger LogMachine("output_file.txt");

	LogMachine.log("logToConsole", "hey ho!?");
	LogMachine.log("logToFile", "SALUTE!0");
	LogMachine.log("logToFile", "SALUTE!1");
	LogMachine.log("logToFile", "SALUTE!2");
	LogMachine.log("logToConsole", "tu vas me repondre!?");
	LogMachine.log("logToFile", "SALUTE!3");
	LogMachine.log("logToFile", "MORE LOGS?");
	return (0);
}
