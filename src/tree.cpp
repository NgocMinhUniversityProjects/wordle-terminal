#include "../abstract/tree.h"

void Tree::__free(Node * n){
    for(int i = 0; i < n->numValid; i++){
        if(n->nextArr[i] != nullptr){
            this->__free(n->nextArr[i]);
        }
    }
    free(n);
}

Tree::~Tree(){
    if(this->root != nullptr){
        this->__free(this->root);
    }
}

int Tree::insert(std::string x){
    if(x.length() != 5) return -1;

    Node * curr = this->root;

    for(int i = 0; i < 5; i++){
        int offset = x[i] - 'a';
        if(offset < 0 || offset >= 26) return -1;
        if(curr->nextArr[offset] == nullptr) {
            curr->numValid++;
            curr->nextArr[offset] = new Node();
        }
        curr = curr->nextArr[offset];
    }

    return 0;
}

bool Tree::inTree(std::string x){
    if(x.length() != 5) return false;

    Node * curr = this->root;

    for(int i = 0; i < 5; i++){
        int offset = x[i] - 'a';
        if(offset < 0 || offset >= 26) return false;
        if(curr->nextArr[offset] == nullptr) return false;
        curr = curr->nextArr[offset];
    }
    return true;
}

std::string Tree::getRandom(){
    std::string ret = "";

    Node * curr = this->root;

    for(int i = 0; i < 5; i++){
        int randomDir;
        if(curr->numValid <= 1){
            randomDir = 0;
        } else randomDir = utils::rng(curr->numValid - 1, 0);

        for(int j = 0; j < 26; j++){
            if(curr->nextArr[j] != nullptr){
                if(randomDir == 0){
                    ret += (char)('a' + j);
                    curr = curr->nextArr[j];
                    break;
                } else randomDir--;
            }
        }  
    }
    return ret;
}

void Tree::__debug(Node * n, int d, int pos){
    if(n == nullptr) return;
    if(n->numValid == 0) return;
    std::string s = "[";
    for(int i = 0; i < 26; i++){
        if(n->nextArr[i] == nullptr) s += '#';
        else s += (char) 'a' + i;
    }
    s += "]";
    printf("depth: %d, pos %d: %s\n", d, pos, s.c_str());

    for(int i = 0; i < 26; i++){
        this->__debug(n->nextArr[i], d + 1, i);
    }
}

void Tree::__debug(){
    this->__debug(this->root, 0);
}