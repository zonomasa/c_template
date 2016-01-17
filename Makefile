#
#  Makefile
#
#  Copyright (c) 2016 Masaki TATEZONO
#
#  This software is released under the MIT License.
#  http://opensource.org/licenses/mit-license.php
#

DOXYGEN    = doxygen

CC         = gcc
CFLAGS     = -Wall -W -Wextra -O2 -g

LIB_NAME   = lib/liblibrary.so
LIB_OBJ    = src/library.o
LIB_FLAGS  = -fPIC

MAIN_NAME  = bin/main.exe
MAIN_OBJ   = src/main.o
MAIN_FLAGS = -L./lib -llibrary

TEST_NAME  = bin/test.exe
TEST_OBJ   = test/test.o
TEST_FLAGS = -I../src -L./lib -llibrary -lcunit

all:library main test doc run

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

library:$(LIB_OBJ)
	@mkdir -p lib
	$(CC) $(LIB_FLAGS) -shared -o $(LIB_NAME) $<

main:$(MAIN_OBJ)
	@mkdir -p bin
	$(CC) -o $(MAIN_NAME) $< $(MAIN_FLAGS)

test:$(TEST_OBJ)
	@mkdir -p bin
	$(CC) -o $(TEST_NAME) $< $(TEST_FLAGS) 

doc:
	echo "nothing to do"


run:
	LD_LIBRARY_PATH=./lib $(MAIN_NAME)

check:
	LD_LIBRARY_PATH=./lib valgrind -v --error-limit=no --leak-check=yes --show-reachable=no ./$(MAIN_NAME)
	LD_LIBRARY_PATH=./lib ./$(TEST_NAME)

clean:
	rm -f *~ $(LIB_NAME) $(LIB_OBJ) $(MAIN_NAME) $(MAIN_OBJ) $(TEST_NAME) $(TEST_OBJ)
