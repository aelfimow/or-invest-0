CXXFLAGS += -O2
CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -pedantic
CXXFLAGS += -Weffc++
CXXFLAGS += -std=c++17
CXXFLAGS += -Werror
CXXFLAGS += --all-warnings
CXXFLAGS += --extra-warnings
CXXFLAGS += -Wconversion
CXXFLAGS += -Wconversion-null
CXXFLAGS += -Wdiv-by-zero
CXXFLAGS += -Wfloat-conversion
CXXFLAGS += -Wfloat-equal

all: main.o Investment.o
	${CXX} main.o Investment.o -o main.exe

main.o: main.cpp
	${CXX} -c main.cpp -o main.o ${CXXFLAGS}

Investment.o: Investment.cpp Investment.h Types.h
	${CXX} -c Investment.cpp -o Investment.o ${CXXFLAGS}
