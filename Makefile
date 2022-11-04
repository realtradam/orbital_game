# Thanks to Job Vranish (https://spin.atomicobject.com/2016/08/26/makefile-c-projects/)
TARGET_EXEC := final_program

# web platform build doesnt work
TARGET_PLATFORM ?= DESKTOP

ifeq ($(TARGET_PLATFORM),DESKTOP)
	BUILD_DIR := build/desktop
	RAYLIB_FLAGS := -lGL -lm -lpthread -ldl -lrt -lX11
endif
# web doesnt work
ifeq ($(TARGET_PLATFORM),WEB)
	BUILD_DIR := build/web
	RAYLIB_FLAGS := -Os -Wall -s USE_GLFW=3 -s ASYNCIFY -DPLATFORM_WEB
	CXX := em++
	CC := emcc
endif
SRC_DIRS := src

RAYLIB_SRC := vendor/raylib/src
RAYLIB_LIB := $(BUILD_DIR)/raylib/libraylib.a

# Find all the C and C++ files we want to compile
# Note the single quotes around the * expressions. Make will incorrectly expand these otherwise.
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')

# String substitution for every C/C++ file.
# As an example, hello.cpp turns into ./build/hello.cpp.o
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

# String substitution (suffix version without %).
# As an example, ./build/hello.cpp.o turns into ./build/hello.cpp.d
DEPS := $(OBJS:.o=.d)

# Every folder in ./src will need to be passed to GCC so that it can find header files
INC_DIRS := $(shell find $(SRC_DIRS) -type d) $(RAYLIB_SRC)

# Add a prefix to INC_DIRS. So moduleA would become -ImoduleA. GCC understands this -I flag
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# The -MMD and -MP flags together generate Makefiles for us!
# These files will have .d instead of .o as the output.
CPPFLAGS := $(INC_FLAGS) -MMD -MP

# The final build step.
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS) raylib
	$(CXX) $(OBJS) -o $@ $(LDFLAGS) $(RAYLIB_LIB) $(RAYLIB_FLAGS)

run: $(BUILD_DIR)/$(TARGET_EXEC)
	./$(BUILD_DIR)/$(TARGET_EXEC)


# Build step for C source
$(BUILD_DIR)/%.c.o: %.c raylib
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Build step for C++ source
$(BUILD_DIR)/%.cpp.o: %.cpp raylib
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

#vendor/raylib/src/libraylib.a
raylib: 
ifeq ($(TARGET_PLATFORM),DESKTOP)
	$(MAKE) -C vendor/raylib/src
	mkdir -p $(BUILD_DIR)/raylib
	cp vendor/raylib/src/libraylib.a $(RAYLIB_LIB)
endif
ifeq ($(TARGET_PLATFORM),WEB)
	$(MAKE) PLATFORM=PLATFORM_WEB -B -e -C vendor/raylib/src
	mkdir -p $(BUILD_DIR)/raylib
	cp vendor/raylib/src/libraylib.a $(RAYLIB_LIB)
endif

.PHONY: clean
clean:
	rm -r build

# Include the .d makefiles. The - at the front suppresses the errors of missing
# Makefiles. Initially, all the .d files will be missing, and we don't want those
# errors to show up.
-include $(DEPS)