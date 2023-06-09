CC = g++
CFLAGS = -std=c++17 -Wall -Werror -Wextra
GCOV_FLAG = -fprofile-arcs -ftest-coverage -fPIC -O0
GCOV_FLAG_TEST = --coverage
TEST_FLAG = -lgtest
OPEN = open

ifeq ($(shell uname), Linux)
	OPEN = xdg-open
endif

SOURCES_1 = calculations.cc parser.cc validation.cc credit_calculations.cc
OBJECTS_1 = calculations.o parser.o validation.o credit_calculations.o
SOURCES_2 = test/test.cc
OBJECTS_2 = test.o

.PHONY: all
all: clean

calc.a: clean
	$(CC) $(CFLAGS) -c $(SOURCES_1)
	ar rc calc.a $(OBJECTS_1)
	ranlib calc.a
	-rm -rf *.o

test_calc.a: clean
	$(CC) $(CFLAGS) $(GCOV_FLAG) -c $(SOURCES_1)
	ar rc calc.a $(OBJECTS_1)
	ranlib calc.a
	-rm -rf *.o

.PHONY: test
test: clean test_calc.a
	$(CC) $(CFLAGS) -c $(SOURCES_2)
	$(CC) $(CFLAGS) $(GCOV_FLAG_TEST) -o tests $(OBJECTS_2) calc.a $(TEST_FLAG)
	-rm -rf *.o
	./tests

.PHONY: gcov_report
gcov_report: clean test
	gcovr -r . --html-details -o report_calc.html
	$(OPEN) report_calc.html
	
.PHONY: clean
clean:
	-rm -rf *.o *.a *.out *.gcda *.gcno *.css *.html
	-rm -rf tests
	
.PHONY: style
style:
	clang-format -n -style=Google *.cc *.h
	

.PHONY: valgrind
valgrind:
	valgrind --leak-check=full -q  -s --track-origins=yes ./tests