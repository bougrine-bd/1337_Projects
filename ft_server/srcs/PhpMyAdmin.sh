apt install -y php7.3-mysql
apt install -y php-mbstring


mv phpMyAdmin-5.0.1-all-languages phpmyadmin
mkdir phpmyadmin/tmp
chmod 777 phpmyadmin

chown -R mysql:mysql var/lib/mysql
service mysql start
mysql -uroot -proot -e "CREATE DATABASE phpmyadmin;"
mysql -uroot -proot -e "CREATE USER 'phpmy'@'localhost' IDENTIFIED BY 'phpmy';"
mysql -uroot -proot -e "GRANT ALL PRIVILEGES ON phpmyadmin.* TO 'phpmy'@'localhost';"
mysql -uroot -proot -e "FLUSH PRIVILEGES;"
mysql -uroot -proot phpmyadmin < phpmyadmin/sql/create_tables.sql

mysql -uroot -proot -e "CREATE DATABASE wordpress;"
mysql -uroot -proot -e "CREATE USER 'wpress'@'localhost' IDENTIFIED BY 'wpress';"
mysql -uroot -proot -e "GRANT ALL PRIVILEGES ON wordpress.* TO 'wpress'@'localhost';"
mysql -uroot -proot -e "FLUSH PRIVILEGES;"
mysql -uroot -proot wordpress < wordpress/wordpress.sql