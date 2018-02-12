Readme

Example google-test usage:

$ export GTEST_HOME=~/usr/gtest
    $ export LD_LIBRARY_PATH=$GTEST_HOME/lib:$LD_LIBRARY_PATH
    $ g++ -I $GTEST_HOME/include -L $GTEST_HOME/lib -lgtest -lgtest_main -lpthread test.cpp

