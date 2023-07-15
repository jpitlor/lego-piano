#ifndef PIANO_SERVER_MIDI_H
#define PIANO_SERVER_MIDI_H

int initialize_midi();

void play_note(int note);

void stop_note(int note);

void play_pedal();

void stop_pedal();

#endif //PIANO_SERVER_MIDI_H
