#include "../renderer/scene/scene.h"
#include "dictionary.h"
#include "utils.h"


class gameManager {

    enum sceneID {
        main_menu,
        rules,
        credit,
        play,
        exit,
        finish
    };

    int lives = 6;
    Scene currScene = getScene(main_menu);
    enum sceneID currSceneID = main_menu;
    Scene getScene(enum sceneID id);

    Dictionary * randomDict = nullptr;
    Dictionary * guessableDict = nullptr;

    Word hiddenWord;

    public: 
        gameManager();
        void step();
        void loop();
        std::string compare(Word);

};