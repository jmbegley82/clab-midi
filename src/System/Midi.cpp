/*
 * Midi.cpp
 * 08/07/2019
 * jmb
 *
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <RtMidi.h>
#include "StringManip.h"
#include "Midi.h"
#include "Log.h"

using std::string;
using std::vector;
using std::endl;
using jmb::common::GetHexString;
using jmb::common::RemovePadding;
using jmb::common::GetFirstWordEtc;
using jmb::common::Log;

namespace jmb {

	namespace Midi {

		void SendMidiMsg(RtMidiOut* midiOut, string signals) {
			vector<unsigned char> _msg;
			string input = signals;
			string remainder = "dummy";
			while(remainder != "") {
				string aword = GetFirstWordEtc(input, remainder);
				unsigned long ul = strtoul(aword.c_str(), NULL, 0);
				unsigned char sig = static_cast<unsigned char>(ul);
				_msg.push_back(sig);
				*Log << "SendMidiMsg:  text=" << aword << ", data=" << (unsigned int)sig << std::endl;
				input = remainder;
			}
			midiOut->sendMessage(&_msg);
		}

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
