NAME = webserv

FLAG = -Wall -Wextra -Werror -std=c++98

SRC = src/Webserv.cpp\
		src/Socket/Socket.cpp\
		src/Response/Response.cpp src/Response/funcs.cpp src/Response/Client.cpp\
		src/Poll/Poll.cpp\
		src/ConfigFileParser/ParseConfigFile.cpp src/ConfigFileParser/Location.cpp\
		src/ConfigFileParser/Server.cpp\
		src/CGI/cgi.cpp\
		src/RequestParser/Request.cpp\
		src/Tools/tools.cpp

all: $(NAME)

$(NAME): $(SRC)
	@c++ $(SRC) -o $(NAME) $(FLAG)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf webserv

re: fclean	all