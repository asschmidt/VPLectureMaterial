sudo apt-get update
sudo apt-get install neovim xz-utils git gcc build-essential
sudo apt-get install openjdk-21-jdk cmake python3 curl wget

cd ~
mkdir Tools
wget https://developer.arm.com/-/media/Files/downloads/gnu/14.2.rel1/binrel/arm-gnu-toolchain-14.2.rel1-x86_64-arm-none-eabi.tar.xz
tar xvfJ arm-gnu-toolchain-14.2.rel1-x86_64-arm-none-eabi.tar.xz
mv arm-gnu-toolchain-14.2.rel1-x86_64-arm-none-eabi arm-gnu-toolchain

cd ~
echo 'export PATH=$PATH:~/Tools/arm-gnu-toolchain/bin' >> .bash_profile

source .bash_profile

sudo apt-get install qemu-system
sudo apt-get install openocd

cd ~/Tools
wget https://eclipse.mirror.liteserver.nl/technology/epp/downloads/release/2024-12/R/eclipse-cpp-2024-12-R-linux-gtk-x86_64.tar.gz
tar xvfz eclipse-cpp-2024-12-R-linux-gtk-x86_64.tar.gz