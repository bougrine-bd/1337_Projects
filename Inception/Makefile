# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 13:52:34 by abougrin          #+#    #+#              #
#    Updated: 2022/03/14 16:11:51 by abougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DC=docker-compose
YML_FILE=./srcs/docker-compose.yml
OLD_CONF=127.0.0.1	localhost
NEW_CONF=127.0.0.1       localhost       abougrin.42.fr
RM_VFILE=/home/abougrin/data
CR_VFILE=/home/abougrin/data /home/abougrin/data/DB /home/abougrin/data/WordPress
SUDO=echo \' | sudo -S


all:
	$(SUDO) mkdir -p $(CR_VFILE)
	$(DC) -f $(YML_FILE) up --build -d
	$(SUDO) sed -i 's/$(OLD_CONF)/$(NEW_CONF)/g' /etc/hosts

up:
	$(DC) -f $(YML_FILE) up -d

down:
	$(DC) -f $(YML_FILE) down

start:
	$(DC) -f $(YML_FILE) start
	
stop:
	$(DC) -f $(YML_FILE) stop

rimg: down
	docker rmi $$(docker images -q)

rvol: 
	docker volume rm $$(docker volume ls -q)

fclean: down rimg rvol
	$(SUDO) rm -rf $(RM_VFILE)

re: down all