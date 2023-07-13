#include <unistd.h>
#include <ws.h>
#include <string.h>
#include <stdio.h>

ws_cli_conn_t* pi;

void onopen(ws_cli_conn_t *client) {
    pi = client;
}

void play_note(char* note) {
    printf("Playing note %s\n", note);
}

void onmessage(ws_cli_conn_t *client, const unsigned char *msg, uint64_t size, int type) {
    char mutable_message[size];
    strcpy(mutable_message, (const char*)msg);

    char* token = strtok(mutable_message, ":");
    while (token != NULL) {
        play_note(token);
        token = strtok(NULL, ":");
    }
}

int main() {
    struct ws_events evs;
    evs.onopen = &onopen;
    evs.onmessage = &onmessage;

    ws_socket(&evs, 8080, 1, 0);

    while (1) {
        sleep(3);
    }

    // Listen for key presses and send to the browser

    return 0;
}