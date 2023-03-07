if [ ! -d /var/lib/mysql/$DB_NAME ]
then
    service mysql start
    mariadb -e "CREATE DATABASE $DB_NAME;"
    mariadb -e "GRANT ALL ON $DB_NAME.* TO '$DB_USERNAME' IDENTIFIED BY '$DB_PASSWORD';"
    mariadb -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$ROOT_DB_PASSWORD';"
    mariadb -e "FLUSH PRIVILEGES;"
    mariadb -uroot -p$ROOT_DB_PASSWORD $DB_NAME < usersdb.sql
    mysqladmin -uroot -p$ROOT_DB_PASSWORD shutdown
fi

mysqld_safe