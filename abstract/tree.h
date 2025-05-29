#pragma once
#include <string>
#include "./utils.h"

class Tree {
    class Node {
        public:
            Node * nextArr[26];
            int numValid;
            Node(){
                for(int i = 0; i < 26; i++){
                    this->nextArr[i] = nullptr;
                }
                this->numValid = 0;
            };
            ~Node(){};
    };

    Node * root = new Node();
    void __free(Node *);

    public:
        Tree(){};
        ~Tree();
        int insert(std::string);
        std::string getRandom();
        bool inTree(std::string);
        void __debug(Node *, int d = 0, int pos = 0);
        void __debug();
};
