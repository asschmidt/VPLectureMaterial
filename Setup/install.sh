sudo apt-get update
sudo apt-get install neovim xz-utils git gcc build-essential
sudo apt-get install openjdk-21-jdk cmake python3 curl wget imhex ghidra

cd ~
mkdir Tools
cd ~/Tools

ARM_TOOL_CHAIN=arm-gnu-toolchain-14.2.rel1-x86_64-arm-none-eabi
ECLIPSE=eclipse-cpp-2025-09-R-linux-gtk-x86_64

#wget https://developer.arm.com/-/media/Files/downloads/gnu/14.2.rel1/binrel/arm-gnu-toolchain-14.2.rel1-x86_64-arm-none-eabi.tar.xz
wget https://developer.arm.com/-/media/Files/downloads/gnu/14.3.rel1/binrel/$(ARM_TOOL_CHAIN).tar.xz
tar xvfJ $(ARM_TOOL_CHAIN).tar.xz
mv $(ARM_TOOL_CHAIN) arm-gnu-toolchain

sudo apt-get install qemu-system
sudo apt-get install openocd

cd ~/Tools
wget https://ftp.halifax.rwth-aachen.de/eclipse/technology/epp/downloads/release/2025-09/R/$(ECLIPSE).tar.gz
tar xvfz $(ECLIPSE).tar.gz

cd ~
echo 'PATH="$PATH:/home/kali/Tools/arm-gnu-toolchain/bin:/home/kali/Tools/eclipse"' >> .profile

source .profile