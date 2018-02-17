test:
	g++ -std=gnu++11 -g -Wall -Wextra -pedantic tests.cpp
	./a.out

speed:
	g++ -std=c++11 -Wall -Wextra speed_test.cpp -o speed.out
	./speed.out
	echo "with O3"
	g++ -std=c++11 -O3 speed_test.cpp -o speed.out
	./speed.out
	echo "Python 50M list append time ..."
	python python_list.py
	echo "Test Finished!"

clean:
	rm a.out
	rm test.out

