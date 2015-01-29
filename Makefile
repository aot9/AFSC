TARGET := afcd
CXX := clang++
CPP_FILES := $(wildcard src/*.cpp)
INC_DIR := ./include/
CXXFLAGS := -Wall -Wextra -O2 -std=c++11 -stdlib=libc++ -DLOGGING 

.PHONY: $(TARGET)

$(TARGET):
	@test -d ./build || mkdir build
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) $(CPP_FILES) -o build/$(TARGET)
