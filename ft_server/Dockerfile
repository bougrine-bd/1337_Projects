FROM	debian:buster

RUN		apt update ; apt install -y nginx ; apt install -y php-fpm ; apt install -y wget
RUN     wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-all-languages.tar.gz \
        ;wget https://dev.mysql.com/get/mysql-apt-config_0.8.14-1_all.deb \
        ;wget https://wordpress.org/latest.tar.gz
RUN     tar xfz phpMyAdmin-5.0.1-all-languages.tar.gz \
        ;tar xfz latest.tar.gz
COPY    srcs/*.sh ./
COPY    srcs/wordpress.sql /wordpress
RUN     sh mysql.sh
RUN     sh PhpMyAdmin.sh

COPY    srcs/default /etc/nginx/sites-available/default
COPY    srcs/config.inc.php /phpmyadmin/config.inc.php
COPY    srcs/wp-config.php /wordpress
COPY    srcs/ssl_cert.pem /etc/ssl/certs/ssl_cert.pem
COPY    srcs/ssl_cert.key /etc/ssl/private/ssl_cert.key

CMD     sh service.sh && bash