#ifndef PIANO_SERVER_WEBSOCKET_H
#define PIANO_SERVER_WEBSOCKET_H

int initialize_websocket();

void send_to_pi(const char* string);

#endif //PIANO_SERVER_WEBSOCKET_H
