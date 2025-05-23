#include "../abstract/gameManager.h"
#include "../renderer/fullTerminalPrinter.h"

gameManager::gameManager(){
    this->randomDict = new Dictionary("dict/la.txt");
    this->guessableDict = new Dictionary("dict/ta.txt");
}

Scene gameManager::getScene(enum sceneID id){
    switch (id) {
    case main_menu: {
        Scene res = Scene("", false, 1);
        res.addLine("Welcome to wordle!");
        res.addLine("");
        res.addLine("Choose an option (Enter to confirm):");
        res.addLine("1. Play!");
        res.addLine("2. Read rules");
        res.addLine("3. Credit");
        res.addLine("Enter anything else to exit");
        res.setTemp("> ");
        return res;
    }
    case rules: {
        Scene res = Scene("", false, 0);
        res.addLine("The game of wordle is a word guessing game!");
        res.addLine("");
        res.addLine("The game first chooses a secret 5 letter word.");
        res.addLine("Your task is to guess the secret word within 6 tries.");
        res.addLine("");
        res.addLine("After you make a guess, colored letters appears for each letter:");
        res.addLine("\x1b[38:5:9m X : Red X\x1b[0m - This letter does not appear in the secret word.");
        res.addLine("\x1b[38:5:11m # : Yellow #\x1b[0m - This letter appears in the secret word but not in this spot.");
        res.addLine("\x1b[38:5:10m O : Green O\x1b[0m - This letter appears in the secret word and in this spot.");
        res.addLine("Tip: If the secret word has 2 letter 'a' and your guess has 3 letter 'a', only 2 will be marked yellow or green, 1 will be red.");
        res.addLine("Press enter to quit back to main menu.");
        res.setTemp("> ");
        return res;
    }
    case credit: {
        Scene res = Scene("", false, 0);
        res.addLine("Made in May 2025 by Ngoc Minh as a university project (allias BlueG15)");
        res.addLine("");
        res.addLine("Press enter to quit back to main menu.");
        res.setTemp("> ");
        return res;
    }
    case play: {
        Scene res = Scene("6 <- Numer of guesses left", false, 5);
        res.addLine("");
        res.setTemp("Enter your guess (only 5 letters will be taken):\n> ");
        return res;
    }

    case exit: {
        Scene res = Scene("Good bye~");
        return res;
    }
    
    default:
        return Scene();
    }
}

void gameManager::step(){
    this->currScene.print(printer);
    switch(this->currSceneID){
        case main_menu: {

            if(printer.lastInputLen != 1){
                this->currScene = getScene(exit);
                this->currSceneID = exit;
                return;
            }

            switch(printer.inputBuffer[0]){
                case '1': {
                    this->currScene = getScene(play);
                    this->currSceneID = play;
                    this->lives = 6;
                    this->hiddenWord = this->randomDict->getRandomWord();
                    return;
                }

                case '2': {
                    this->currScene = getScene(rules);
                    this->currSceneID = rules;
                    return;
                }

                case '3': {
                    this->currScene = getScene(credit);
                    this->currSceneID = credit;
                    return;
                }

                default: {
                    this->currScene = getScene(exit);
                    this->currSceneID = exit;
                    return;
                }
            }
        }

        case finish:
        case rules: //fall through
        case credit: {
            this->currScene = getScene(main_menu);
            this->currSceneID = main_menu;
            return;
        }

        case play: {

            std::string s = string(printer.inputBuffer, 5);
            Word cWord = Word(s);
            if(utils::isValidWord(s)){
                if(this->randomDict->isWordInDictionary(cWord) || this->guessableDict->isWordInDictionary(cWord)){

                    std::string com = this->compare(cWord);

                    if(this->lives != 1){
                        this->lives--;
                        this->currScene.setDirect(0, (char) this->lives + '0');
                        this->currScene.addLine("You guessed: " + s);
                        this->currScene.addLine(string("Checked:    |") + com + "|");
                        this->currScene.addLine("");

                        if(this->lives == 100){
                            this->currScene.setTemp("You Won!!!!! the word was: \x1b[38:5:10m " + this->hiddenWord.toStr() + " \x1b[0m\n\nPress Enter to return to main menu\n> ");
                            this->currScene.setWaitLen(0);
                            this->currSceneID = finish;
                        } else {
                            this->currScene.setTemp("Enter your guess (only 5 letters will be taken):\n> ");
                        }
                    } else {
                        this->currScene.setDirect(0, '0');
                        this->currScene.addLine("You guessed: " + s);
                        this->currScene.addLine(string("Checked:    |") + com + "|");
                        this->currScene.addLine("");

                        if(this->lives == 100){
                            this->currScene.setTemp("You Won!!!!! (just barely >.<) the word was: \x1b[38:5:10m " + this->hiddenWord.toStr() + " \x1b[0m\n\nPress Enter to return to main menu\n> ");
                            this->currScene.setWaitLen(0);
                            this->currSceneID = finish;
                        } else {
                            this->currScene.setTemp("You lost, the word was: \x1b[38:5:10m " + this->hiddenWord.toStr() + " \x1b[0m\n\nPress Enter to return to main menu\n> ");
                            this->currScene.setWaitLen(0);
                            this->currSceneID = finish;
                        }
                    }
                } else {
                    this->currScene.setTemp("Wrong input!, word not in recognizable dictionary!\n> ");
                }
            } else {
                this->currScene.setTemp("Wrong input!, please input a lower cased word of length 5!\n> ");
            }
            return;
        }

        default: return;

    }

    memset(printer.inputBuffer, '\0', printer.lastInputLen);
};


void gameManager::loop(){
    while(true){
        if(this->currSceneID != exit){
            this->step();
        } else {
            this->step();
            return;
        }
    }
}

std::string gameManager::compare(Word w){
    std::string res = "_____";
    char greenOrYellowCounter[26];
    memset(greenOrYellowCounter, 0, 26);
    int x = 0;
    for(int i = 0; i < 5; i++){
        char a = this->hiddenWord.getCharAtPos(i);
        char b = w.getCharAtPos(i);
        if( a == b ) {
            res[i] = 'O';
            greenOrYellowCounter[b - 'a']++;
            x++;
        }
    }
    if(x == 5) {
        this->lives = 100;
        return std::string() + "\x1b[38:5:10m" + res + "\x1b[0m";
    }

    for(int i = 0; i < 5; i++){
        if(res[i] == 'O') continue;
        char b = w.getCharAtPos(i);
        int c = this->hiddenWord.getCount(b);
        if(c == 0 || c <= greenOrYellowCounter[b - 'a']) res[i] = 'X';
        else {
            res += 'X';
            greenOrYellowCounter[b - 'a']++;
        }
    }

    //ANSI color pass
    std::string res2 = "";
    for(int i = 0; i < 5; i++){
        switch(res[i]){
            case 'O': {
                res2 += "\x1b[38:5:10mO";
                break;
            }

            case 'X': {
                res2 += "\x1b[38:5:9mX";
                break;
            }

            default: {
                res2 += "\x1b[38:5:11m#";
                break;
            }
        }
    }

    res2 += "\x1b[0m";
    return res2;
}
