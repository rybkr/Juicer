CXX=clang++
STD=c++23
CXXFLAGS=-O3 -Wall -Wextra -pedantic
INCLUDES=-I./ -I./movegen/ -I./tests/static/

.PHONY: hunt

hunt: ./movegen/magics/hunt.cpp
	$(CXX) -std=$(STD) $(CFLAGS) $(INCLUDES) -I./movegen/magics/ ./movegen/magics/hunt.cpp ./movegen/magics/persistence.cpp -o ./movegen/magics/hunt && ./movegen/magics/hunt
