#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#include <iostream>
#include <map>
#include <vector>

#define CHAR( text ) ((char*)std::string( text ).c_str())

class smartPerf {
    public: 
        smartPerf();
        ~smartPerf();
        static void start(const char *name = "default");
        static void clear();
        static clock_t end(bool displayResult = true);
        static void print();
    private:
        static void printByWidth(char* str, int maxWidth);

        static std::map<std::string, clock_t> timeData;
        static std::vector<std::pair<std::string, clock_t> > recordData;
        static char *lastItemName;
};

