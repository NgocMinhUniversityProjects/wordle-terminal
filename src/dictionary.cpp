#include "../abstract/dictionary.h"

Dictionary::Dictionary(std::string filename){
    std::string line;
    bool sx = false;

    std::ifstream file(filename);

    while (getline(file, line)) {
        if(utils::isValidWord(line)) {
            this->collection->insert(line);
            this->s++;
        }
        sx = true;    
    }

    file.close();

    if(sx == false){
        throw filename;
    }
}

Word Dictionary::getRandomWord(){
    return Word(this->collection->getRandom());
}

bool Dictionary::isWordInDictionary(Word x){
    std::string s = "";
    for(int i = 0; i < 5; i++){
        s += x.getCharAtPos(i);
    }

    return this->collection->inTree(s);
}
