/*
 * Midi.h
 * 08/07/2019
 * jmb
 *
 */

#ifndef MIDI_H
#define MIDI_H

#include <string>
#include <RtMidi.h>

namespace jmb {
	namespace Midi {
		void SendMidiMsg(RtMidiOut* midiOut, std::string signals);
		void SendMidiMsg(RtMidiOut* midiOut, unsigned char sig1, unsigned char sig2);
		void SendMidiMsg(RtMidiOut* midiOut, unsigned char sig1, unsigned char sig2, unsigned char sig3);
		std::string GetNoteFromSignal(unsigned char signal);
	}
}

#endif // MIDI_H
