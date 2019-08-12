/*
 * Midi.h
 * 08/07/2019
 * jmb
 *
 */

#ifndef MIDI_H
#define MIDI_H

#include <RtMidi.h>

namespace jmb {
	namespace Midi {
		void SendMidiMsg(RtMidiOut* midiOut, unsigned char sig1, unsigned char sig2);
		void SendMidiMsg(RtMidiOut* midiOut, unsigned char sig1, unsigned char sig2, unsigned char sig3);
	}
}

#endif // MIDI_H
