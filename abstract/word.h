//a wordle word can be abstracted
#pragma once
#include <string>

//immutable
class Word {
    private:
        char letterArr[5];
    public:
        Word(std::string s = "aaaaa");
        ~Word(){};
        int getCount(char);
        char getCharAtPos(int);
        std::string toStr(){return std::string(this->letterArr, 5);};
};