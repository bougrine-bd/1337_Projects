chown -R mysql:mysql var/lib/mysql
service nginx start
service php7.3-fpm start
service mysql start