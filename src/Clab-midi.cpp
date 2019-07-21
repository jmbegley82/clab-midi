/*
 * Clab-midi.cpp
 * 07/19/2019
 * jmb
 */

#include <string>
#include "Clab-midi.h"
#include "MidiOut.h"
#include "Types.h"
#include "config.h"
#include "toaster.h"

using std::string;
using jmb::common::Manager;
using jmb::common::Video;
using jmb::common::Types::AddMapping;

namespace jmb {
	namespace common {
		int ClabMidiInit() {
			int retval = 0;  // TODO:  something meaningful with this?
			AddMapping("MidiOut", MidiOut::CtorWrapper);
			return retval;
		}

		string ClabMidiVersionString() {
			return string(TOASTER(PACKAGE_NAME)) + " " + string(TOASTER(PACKAGE_VERSION)) + " built on " + __DATE__ + " at " + __TIME__;
		}

		int ClabMidiVersionMajor() {
			return CLAB_MIDI_VERSION_MAJOR;
		}

		int ClabMidiVersionMinor() {
			return CLAB_MIDI_VERSION_MINOR;
		}
	}
}
