FROM debian:buster

# Récupère les mises à jour et installe les paquets nécessaires
RUN apt-get update -y && apt-get upgrade -y

# Installation de MariaDB 
RUN apt-get install -y mariadb-server

# Supprime les fichiers généres par l'installation
RUN apt-get clean && rm -rf /var/lib/apt/lists/*

# Labélise l'image
LABEL version="1.0"
LABEL description="MariaDB Server"

# Création des répertoires nécessaires
RUN mkdir -p /var/run/mysqld && mkdir -p /var/lib/mysql

# Copie les fichiers de configuration et de setup
COPY ./conf/my.cnf /etc/mysql/my.cnf
COPY ./tools/db_setup.sh /db_setup.sh

# Rend le script executable et donne les droits nécessaires
RUN chmod +x db_setup.sh && chmod -R 777 /var/lib/mysql /var/run/mysqld

EXPOSE 3306

# Commande par défaut
ENTRYPOINT ["./db_setup.sh"]