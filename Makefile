###############################################################################
# Author: Sean Foster         																			<Makefile>
# Date: 10/15/2017
# Description: Makefile for Lab 04: OSU Information System
###############################################################################
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = menu.o validator.o num.o

SRCS = menu.cpp validator.cpp num.cpp

HEADERS = menu.hpp validator.hpp 

#target: dependencies
#		rule to build

num: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o num

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o num