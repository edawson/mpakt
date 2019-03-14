CXX:=g++
CXXFLAGS:=-O3 -g -std=c++11

test: test.cpp mpakt.hpp
	$(CXX) $(CXXFLAGS) -o $@ $< && ./test
	
.PHONY: test
