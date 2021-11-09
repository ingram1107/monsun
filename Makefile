BUILD_DIR=build
CMAKE=cmake
CMAKE_FLAGS=-S . -B $(BUILD_DIR)
EXE=./monsun

ifneq ("$(wildcard compile_commands.json)","")
	JSON_EXISTS = 1
else
	JSON_EXISTS = 0
endif

build: CMakeLists.txt monsun.h.in lib/* src/* doc/* test/*
	$(CMAKE) $(CMAKE_FLAGS)
ifeq ($(JSON_EXISTS),0)
	ln -s $(BUILD_DIR)/compile_commands.json compile_commands.json
endif
	cd $(BUILD_DIR) && make

install: CMAKE_FLAGS = --install
install:
	$(CMAKE) $(CMAKE_FLAGS) $(BUILD_DIR)

pack:
	cd $(BUILD_DIR) && cpack

uninstall:
	rm /usr/local/lib/libcustomer.a
	rm /usr/local/include/Customer.cpp
	rm /usr/local/lib/liblinkedlist.a
	rm /usr/local/include/LinkedList.cpp
	rm /usr/local/bin/monsun
	rm /usr/local/include/monsun.h

gtest:
	cd $(BUILD_DIR) && ctest $(ARGS)

doc: build/* doc/docgen
	cd $(BUILD_DIR) && make doc

run:
	cd $(BUILD_DIR) && $(EXE)

clean:
	rm -rf $(BUILD_DIR)
