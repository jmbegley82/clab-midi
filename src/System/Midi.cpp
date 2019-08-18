/*
 * Midi.cpp
 * 08/07/2019
 * jmb
 *
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cassert>
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
using jmb::common::GetString;
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

		string GetNoteFromSignal(unsigned char signal) {
			// return string representing the note in signal
			//   or empty string for invalid signal (eg >=128)
			string retval = "";
			// 0 = C(-2), 127 = G8
			if(signal < 128) {
				int octave = floor(signal / 12) - 2;  // -2 >= octave >= 8
				int note = signal % 12;  // 0 >= note >= 11
				switch(note) {
				case 0:
					retval += "C";
					break;
				case 1:
					retval += "C#";
					break;
				case 2:
					retval += "D";
					break;
				case 3:
					retval += "D#";
					break;
				case 4:
					retval += "E";
					break;
				case 5:
					retval += "F";
					break;
				case 6:
					retval += "F#";
					break;
				case 7:
					retval += "G";
					break;
				case 8:
					retval += "G#";
					break;
				case 9:
					retval += "A";
					break;
				case 10:
					retval += "A#";
					break;
				case 11:
					retval += "B";
					break;
				default:
					assert(0);
					break;
				}
				retval += GetString(octave);
			}
			return retval;
		}

	}

}
