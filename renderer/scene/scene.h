#pragma once
#include "../printer/printer.h"

class Scene {
    std::string str;
    std::string temp = "";
    bool doPrintNewLine;
    int waitForInputLen;
    public:
        Scene(std::string initial = "", bool doPrintNewLine = true, int waitForInputLen = -1);
        void print(Printer&);
        void add(std::string);
        void addLine(std::string);
        void setDirect(int pos, char c);
        void setTemp(std::string s){this->temp = s;};
        void setWaitLen(int x){this->waitForInputLen = x;};
};