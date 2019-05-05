# To install IEGA on your system, modify this file to contain the correct directories
# if you'd like to install them in a custom location. Once you are satisfied with the
# install location, run 'make -f makefile install' (without the quote marks).

#
# This will install KMatrix, string_manip, stdutil, KTable, & KVector
#

ifeq ($(OS),Windows_NT)
    CCFLAGS += -D WIN32
    ifeq ($(PROCESSOR_ARCHITEW6432),AMD64)
        #Windows things...
    else
        ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
            #Windows things...
        endif
        ifeq ($(PROCESSOR_ARCHITECTURE),x86)
            #Windows things...
        endif
    endif
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        CC = g++ -std=c++11
    endif
    ifeq ($(UNAME_S),Darwin)
        CC = clang++ -std=c++11
    endif
endif

# CC = clang++ -std=c++11

#Where hpp files are saved
IEGA_INCLUDE = /usr/local/include/IEGA

#Where object file is saved
IEGA_LIB = /usr/local/lib/

IEGA_LIB_OBJS = /usr/local/lib/IEGA\ source/Objects/

#Where cpp files are saved
IEGA_SRC = /usr/local/lib/IEGA\ source

#==============================================================================#
#============ YOU SHOULD NOT NEED TO MODIFY ANYTHING BELOW THIS LINE ==========#
#==============================================================================#

#Archive file name
ARCHIVE_FILE = libIEGA.a

#Object files to keep in archive with '$(IEGA_LIB_OBJS)' appended in front of each entry. (I know
#this is tedious, but it saves copying things all around your hard drive).
DIR_OBJECT_FILES = $(IEGA_LIB_OBJS)KMatrixHelpers.o $(IEGA_LIB_OBJS)string_manip.o $(IEGA_LIB_OBJS)stdutil.o $(IEGA_LIB_OBJS)KVar.o $(IEGA_LIB_OBJS)KTable.o

#Compile all files
all: KMatrixHelpers.cpp  string_manip.cpp stdutil.cpp KVar.cpp KTable.cpp
	$(CC) -c KMatrixHelpers.cpp
	$(CC) -c string_manip.cpp
	$(CC) -c stdutil.cpp
	$(CC) -c KVar.cpp
	$(CC) -c KTable.cpp

#Install IEGA on your system...
install: all
	sudo mkdir -p $(IEGA_INCLUDE)
	sudo mkdir -p $(IEGA_LIB)
	sudo mkdir -p $(IEGA_LIB_OBJS)
	sudo mkdir -p $(IEGA_SRC)
	sudo cp *.hpp $(IEGA_INCLUDE)
	sudo cp *.cpp $(IEGA_SRC)
	sudo cp *.o $(IEGA_LIB_OBJS)
	sudo ar rvs $(IEGA_LIB)$(ARCHIVE_FILE) $(DIR_OBJECT_FILES)
