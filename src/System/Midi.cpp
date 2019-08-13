/*
 * Midi.cpp
 * 08/07/2019
 * jmb
 *
 */

#include <vector>
#include <RtMidi.h>
#include "Midi.h"

using std::vector;

namespace jmb {
	namespace Midi {
		void SendMidiMsg(RtMidiOut* midiOut, unsigned char sig1, unsigned char sig2) {
			vector<unsigned char> _msg;
			_msg.push_back(sig1);
			_msg.push_back(sig2);
			//if(midiOut)
				midiOut->sendMessage(&_msg);
		}
		
		void SendMidiMsg(RtMidiOut* midiOut, unsigned char sig1, unsigned char sig2, unsigned char sig3) {
			vector<unsigned char> _msg;
			_msg.push_back(sig1);
			_msg.push_back(sig2);
			_msg.push_back(sig3);
			//if(midiOut)
				midiOut->sendMessage(&_msg);
		}
	}
}
