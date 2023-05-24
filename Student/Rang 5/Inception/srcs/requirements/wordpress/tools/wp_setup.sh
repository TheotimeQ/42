#!/bin/bash

if [ -f ./wp-config.php ]
then
	echo "Wordpress already installer"
else
	echo "Installing Wordpress"

	wp core download --allow-root

	until mysqladmin -hmariadb -u$WORDPRESS_DB_USER -p$WORDPRESS_DB_USER_PASS ping && mariadb -hmariadb -u$WORDPRESS_DB_USER -p$WORDPRESS_DB_USER_PASS -e "SHOW DATABASES;" | grep "$WORDPRESS_DB_NAME"; \
		do
		echo 'Waiting for mariadb'
		sleep 1
	done

    wp core config  --dbname=$WORDPRESS_DB_NAME --dbuser=$WORDPRESS_DB_USER --dbpass=$WORDPRESS_DB_USER_PASS --dbhost=$WORDPRESS_DB_HOST --dbprefix=wp_ --allow-root
    
    wp core install --url=$DOMAIN_NAME --title="Inception" --admin_user=$WORDPRESS_ADMIN --admin_password=$WORDPRESS_ADMIN_PASS --admin_email=$WORDPRESS_ADMIN_MAIL --allow-root
    
	wp user create $WORDPRESS_USER $WORDPRESS_USER_MAIL --role=subscriber --user_pass=$WORDPRESS_USER_PASS --display_name=$WORDPRESS_USER_DISPLAY --allow-root
fi

# Mets les droit sur le dossier d'installation de wp
chown -R www-data:www-data /var/www/html/

# Lance php-
echo 'Starting php-fpm7.3'
/usr/sbin/php-fpm7.3 -F