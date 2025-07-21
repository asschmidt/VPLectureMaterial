sudo apt-get update
sudo apt-get install neovim xz-utils git gcc build-essential
sudo apt-get install openjdk-21-jdk cmake python3 curl wget imhex ghidra

cd ~
mkdir Tools
cd ~/Tools
wget https://developer.arm.com/-/media/Files/downloads/gnu/14.2.rel1/binrel/arm-gnu-toolchain-14.2.rel1-x86_64-arm-none-eabi.tar.xz
tar xvfJ arm-gnu-toolchain-14.2.rel1-x86_64-arm-none-eabi.tar.xz
mv arm-gnu-toolchain-14.2.rel1-x86_64-arm-none-eabi arm-gnu-toolchain

sudo apt-get install qemu-system
sudo apt-get install openocd

cd ~/Tools
wget https://eclipse.mirror.wearetriple.com//technology/epp/downloads/release/2025-06/R/eclipse-cpp-2025-06-R-linux-gtk-x86_64.tar.gz
tar xvfz eclipse-cpp-2025-06-R-linux-gtk-x86_64.tar.gz

cd ~
echo 'PATH="$PATH:/home/kali/Tools/arm-gnu-toolchain/bin:/home/kali/Tools/eclipse"' >> .profile

source .profile