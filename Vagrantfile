Vagrant.configure("2") do |config|
  # Configuración de la máquina máster
  config.vm.define "master" do |master|
    master.vm.box = "ubuntu/focal64"
    master.vm.network "private_network", ip: "192.168.56.77"  # Red LAN interna
    master.vm.network "public_network"  # Red pública NAT
    master.vm.provider "virtualbox" do |vb|
      vb.memory = "1024"
      vb.cpus = 1
    end

    # Provisión del máster
    master.vm.provision "shell", inline: <<-SHELL
      sudo apt-get update
      sudo apt-get install -y software-properties-common
      wget -qO - https://www.openhpc.community/apt/keys/openhpc.asc | sudo apt-key add -
      echo "deb https://www.openhpc.community/apt/ubuntu focal main" | sudo tee /etc/apt/sources.list.d/openhpc.list
      sudo apt-get update
      sudo apt-get install -y openhpc
    SHELL
  end

  # Configuración del nodo-0
  config.vm.define "node-0" do |node|
    node.vm.box = "ubuntu/focal64"
    node.vm.network "private_network", ip: "192.168.56.78"  # Red LAN interna
    node.vm.provider "virtualbox" do |vb|
      vb.memory = "1024"
      vb.cpus = 1
    end

    # Provisión del nodo-0
    node.vm.provision "shell", inline: <<-SHELL
      sudo apt-get update
      sudo apt-get install -y software-properties-common
      wget -qO - https://www.openhpc.community/apt/keys/openhpc.asc | sudo apt-key add -
      echo "deb https://www.openhpc.community/apt/ubuntu focal main" | sudo tee /etc/apt/sources.list.d/openhpc.list
      sudo apt-get update
      sudo apt-get install -y openhpc
    SHELL
  end

  # Configuración del nodo-1
  config.vm.define "node-1" do |node|
    node.vm.box = "ubuntu/focal64"
    node.vm.network "private_network", ip: "192.168.56.79"  # Red LAN interna
    node.vm.provider "virtualbox" do |vb|
      vb.memory = "1024"
      vb.cpus = 1
    end

    # Provisión del nodo-1
    node.vm.provision "shell", inline: <<-SHELL
      sudo apt-get update
      sudo apt-get install -y software-properties-common
      wget -qO - https://www.openhpc.community/apt/keys/openhpc.asc | sudo apt-key add -
      echo "deb https://www.openhpc.community/apt/ubuntu focal main" | sudo tee /etc/apt/sources.list.d/openhpc.list
      sudo apt-get update
      sudo apt-get install -y openhpc
    SHELL
  end
end
