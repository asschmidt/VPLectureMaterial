# Install prerequisites
sudo apt-get update
sudo apt-get install neovim xz-utils git gcc build-essential
sudo apt-get install openjdk-21-jdk cmake python3 curl wget imhex ghidra

# Prepare Tools folder
cd ~
mkdir Tools
cd ~/Tools

ARM_TOOL_CHAIN=arm-gnu-toolchain-14.3.rel1-x86_64-arm-none-eabi
ECLIPSE=eclipse-cpp-2025-09-R-linux-gtk-x86_64

# Download and install ARM GNU Toolchain
wget https://armkeil.blob.core.windows.net/developer/Files/downloads/gnu/14.3.rel1/binrel/$ARM_TOOL_CHAIN.tar.xz
tar xvfJ $ARM_TOOL_CHAIN.tar.xz
mv $ARM_TOOL_CHAIN arm-gnu-toolchain

# Install QEmu and OpenOCD
sudo apt-get install qemu-system
sudo apt-get install openocd

# Download and install Eclipse
cd ~/Tools
wget https://ftp.halifax.rwth-aachen.de/eclipse/technology/epp/downloads/release/2025-09/R/$ECLIPSE.tar.gz
tar xvfz $ECLIPSE.tar.gz

# Setup environment
cd ~
echo 'export PATH="$PATH:/home/kali/Tools/arm-gnu-toolchain/bin:/home/kali/Tools/eclipse"' >> .profile