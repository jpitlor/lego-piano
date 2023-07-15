#include <ws.h>
#include <string.h>
#include <stdlib.h>
#include "websocket.h"
#include "midi.h"
#include "gpio.h"

ws_cli_conn_t *pi;

void onopen(ws_cli_conn_t *client) {
    pi = client;
}

void onmessage(ws_cli_conn_t *, const unsigned char *msg, uint64_t size, int) {
    char mutable_message[size];
    strcpy(mutable_message, (const char *) msg);

    char *parts[2];
    int i = 0;
    char *token = strtok(mutable_message, ":");
    while (token != NULL && i < 2) {
        parts[i++] = token;
        token = strtok(NULL, ":");
    }

    if (strcmp(parts[0], "note_on") == 0) {
        int note = (int) strtol(parts[1], NULL, 10);
        play_note(note);
    } else if (strcmp(parts[0], "note_off") == 0) {
        int note = (int) strtol(parts[1], NULL, 10);
        stop_note(note);
    } else if (strcmp(parts[0], "pedal_on") == 0) {
        play_pedal();
    } else if (strcmp(parts[0], "pedal_off") == 0) {
        stop_pedal();
    } else if (strcmp(parts[0], "prompt_for_note") == 0) {
        int note = (int) strtol(parts[1], NULL, 10);
        prompt_for_note(note);
    }
}

void send_to_pi(const char *message) {
    ws_sendframe_txt(pi, message);
}

int initialize_websocket() {
    struct ws_events evs;
    evs.onopen = &onopen;
    evs.onmessage = &onmessage;

    ws_socket(&evs, 8080, 1, 0);
    return 0;
}