all: main.cpp ./src/global.cpp ./src/faculty.cpp ./src/login.cpp ./src/signup.cpp ./src/table_manage.cpp
	g++ -o "./build/app" main.cpp ./src/global.cpp ./src/faculty.cpp ./src/login.cpp ./src/signup.cpp ./src/table_manage.cpp

run:
	./build/app

clean:
	rm -f ./build/*

clean(win):
	del /f build\*

headers: ./include/global.hh ./include/faculty.hh ./include/login.hh ./include/signup.hh ./include/table_manage.hh 
	g++ ./include/global.hh ./include/faculty.hh ./include/login.hh ./include/signup.hh ./include/table_manage.hh