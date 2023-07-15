#include <pigpio.h>
#include <stdio.h>
#include "gpio.h"
#include "websocket.h"

int initialize_gpio() {
    if (gpioInitialise() < 0)
    {
        perror("Can't initialize_gpio PI GPIO");
        return 1;
    }

    return 0;
}

void prompt_for_note(int note) {
    // This is where we might turn on a light above the key
}

void handle_played_note(int note) {
    printf("Note %d was played", note);

    char message[16];
    sprintf(message, "played_note:%d", note);
    send_to_pi(message);
}