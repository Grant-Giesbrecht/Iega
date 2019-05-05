# To install IEGA on your system, modify this file to contain the correct directories
# if you'd like to install them in a custom location. Once you are satisfied with the
# install location, run 'make -f makefile install' (without the quote marks).

#
# This will install KMatrix, string_manip, stdutil, KTable, & KVector
#

CC = clang++ -std=c++11

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
	cp *.hpp $(IEGA_INCLUDE)
	cp *.cpp $(IEGA_SRC)
	cp *.o $(IEGA_LIB_OBJS)
	ar rvs $(IEGA_LIB)$(ARCHIVE_FILE) $(DIR_OBJECT_FILES)
