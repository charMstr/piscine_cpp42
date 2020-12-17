/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 15:06:37 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/17 16:15:01 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <unistd.h>

struct Data { std::string s1; int n; std::string s2; };

typedef struct s_MyData
{
	char	array1[8];	
	int		randomInt;
	char	array2[8];
}				t_MyData;

void displayMyDataContentForPeer(t_MyData *ptr)
{
	std::cout << "Displaying the content of MyData structure:" << std::endl;
	std::cout << "array1 = \"";
	for (int i = 0; i < 8; i++)
		std::cout << ptr->array1[i];
	std::cout << "\"" << std::endl;
	std::cout << "random int = " << ptr->randomInt << std::endl;
	std::cout << "array2 = \"";
	for (int i = 0; i < 8; i++)
		std::cout << ptr->array2[i];
	std::cout << "\"" << std::endl;
}

void ShowDeserialized(Data *ptr)
{
	std::cout << "After deserialization, Data contains:" << std::endl;
	std::cout << "s1: \"" << ptr->s1 << "\"" << std::endl;
	std::cout << "n: " << ptr->n << std::endl;
	std::cout << "s2: \"" << ptr->s2 << "\"" << std::endl;
}

void * serialize(void)
{
	t_MyData *ptr = new t_MyData;
	static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    srand( (unsigned) time(NULL) * getpid());
    for (int i = 0; i < 8; ++i)
        ptr->array1[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    for (int i = 0; i < 8; ++i)
        ptr->array2[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	ptr->randomInt = rand();

	displayMyDataContentForPeer(ptr);
	return (ptr);
}

Data * deserialize(void * raw)
{
	Data *ptr = new Data;
	
	t_MyData *my_ptr = reinterpret_cast<t_MyData*>(raw);
	for (int i = 0; i < 8; i++)
	{
		ptr->s2 += my_ptr->array2[i];
		ptr->s1 += my_ptr->array1[i];
	}
	ptr->n = my_ptr->randomInt;
	return (ptr);
}

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	void *ptr = serialize();

	std::cout << "..." << std::endl;

	Data *received= deserialize(ptr);	

	ShowDeserialized(received);
	return (0);
}
