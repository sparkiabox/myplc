CXX = g++
CFLAGS = -O2

# Source files for the library (from src/myplc_cpp/)
LIB_SOURCES = $(wildcard src/myplc_cpp/*.cpp)
LIB_OBJECTS = $(patsubst src/myplc_cpp/%.cpp,src/myplc_obj/%.o,$(LIB_SOURCES))
LIBRARY = libmyplc.a

# Source files for the executable (from user_code/src/)
USER_SOURCES = $(wildcard user_code/src/*.cpp)
USER_OBJECTS = $(patsubst user_code/src/%.cpp,user_code/obj/%.o,$(USER_SOURCES))
EXECUTABLE = runtime

# Default target: build both the library and the executable
all: dirs $(LIBRARY) $(EXECUTABLE)

# Create directories explicitly
dirs:
	@mkdir -p src/myplc_obj user_code/obj

# Link the user objects with the library to create the executable
$(EXECUTABLE): $(USER_OBJECTS) $(LIBRARY)
	$(CXX) $(USER_OBJECTS) -L. -lmyplc -o $@

# Build the library from its object files
$(LIBRARY): $(LIB_OBJECTS)
	ar rcs $@ $^

# Compile library source files into object files in src/myplc_obj/
src/myplc_obj/%.o: src/myplc_cpp/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

# Compile user source files into object files in user_code/obj/
user_code/obj/%.o: user_code/src/%.cpp
	$(CXX) $(CFLAGS) -I../src -c $< -o $@

# Clean up
clean:
	rm -rf $(LIBRARY) $(EXECUTABLE) src/myplc_obj user_code/obj