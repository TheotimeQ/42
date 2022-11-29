# •L’architecture de votre système d’exploitation ainsi que sa version de kernel.
archi=$(uname -a)   

# •Le nombre de processeurs physiques.
nb_proc_phy=$(cat /proc/cpuinfo | grep -i "^processor" | wc -l)

# •Le nombre de processeurs virtuels.
nb_proc_virt=$(cat /proc/cpuinfo | grep "physical id" | sort -u | wc -l)
															# unique (supprime doublons)

# •La mémoire vive disponible actuelle sur votre serveur ainsi que son taux d’utilisation sous forme de pourcentage.
total_vive=$(free -m | awk '$1 == "Mem:" {print $2}')
use_vive=$(free -m | awk '$1 == "Mem:" {print $3}')
pourc_vive=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')

# La commande awk '$1 == "Mem:" {print $2}' extrait la deuxième colonne lorsque la première correspond à la chaîne de caractères "Mem:".

# •La mémoire disponible actuelle sur votre serveur ainsi que son taux d’utilisation sous forme de pourcentage.
total_disk=$(df -Bg | grep '^/dev/' | grep -v '/boot$' | awk '{total += $2} END {print total}')
use_disk=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{use += $3} END {print use}')
pourc_disk=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{use += $3} {total+= $2} END {printf("%d"), use/total*100}')

					# m pour mega
					# g pour giga  ^ pour commence avec 

# •Le taux d’utilisation actuel de vos processeurs sous forme de pourcentage.
cpu_load=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}')

# •La date et l’heure du dernier redémarrage.
date_boot=$(who -b | awk '$1 == "system" {print $3 " " $4}')

# •Si LVM est actif ou pas.
lvm_count=$(lsblk | grep "lvm" | wc -l)
lvm_actif=$(if [ $lvm_count -eq 0 ]; then echo no; else echo yes; fi)

# •Le nombre de connexions actives.
nb_co=$(cat /proc/net/sockstat{,6} | awk '$1 == "TCP:" {print $3}')

# •Le nombre d’utilisateurs utilisant le serveur.
nb_log=$(users | wc -w)

# •L’adresse IPv4 de votre serveur, ainsi que son adresse MAC (Media Access Control).
ip=$(hostname -I)
mac=$(ip link show | awk '$1 == "link/ether" {print $2}')

# •Le nombre de commande executées avec le programme sudo
all_cmd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "  #Architecture: $archi
        #CPU physical: $nb_proc_phy
        #vCPU: $nb_proc_virt
        #Memory Usage: $use_vive/${total_vive}MB ($pourc_vive%)
        #Disk Usage: $use_disk/${total_disk}Gb ($pourc_disk%)
        #CPU load: $cpu_load
        #Last boot: $date_boot
        #LVM use: $lvm_actif
        #Connexions TCP: $nb_co ESTABLISHED
        #User log: $nb_log
        #Network: IP $ip ($mac)
        #Sudo: $all_cmd cmd"