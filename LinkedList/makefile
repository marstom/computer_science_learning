test:
	@echo "unittest has now separate makefile in unittest folder"

speed:
	@echo "*********Test Linked List speed C++ with 50M elements!*********"
	g++ -std=c++11 -Wall -Wextra speed_test.cpp -o speed.out
	./speed.out
	@echo "C++ with O3"
	g++ -std=c++11 -O3 speed_test.cpp -o speed.out
	./speed.out
	@echo "Python list() 50M list append time ..."
	python python_list.py
	@echo "*****************Test Finished!*********************************"


clean:
	rm speed.out

