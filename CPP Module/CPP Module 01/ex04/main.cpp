/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:53:41 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/04 11:46:54 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void replace(std::string filename, std::string s1, std::string s2)
{
	std::ifstream file(filename);
	std::ifstream nextLineInFile(filename);

	if (file.is_open())
	{
		std::ofstream file2(filename + ".replace");
		std::string line;
		int pos;
		int i;
	
		getline(nextLineInFile, line);
		while (getline(file, line) != 0)
		{
			i = 0;
			while (line[i])
			{
				if ((pos = line.find(s1, i)) != -1)
				{
					for (int j = 0; j < pos; j++)
					{
						file2 << line[j];
						i++;
					}
					file2 << s2;
					i += s1.length();
				}
				else
				{
					file2 << &line[i];
					break ;
				}
			}
			if (getline(nextLineInFile, line) != 0)
				file2 << std::endl;
		}
		file.close();
		nextLineInFile.close();
	}
	else
		std::cout << "Error file does not exist" << std::endl;
}

int main (int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "must be 4 args" << std::endl;
		return (0);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	
	replace(filename, s1, s2);
}