#include "../abstract/utils.h"

int utils::rng(int max, int min){
    srand(time(0) + rand());
    return (rand() % (max - min + 1)) + min;
}

bool utils::isValidWord(std::string x){
    if(x.length() < 5) return false;
    for(int i = 0; i < 5; i++){
        if(x[i] > 'z' || x[i] < 'a') return false;
    }
    return true;
}