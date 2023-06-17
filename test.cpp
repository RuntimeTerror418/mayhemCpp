#include <window.hpp>

class Game: public mhy::Window {


public:
    Game(): mhy::Window(640, 640, "Whirly Woosh"){}

};

int main() {
    Game g;
    g.start();
    return 0;
}