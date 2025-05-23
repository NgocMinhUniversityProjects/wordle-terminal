#pragma once
#include <stdlib.h>
#include <ctime>
#include <string>

class utils {
    public:
        utils(){};
        ~utils(){};
        //max and min inclusive
        static int rng(int max, int min);
        static bool isValidWord(std::string);
};
