# Tomasz Marszalek's Coding Interview University #
#### About:
- This repo is a based on [Jwasham's Coding Interview University](https://github.com/jwasham/coding-interview-university)
- I implement everything in C, C++

##### Content:
* Linked lists

# How to use it
#### How to run tests?
1. First install google-test (I do it so on my Linux Mint):
```bash
sudo apt-get install libgtest-dev
sudo apt-get install cmake # install cmake
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp *.a /usr/lib
```

2. How to run unittests?
* In unittest folder:
```bash
cmake CMakeLists.txt
make
./runTests.out # run all unittests
```

