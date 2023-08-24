CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11 #-fsanitize=address -g
VALGRIND=valgrind --leak-check=full --leak-resolution=med -s
OS:= $(shell uname -s)
LINFLAGS=-lcheck -pthread -lrt -lm -lsubunit
#TC_FLAGS += $(shell pkg-config --cflags check) $(shell pkg-config --libs check)

ifeq ($(OS), Linux)
	FLAGS = -lcheck -lm -lpthread -lrt -lsubunit 
	LEAKS = CK_FORK=no valgrind  --leak-check=full  --track-origins=yes  ./test
else
	FLAGS = -lcheck
	LEAKS = leaks -atExit -- ./test
endif

all: clean test

calculator.a:
	gcc $(CFLAGS) $(LINFLAGS) -c calculator.c 
	ar r calculator.a  calculator.o
	ranlib calculator.a

test: calculator.a
ifeq ($(OS), Darwin)
	gcc test.c calculator.a  -o test `pkg-config --cflags --libs check` -lcheck -lpthread #-fsanitize=address
	./test
else
	gcc test.c calculator.a -o test $(LINFLAGS)
	./test
endif

gcov_report: clean
ifeq ($(OS), Darwin)
	gcc --coverage test.c -o test calculator.c `pkg-config --cflags --libs check`
	./test
	gcov -f calculator.gcda
	lcov -t "test" -o test.info -c -d .   
	genhtml -o report test.info
	open ./report/index.html
else
	gcc --coverage test.c -o test calculator.c $(LINFLAGS)
	./test
	gcov -f calculator.gcda
	lcov -t "test" -o test.info -c -d .  
	genhtml -o report test.info
	xdg-open ./report/index.html
endif

install: uninstall
	mkdir -p build
	qmake6 SmartCalc/SmartCalc.pro -o build/Makefile
	cd build; make > /dev/zero 2> /dev/zero
	mkdir -p ~/Applications/SmartCalc.app/Contents/Resources ; cp -r SmartCalc/icon.icns ~/Applications/SmartCalc.app/Contents/Resources/icon.icns
	cp -r build/SmartCalc.app ~/Applications/SmartCalc.app

uninstall: clean
	rm -rf build
	rm -rf ~/Applications/SmartCalc.app

dist:
	cd .. && tar -czvf SmartCalc.tar src

dvi:
	open SmartCalc/dvi.html

check: clean cppcheck style leaks

cppcheck: test
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

valgrind: test
	CK_FORK=no valgrind  --leak-check=full  --track-origins=yes  ./test
	
style: test
	cp ../materials/linters/.clang-format .clang-format
	# clang-format -style=google -i *.c *.h *.cpp
	clang-format -style=google -n *.c *.h SmartCalc/*.cpp SmartCalc/*.h
	rm .clang-format 

leaks: test
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./test
	rm -rf calculator.o
else
	#sudo dnf install valgrind
	$(VALGRIND) --leak-check=full --show-leak-kinds=all ./test
	rm -rf calculator.o
endif

clean:
	rm -rf *.o *.a *.out *.gcda *.gcno 
	rm -rf test a.out 
	rm -rf *.info && rm -rf *.gcov
	rm -rf build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Debug/
	rm -rf ./report/
