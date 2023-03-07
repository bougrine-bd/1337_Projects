#include "../Include/Webserv.hpp"

std::string generateFileName(std::string prefix)
{
    char            s[10];
    struct timeval  tv;
    std::string     filename;

    gettimeofday(&tv, NULL);
    sprintf(s, "%d", tv.tv_usec);
    filename = prefix + s;
    return (filename);
}

std::string strToUpper(std::string s)
{
	for (unsigned long int i = 0; i < s.length(); ++i)
		s[i] = toupper(s[i]);
	return (s);
}

std::string strToLower(std::string s)
{
	for (size_t i = 0; i < s.length(); ++i)
		s[i] = tolower(s[i]);
	return (s);
}

size_t  strToSize_t(std::string s)
{
    size_t num;

    sscanf(s.c_str(), "%zu", &num);
    return (num);
}

char        hexToAscii(std::string hex)
{
    char c = 0;

    for (size_t i = 0; i < hex.length(); ++i)
    {
        if (hex[i] >= 'a')
			c = c * 16 + (hex[i] - 87);
		else if (hex[i] >= 'A')
			c = c * 16 + (hex[i] - 55);
		else
			c = c * 16 + (hex[i] - 48);
    }
    return (c);
}

