#include "scene.h"

Scene::Scene(std::string initial, bool doPrintNewLine, int waitForInputLen){
    this->str = initial;
    this->doPrintNewLine = doPrintNewLine;
    this->waitForInputLen = waitForInputLen;
}

void Scene::addLine(std::string str){
    this->str += "\n" + str;
}

void Scene::add(std::string str){
    this->str += str;
}

void Scene::setDirect(int pos, char c){
    this->str[pos] = c;
}

void Scene::print(Printer& p){
    p.clear();
    p.move_cursor(0, 0);

    std::string s = "";
    std::string t = this->str + "\n" + this->temp;
    for(int i = 0; i < t.length(); i++){
        if(t[i] != '\n'){
            s += t[i];
        } else {
            p.println(s);
            s = "";
        }
    }

    if(s.length() != 0){
        p.print(s);
    }

    p.render(this->doPrintNewLine);
    if(this->waitForInputLen >= 0){
        p.getInput(this->waitForInputLen);
    }
}