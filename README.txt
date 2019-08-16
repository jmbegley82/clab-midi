No-name collection of MIDI-related objects

All objects are derived from Atom (directly or indirectly).


MIDI Object Types:
====================
MidiOut:	An object that represents an RtMidi Virtual MIDI output.
		Commands:
			>MidiOut midi1
			creates object
			>midi1 := name Midi Output 1
			sets virtual MIDI channel's name
			>midi1 := open
			opens RtMidi output (also done during creation of MidiOut)
			>midi1 := close
			closes RtMidi output
			>midi1 := init
			sends default program/volume to connected device
			>midi1 := send 0x90 0x00
			>midi1 := send 0x90 0x00 0x7F
			sends MIDI message to channel

