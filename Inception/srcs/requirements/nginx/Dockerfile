FROM debian:buster

RUN	apt update &&\
	apt install -y nginx &&\
	rm -rf /etc/nginx/nginx.conf

COPY conf/nginx.conf /etc/nginx/nginx.conf

RUN rm -rf /etc/nginx/sites-available/default
COPY conf/default /etc/nginx/sites-available/

RUN mkdir etc/nginx/ssl
COPY conf/ssl/* etc/nginx/ssl/

EXPOSE 443 

CMD ["nginx", "-g", "daemon off;"]