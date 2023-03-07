FROM debian:buster

RUN apt update &&\
    apt install php7.3 -y &&\
    apt install php7.3-fpm -y &&\
    apt install php7.3-mysql -y

RUN apt install wget -y &&\
    wget https://wordpress.org/latest.tar.gz &&\
    tar xzvf latest.tar.gz &&\
    mkdir /var/www/inception &&\
    cp -R wordpress/* /var/www/inception/ &&\
    rm -rf latest.tar.gz wordpress

COPY conf/wp-config.php /var/www/inception/

RUN rm -rf /etc/php/7.3/fpm/pool.d/www.conf
COPY conf/www.conf /etc/php/7.3/fpm/pool.d/

RUN service php7.3-fpm start

EXPOSE 9000

CMD ["php-fpm7.3", "-F"]
