# Installation

## Ubuntu VirtualBox Installation
Download the Ubuntu 24.10 ISO Image
https://ubuntu.com/download/desktop

Create a VirtualBox VM for Linux and install Ubuntu with default packages. The VM should have at least 4GB of RAM

## Download Kali Linux VM
If you don't want to install a Linux distribution by your own, just download a ready-to-use Kali Linux VM
https://www.kali.org/get-kali/#kali-virtual-machines

## Get Install Script (install everything via script)
    $ sudo apt-get install curl
    $ cd ~
    $ curl https://raw.githubusercontent.com/asschmidt/VPLectureMaterial/refs/heads/main/Setup/install.sh >> install.sh
    $ bash install.sh

## Prerequisites
The following tools should be installed on the Linux system used for the Lecture examples

- NeoVim
- XZ Utils
- Git
- GCC and build essentials (incl. Make)
- OpenJDK
- CMake
- Python
- Curl
- WGet
- ImHex
- Ghidra

### Install Prerequisites (manually)
    $ sudo apt-get update

    $ sudo apt-get install neovim xz-utils git gcc build-essential
    $ sudo apt-get install openjdk-21-jdk cmake python3 curl wget imhex ghidra


## Tools

### ARM GNU Toolchain

    $ cd ~
    $ mkdir Tools
	$ cd Tools

    $ wget https://developer.arm.com/-/media/Files/downloads/gnu/14.2.rel1/binrel/arm-gnu-toolchain-14.2.rel1-x86_64-arm-none-eabi.tar.xz

    $ tar xvfJ arm-gnu-toolchain-14.2.rel1-x86_64-arm-none-eabi.tar.xz

    $ mv arm-gnu-toolchain-14.2.rel1-x86_64-arm-none-eabi arm-gnu-toolchain

To run the GNU ARM tools from any directory, the `PATH` environment variable must be extended. For this, open the file `.bash_profile` in NeoVim (or any other editor) and add the following line

    export PATH=$PATH:~/Tools/arm-gnu-toolchain/bin

After saving the file, it must be reloaded to apply the changes and make them available

    $ source .bash_profile

### QEmu

    $ sudo apt-get install qemu-system

### OpenOCD

    $ sudo apt-get install openocd

### Eclipse

Download Eclipse for C/C++

    $ cd ~/Tools

    $ wget https://eclipse.mirror.wearetriple.com//technology/epp/downloads/release/2025-06/R/eclipse-cpp-2025-06-R-linux-gtk-x86_64.tar.gz

    $ tar xvfz eclipse-cpp-2024-12-R-linux-gtk-x86_64.tar.gz


# Setup
Clone the VPLectureMaterials repo

	$ cd ~
	$ mkdir Repo
	$ cd Repo
    $ git clone https://github.com/asschmidt/VPLectureMaterial