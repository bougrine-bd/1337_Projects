FROM debian:buster

RUN apt update && apt install mariadb-server -y

COPY tool/setup-db.sh .

RUN rm -rf etc/mysql/mariadb.conf.d/50-server.cnf
COPY conf/50-server.cnf etc/mysql/mariadb.conf.d/

COPY conf/usersdb.sql .

EXPOSE 3306

CMD ["sh", "setup-db.sh"]