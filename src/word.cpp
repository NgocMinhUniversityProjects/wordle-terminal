#include "../abstract/word.h"

Word::Word(std::string x){
    for(int i = 0; i < 5; i++){
        this->letterArr[i] = x[i];
    }
};

int Word::getCount(char x){
    int c = 0;
    for(int i = 0; i < 5; i++){
        if(this->letterArr[i] == x) c++;
    }
    return c;
};

char Word::getCharAtPos(int x){
    if(x < 0 || x >= 5) return '\0';
    return this->letterArr[x];
}