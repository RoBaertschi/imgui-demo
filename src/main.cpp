#include "Logging.h"
#include "Window.h"

int main() {
    CWindow window{};
    try {
    window.run();
    } catch (std::runtime_error& error) {
        ERROR("Error while running the program: {}", error.what());
        return 1;
    }
    return 0;
}
