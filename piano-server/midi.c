#include <stdio.h>
#include <sys/file.h>
#include <unistd.h>
#include "websocket.h"
#include "midi.h"

int midi;

void stop_note(int note) {
    int midi_note = 48 + note;
    printf("Stopping note %d\n", midi_note);
    int message[] = {0x80, midi_note, 127};
    write(midi, message, sizeof(message));
}

void play_note(int note) {
    int midi_note = 48 + note;
    printf("Playing note %d\n", midi_note);
    int message[] = {0x90, midi_note, 127};
    write(midi, message, sizeof(message));
}

void play_pedal() {
    printf("Turning pedal on");
    int message[] = {0xB0, 64, 127};
    write(midi, message, sizeof(message));
}

void stop_pedal() {
    printf("Turning pedal off");
    int message[] = {0xB0, 64, 0};
    write(midi, message, sizeof(message));
}

int initialize_midi() {
    midi = open("/dev/midi0", O_WRONLY);
    if (midi < 0) {
        perror("Can't open midi device");
        return 1;
    }
}