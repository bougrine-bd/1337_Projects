#include "Include/Webserv.hpp"


int main(int argc, char **argv)
{
	if (argc == 1 || argc == 2)
	{
		std::string defultConf = "src/default.conf";
		if (argc == 2)
			defultConf = argv[1];

		try
		{
			std::list<Server> servers;

			ParseConfigFile parse(defultConf, servers);
			runWebserv(servers);
		}
		catch(const Result& e)
		{
			std::cout << RED << "Error " << WHITE << ": Configuration file error." << RESETCOLOR << "\n";
		}
	}
	else
		std::cout << RED << "Error " << WHITE << ": You must enter exactly one argument." << RESETCOLOR << "\n";
	return (0);
}