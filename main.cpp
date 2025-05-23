#include "./abstract/gameManager.h"

int main() {
    gameManager * g = new gameManager();
    g->loop();
    system("cls");

    // Tree t = Tree();
    // t.insert("aaaab");
    // t.insert("bbbba");
    // printf("Is aaaab in tree: %d\n", t.inTree("aaaab"));
    // printf("Get random string result: %s\n", t.getRandom().c_str());
    // t.__debug();

    // Dictionary * randomDict = new Dictionary("./dict/la.txt");

    // printf("%d\n", randomDict->isWordInDictionary(Word("tiara")));
    // printf("%d\n", randomDict->isWordInDictionary(Word("snake")));
    // printf("%d\n", randomDict->isWordInDictionary(Word("apple")));

    // printf("%.5s\n", randomDict->getRandomWord().letterArr);
    // printf("%.5s\n", randomDict->getRandomWord().letterArr);
    // printf("%.5s\n", randomDict->getRandomWord().letterArr);
    // printf("%.5s\n", randomDict->getRandomWord().letterArr);
}

/*
//printer.debug();
printer.println("Welcome to the Hangman game!");
printer.println("Please select your options!");

printer.println("1. Play a hangman game");
printer.println("2. View credits");
printer.println("3. Exit game");
printer.print("> ");

printer.render(false);
printer.getInput(1);

printer.clear();
printer.move_cursor(0, 0);
printer.render();

printer.print("Your input was: ");
printer.print(printer.inputBuffer, printer.lastInputLen);
printer.println("");
printer.render();
*/