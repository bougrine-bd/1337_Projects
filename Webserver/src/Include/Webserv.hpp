#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <sys/unistd.h>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/poll.h>
#include <dirent.h>

std::string itos(int num);

extern char **environ;

class   Server;
class   Location;

enum    Method  { GET, POST, DELETE };
enum    State   {Parse_Request_Line, Parse_Header_Fields, Parse_Body, Parse_Chunked_Body, Parse_Trailer_Part, Ready, Error};
enum    Result  {ConfigFile_ParseError, ConfigFile_MethodNotAllowed, ConfigFile_Duplicate, Bad_Request, 
				Server_Error, Not_Implemented, Bad_Gateway, HTTP_Version_Not_Supported, Request_Unready, Request_Ready, Response_Ready};

typedef std::set<std::pair<std::string, int> >			t_listen_port;
typedef std::map<std::string, std::list<std::string> >	t_request_headers;
typedef std::map<std::string, std::string>				t_cgi_headers;
typedef std::map<std::string, Location>					t_locations;
typedef std::pair<int, std::string>                     t_redirection;
typedef std::set<std::string>                           t_index;
typedef std::map<std::string, std::string >             t_cgi;

#include "../Tools/tools.hpp"
#include "../ConfigFileParser/ParseConfigFile.hpp"
#include "../ConfigFileParser/Server.hpp"
#include "../ConfigFileParser/Location.hpp"
#include "../RequestParser/Request.hpp"
#include "../CGI/cgi.hpp"
#include "../Socket/Socket.hpp"
#include "../Response/Response.hpp"
#include "../Response/Client.hpp"
#include "../Response/funcs.hpp"
#include "../Poll/Poll.hpp"

#define MAX_CLIENT		SOMAXCONN
#define TCP_MAX_BUFF	65535
#define UREAD_ONLY		256;
#define UWRITE_ONLY		128;
#define UEXECUTE_ONLY	64;

#define RED				"\033[0;31m"
#define GREEN			"\033[0;32m"
#define YELLOW			"\033[0;33m"
#define PURPLE			"\033[0;35m"
#define CYAN			"\033[0;36m"
#define WHITE           "\033[0;37m"
#define RESETCOLOR		"\033[0m"



