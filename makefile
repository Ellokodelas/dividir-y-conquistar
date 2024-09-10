# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Source files
SRCS = main.cpp resultados.cpp lector.cpp ordena/bublesort.cpp ordena/quicksort.cpp ordena/mergesort.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = miprograma

# Additional source files for 'm'
SRCS_M = main_m.cpp resultados_m.cpp lector_m.cpp matrices/i-c-o.cpp matrices/i-c-t.cpp matrices/strassen.cpp 
OBJS_M = $(SRCS_M:.cpp=.o)
TARGET_M = programa_m

# Default target: build, run, and clean
all: $(TARGET) run clean

# Build the executable
$(TARGET): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@

# Compile source files into object files
%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	@./$(TARGET)

# Clean up
clean:
	@rm -f $(TARGET) $(OBJS) $(TARGET_M) $(OBJS_M)

# Compile, run and clean 'generar.cpp'
generar: generador.o
	@$(CXX) $(CXXFLAGS) generador.o -o generador
	@./generador
	@rm -f generador generador.o

# Compile, run and clean 'generar_m.cpp'
generar_m: generador_m.o
	@$(CXX) $(CXXFLAGS) generador_m.o -o generador_m
	@./generador_m
	@rm -f generador_m generador_m.o

# Compile, run, and clean the program 'm'
m: $(OBJS_M)
	@$(CXX) $(CXXFLAGS) $(OBJS_M) -o $(TARGET_M)
	@./$(TARGET_M)
	@rm -f $(TARGET_M) $(OBJS_M)


