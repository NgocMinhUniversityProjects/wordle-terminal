//stores a set of possible words
#pragma once
#include "./word.h"
#include "./tree.h"
#include "./utils.h"
#include <fstream>

//immutable
class Dictionary {
    private:
        Tree * collection = new Tree();
        int s = 0;

    public:
        //reads every line of the file into the dictionary, discards invalids
        Dictionary(std::string filename);
        ~Dictionary(){delete this->collection;};
        int size(){return this->s;};
        Word getRandomWord();
        bool isWordInDictionary(Word);
};