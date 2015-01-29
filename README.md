## Asus Fan Speed Control

### Description
Daemon that provides fan speed control for Asus laptops by manipulating [DSDT](https://wiki.archlinux.org/index.php/DSDT) registers.
### Installation
This project uses c++11 features(it wasn't absolutely neccessary, just for fun) which are not fully supported until GCC 4.9 or Clang 3.4.

    git clone https://github.com/aot9/AFSC asfc
    cd afsc/
    make
    sudo make install
### Usage
AFSC relies on start-stop-daemon utility, which is common thing on most popular distros.
After installing reboot or run `/etc/init.d/afsc start`. *NO WARRANTY. USE AT YOUR OWN RISK. USING AFSC MAY CAUSE HARDWARE MALFUNCTIONING*.

### Success story list
* UL30JT
* F3JP

### Links
[Similar project](https://github.com/nicolai-rostov/asus-fancontrol)<br>
[Clang tutorial](https://solarianprogrammer.com/2013/01/17/building-clang-libcpp-ubuntu-linux/)<br>
[A.Breckel original paper](http://www.aneas.org/knowledge/asus_f3jp_fan_control.php)

