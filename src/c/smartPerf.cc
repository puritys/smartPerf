#include "smartPerf.h"

std::map<std::string, clock_t> smartPerf::timeData;
std::map<std::string, clock_t> smartPerf::recordData;
char* smartPerf::lastItemName = (char*)malloc(sizeof(char) * 51);

void smartPerf::clear() {/*{{{*/
    while (!timeData.empty()) {
        timeData.erase(timeData.begin());
    }
}/*}}}*/

void smartPerf::start(const char *name) {/*{{{*/
    if (strlen(name) >= 50) {
        throw std::runtime_error("The name of perf is too long. Please keep the length of name to be small than 50.");
    }
    std::map<std::string, clock_t>::iterator it;
    it = timeData.find(name);
    clock_t startTime = clock();

    if (it == timeData.end()) {
        std::pair<std::string, clock_t> d(name, startTime);
        timeData.insert(d);
    } else {
        it->second = startTime;
    }

    int len = strlen(name);
    strncpy(lastItemName, name, len);
    lastItemName[len] = '\0';
}/*}}}*/

clock_t smartPerf::end(bool displayResult) {/*{{{*/

    clock_t end = clock();
    clock_t start, diffMs, diffUs;
    char* key = (char*) malloc(sizeof(key) * 51);
    memset(key, '\0', 51);
    char defaultKey[8] = "default";
    strcpy(key, lastItemName);


    std::map<std::string, clock_t>::iterator it;

    timeData.rbegin();
    it = timeData.find(lastItemName);

    if (it == timeData.end()) {
        it = timeData.find(defaultKey);
        strncpy(key, defaultKey, 7);
        *(key + 7) = '\0';
    }

    if (it == timeData.end()) {
        throw std::runtime_error("Can not find the perf keyname.");
    }

    start = it->second;

    diffUs = (end - start);
    diffMs = diffUs / 1000;
    
    if (displayResult == true) {
        printf("%s: Time diff = %lu ms %lu us\n", key, diffMs, diffUs);
    }
    std::pair<std::string, clock_t> p(key, diffUs);
    recordData.insert(p);
    free(key);
    return diffMs;
}/*}}}*/

void smartPerf::print() {
    std::map<std::string, clock_t>::iterator it;
    int maxKeyLength = 1, maxWidth = 10;

    for(it = recordData.begin(); it != recordData.end(); ++it) {
        if ((int)it->first.size() > maxKeyLength) maxKeyLength = it->first.size();
    }
    if (maxKeyLength > 10) maxWidth = maxKeyLength + 2;

    // generate border
    char *border = (char*) malloc(sizeof(char) * (maxWidth*3 + 10));
    border[0] = '+';
    for (int i = 0 ; i < maxWidth*3 + 5; i++)  border[i+1] = '-';
    border[maxWidth*3 + 6] = '+';
    border[maxWidth*3 + 7] = '\n';
    border[maxWidth*3 + 8] = '\0';
    printf("%s", border);
    
    printf("|");
    printByWidth(CHAR("Key"), maxWidth);
    printf("|");
    printByWidth(CHAR("CPU(ms)"), maxWidth);
    printf("|");
    printByWidth(CHAR("CPU(us)"), maxWidth);
    printf("|\n");

    printf("%s", border);



    char buffer[32];

    for(it = recordData.begin(); it != recordData.end(); ++it) {
        printf("|");
        printByWidth((char*)it->first.c_str(), maxWidth);
        printf("|");
        sprintf(buffer, "%lu ms", it->second/1000);
        printByWidth(buffer, maxWidth);
        printf("|");
        sprintf(buffer, "%lu us", it->second);
        printByWidth(buffer, maxWidth);
        printf("|\n");
        //printf("| %s |%lu | \n", it->first.c_str(), it->second);
    }

    printf("%s", border);



}


void smartPerf::printByWidth(char* str, int maxWidth) {
    int length, left, right, i;
    length = strlen(str) - 1;
    length = maxWidth - length;
    if (length > 0 ) {
        left = (length / 2);
        if (length % 2 ==1 ) left++;
        for(i = 0; i < left; i++ ) printf(" ")
;
        printf("%s", str);
        right = length - left;
        for(i = 0; i < right; i++ ) printf(" ")
;
    }
}


