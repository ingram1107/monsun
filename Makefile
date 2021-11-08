BUILD_DIR=build
CMAKE=cmake
CMAKE_FLAGS=-DBUILD_DOCS=ON
CMAKE_FLAGS+=-DENABLE_TUI=ON
CMAKE_FLAGS+=-S . -B $(BUILD_DIR)
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

# uninstall:
# 	rm /usr/local/lib/libadder.a
# 	rm /usr/local/include/adder.h
# 	rm /usr/local/lib/libglfw3.a
# 	rm -rf /usr/local/include/GLFW
# 	rm -rf /usr/local/cmake/glfw3
# 	rm /usr/local/lib/pkgconfig/glfw3.pc
# 	rm /usr/local/bin/olas

gtest:
	cd $(BUILD_DIR) && ctest

run:
	cd $(BUILD_DIR) && $(EXE)

clean:
	rm -rf $(BUILD_DIR)
