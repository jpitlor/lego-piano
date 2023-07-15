#include <unistd.h>
#include "gpio.h"
#include "midi.h"
#include "websocket.h"

int main() {
    if (initialize_gpio() || initialize_midi() || initialize_websocket()) {
        return 1;
    }

    while (1) {
        sleep(3);
    }

    // Listen for key presses and send to the browser

    return 0;
}