# mpi-communication

Se ejcuta ´Vagranfile up´ para montar las 3 maquinas virtuales 

ingresamos a master:  vagrant ssh master

sudo mkdir /home/vagrant/nfs_shared
sudo chown vagrant:vagrant /home/vagrant/nfs_shared
echo "/home/vagrant/nfs_shared *(rw,sync,no_subtree_check)" | sudo tee -a /etc/exports
sudo exportfs -a
sudo systemctl restart nfs-kernel-server


En las máquinas nodo-0 y nodo-1, monta el directorio compartido:

sudo mkdir /mnt/nfs_shared
sudo mount -t nfs master:/home/vagrant/nfs_shared /mnt/nfs_shared


vericar si esta funcionando showmount -e localhost

luego en la maquina master ejecutasmo cd /home/vagrant/nfs_shared 

luego git clone https://github.com/holk26/mpi-communication.git

luego cd mpi-communication y ejecutamos el programa 

mpicc -o core core.c

luego ejecutamos en master calcula_pi.c

mpicc -o calcula_pi calcula_pi.c

1 procesador:
mpirun -np 1 --host master ./calcula_pi

2 procesadores:
mpirun -np 2 --host master,nodo-0 ./calcula_pi

3 procesadores:
mpirun -np 3 --host master,nodo-0,nodo-1 ./calcula_pi
