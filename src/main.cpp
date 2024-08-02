#include <iostream>
#include "Window.h"
#include "Logging.h"

int main() {
    InitLogger();
    CWindow window{};
    window.run();
    return 0;
}
