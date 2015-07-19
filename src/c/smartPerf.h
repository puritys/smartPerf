#include <stdio.h>
#include <time.h>
#include <string.h>

#include <iostream>
#include <map>

class smartPerf {
    public: 
        smartPerf();
        ~smartPerf();
        void start(const char *name = "");
        void end(bool displayResult);
        void print();
    private:
        std::map<char*, size_t> timeData;

};

