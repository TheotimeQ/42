#!/bin/bash

#Genere le script d'initialisation de la base de donnees
echo "Generating MySQL init script..."

echo "CREATE DATABASE IF NOT EXISTS Test ;" > $DATABASE_PATH
echo "CREATE DATABASE IF NOT EXISTS $DATABASE_NAME ;" >> $DATABASE_PATH

echo "CREATE USER IF NOT EXISTS '$DATABASE_USER'@'%' IDENTIFIED BY '$DATABASE_USER_PASS' ;" >> $DATABASE_PATH
echo "GRANT ALL PRIVILEGES ON $DATABASE_NAME.* TO '$DATABASE_USER'@'%' ;" >> $DATABASE_PATH
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '$DATABASE_ROOT_PASS' ;" >> $DATABASE_PATH
echo "FLUSH PRIVILEGES;" >> $DATABASE_PATH

echo "USE $DATABASE_NAME;" >> $DATABASE_PATH
echo "CREATE TABLE inception (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(50) NOT NULL);" >> $DATABASE_PATH
echo "INSERT INTO inception (name) VALUES ('Dream'), ('Reality'), ('Limbo');" >> $DATABASE_PATH

echo "MySQL init script generated."

#Demarre le serveur MySQL
echo "Starting MySQL..."

init_base() {
    until mysqladmin -u root status >/dev/null 2>&1; do
        echo "Waiting for mariadb t start..."
        sleep 1
    done

    echo "MySQL started."
    mysql -u root < $DATABASE_PATH
}

init_base & mysqld