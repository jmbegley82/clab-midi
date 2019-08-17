/*
 *  MidiOut.cpp
 *  7/20/19.
 *  jmb
 */

#include <string>
#include <iostream>
#include <cassert>
#include <RtMidi.h>
#include "Midi.h"
#include "MidiOut.h"
#include "Atom.h"
#include "Node.h"
#include "Notype.h"
#include "StringManip.h"
#include "Log.h"
#include "config.h"
#include "toaster.h"

using std::string;
using jmb::Midi::SendMidiMsg;

namespace jmb {

	namespace common {

		const char MidiOut::type = 0xA0;

		MidiOut::MidiOut() {
			MidiOut("");
		}

		MidiOut::MidiOut(string const& name) : Atom(name) {
			_OpenMidiOut();
		}

		MidiOut::MidiOut(const Atom* atm) {
			assert(0);
		}

		MidiOut::~MidiOut() {
			_CloseMidiOut();
		}

		Atom* MidiOut::CtorWrapper(string name) {
			return new MidiOut(name);
		}

		int MidiOut::Command(string const& cmd) {
			//TODO:  commands to set channel name and to send messages
			string remainder;
			string fword = GetFirstWordEtc(cmd, remainder);

			if(fword == "init") {
				_SetDefaults();
			} else if(fword == "open") {
				_OpenMidiOut();
			} else if(fword == "close") {
				_CloseMidiOut();
			} else if(fword == "send") {
				SendMidiMsg(remainder);
			} else if(fword == "test") {
				SendMidiMsg("0xC0 0x00");
			} else return Atom::Command(cmd);
			return 0;
		}

		string MidiOut::GetValueAsStdString() {
			return string("MidiOut ") + identity + "@" + GetHexString(this);
		}

		void MidiOut::Debug() {}

		void MidiOut::SetValue(string const& val) {}

		int MidiOut::OperatorEqu(Atom* atm) {
			*Log << "MidiOut::" << __FUNCTION__ << ": stub" << std::endl;
			return -1;
		}

		int MidiOut::_Procedure() {
			*Log << GetAbsolutePath() << std::endl;
			return 0;
		}

		int MidiOut::_Declarate(string const& declarator, string const& subject) {
			return -1;
		}

		Atom* MidiOut::_Interpret(Atom* atm) {
			return new MidiOut(atm);
		}

		void* MidiOut::GetRawData() {
			return NULL;
		}

		void MidiOut::Tick(int time) {
		}

		void MidiOut::SendMidiMsg(string signals) {
			if(_out) jmb::Midi::SendMidiMsg((RtMidiOut*)_out, signals);
		}

		void MidiOut::SendMidiMsg(unsigned char sig1, unsigned char sig2) {
			if(_out) jmb::Midi::SendMidiMsg((RtMidiOut*)_out, sig1, sig2);
		}

		void MidiOut::SendMidiMsg(unsigned char sig1, unsigned char sig2, unsigned char sig3) {
			if(_out) jmb::Midi::SendMidiMsg((RtMidiOut*)_out, sig1, sig2, sig3);
		}

		void MidiOut::_OpenMidiOut() {
			if(!_out) {
				RtMidiOut* rtmo;
				try {
					rtmo = new RtMidiOut();
				} catch (RtMidiError &e) {
					e.printMessage();
					exit(EXIT_FAILURE);
				}
				
				rtmo->openVirtualPort(TOASTER(PACKAGE_NAME));
				_out = (void*)rtmo;
			} else {
				*Log << identity << ":  _OpenMidiOut:  port already open" << std::endl;
			}
		}

		void MidiOut::_CloseMidiOut() {
			if(_out) {
				delete (RtMidiOut*)_out;
				_out = NULL;
			} else {
				*Log << identity << ":  _CloseMidiOut:  port not open" << std::endl;
			}
		}

		void MidiOut::_SetDefaults() {
			SendMidiMsg(0xC0, 0x00);		// set ch.1 program to 0
			SendMidiMsg(0xB0, 0x07, 0x7F);		// set ch.1 volume to 127
		}

	}

}
