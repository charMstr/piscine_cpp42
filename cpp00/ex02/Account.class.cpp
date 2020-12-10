/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 00:44:52 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/10 04:05:24 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <Account.class.hpp>
#include <iostream>     // std::cout
#include <iomanip>      // std::put_time
#include <ctime>        // std::time_t, struct std::tm, std::localtime
#include <chrono>       // std::chrono::system_clock

//publique functions***********************************************************

//static
int	
Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

//static 
int	
Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

//static
int	
Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

//static
int	
Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

//static
void	
Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << Account::_nbAccounts;
	std::cout << ";total:" << Account::_totalAmount;
	std::cout << ";deposits:" << Account::_totalNbDeposits;
	std::cout << ";withdeawals:" << Account::_totalNbWithdrawals << std::endl;
	return ;
}

//[19920104_091532] index:0;amount:42;created
Account::Account( int initial_deposit ) :
	_amount(initial_deposit)
{
	this->_accountIndex = Account::getNbAccounts();
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;
	return ;
}

//[19920104_091532] index:0;amount:47;closed
Account::~Account( void )
{
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;
	_displayTimestamp();
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;
	return ;
}

//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	
Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
	return ;
}

//[19920104_091532] index:0;p_amount:47;withdrawal:refused
//[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool	
Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";withdrawal:";
	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal;
	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals += 1;
	 return (true);
}

//useless
int		
Account::checkAmount( void ) const
{
	return (this->_amount);
}

//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void	
Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
	return ;
}

//[19920104_091532]
//private functions************************************************************
//static
void	
Account::_displayTimestamp( void )
{
	std::time_t tt = std::chrono::system_clock::to_time_t (std::chrono::system_clock::now());
	
	struct std::tm * ptm = std::localtime(&tt);
	std::cout << "[";
	std::cout << std::put_time(ptm,"%Y"); //year
	std::cout << std::put_time(ptm,"%m"); //month
	std::cout << std::put_time(ptm,"%d"); //day of the month
	std::cout << "_";
	std::cout << std::put_time(ptm,"%H"); //hour
	std::cout << std::put_time(ptm,"%M"); //minutes
	std::cout << std::put_time(ptm,"%S"); //secondes
	std::cout << "]";
	return ;
}

//unused
Account::Account( void )
{
	return ;
}

//static private variables*****************************************************
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
