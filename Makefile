CXX := clang++
CPP_FILES := $(wildcard src/*.cpp)
INC_DIR := ./include/
CXXFLAGS := -Wall -Wextra -O2 -std=c++11 -stdlib=libc++
DEST_DIR := ./build

.PHONY: install clean

all:
	@test -d $(DEST_DIR) || mkdir $(DEST_DIR)
	$(CXX) $(CXXFLAGS) ${DEFS} -I$(INC_DIR) $(CPP_FILES) -o $(DEST_DIR)/afsc

install:
	@cp ./build/afsc /usr/sbin/
	@cp afsc.conf /etc/
	@cp afsc.sh /etc/init.d/afsc
	@update-rc.d

uninstall:
	@rm /usr/sbin/afsc
	@rm /etc/afsc.conf
	@rm /etc/init.d/afsc
	@update-rc.d

