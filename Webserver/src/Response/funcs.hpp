#pragma once

#include "../Include/Webserv.hpp"

void runWebserv(std::list<Server> &servers);
bool sortBylenth(std::string s1, std::string s2);
void initMimeType(std::map<std::string, const std::string> &mimeType);
void initStatusCM(std::map<int, const std::string> &statusCM);