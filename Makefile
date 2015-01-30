CXX := clang++
CPP_FILES := $(wildcard src/*.cpp)
INC_DIR := ./include/
CXXFLAGS := -Wall -Wextra -O2 -std=c++11 -stdlib=libc++
DEST_DIR := ./build

.PHONY: uninstall install

release:
	@test -d $(DEST_DIR) || mkdir $(DEST_DIR)
	$(CXX) $(CXXFLAGS) -DNDEBUG -I$(INC_DIR) $(CPP_FILES) -o $(DEST_DIR)/afsc

debug:
	@test -d $(DEST_DIR) || mkdir $(DEST_DIR)
	$(CXX) $(CXXFLAGS) -g -I$(INC_DIR) $(CPP_FILES) -o $(DEST_DIR)/afsc_debug

install:
	@cp ./build/afsc /usr/sbin/
	@cp afsc.conf /etc/
	@cp afsc.sh /etc/init.d/afsc
	@update-rc.d afsc defaults

uninstall:
	@rm /usr/sbin/afsc
	@rm /etc/afsc.conf
	@rm /etc/init.d/afsc
	@update-rc.d afsc remove

