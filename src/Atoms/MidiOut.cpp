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
			*Log << name << ":  ah, why not." << std::endl;
		}

		MidiOut::MidiOut(const Atom* atm) {
			assert(0);
		}
		
		MidiOut::~MidiOut() {
		}

		Atom* MidiOut::CtorWrapper(string name) {
			return new MidiOut(name);
		}

		int MidiOut::Command(string const& cmd) {
			//TODO:  commands to set channel name and to send messages
			if(cmd == "init") {
				_OpenMidiOut();
				_SetDefaults();
			} else if(cmd == "something") {
				//return 0;
			} else return Atom::Command(cmd);
			return 0;
		}	

		string MidiOut::GetValueAsStdString() {
			//string retval = string("MidiOut ") + identity + "@" + std::hex(this);
			//return retval;
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
			// default
			//*Log << "MidiOut::_Interpret" << std::endl;
			return new MidiOut(atm);
		}
		
		void* MidiOut::GetRawData() {
			return NULL;
		}
		
		void MidiOut::Tick(int time) {
			// almost purely virtual
			//*Log << GetAbsolutePath() << "::Tick(" << time << ")" << std::endl;
		}

		void MidiOut::_OpenMidiOut() {
			RtMidiOut* rtmo;
			try {
				rtmo = new RtMidiOut();
			} catch (RtMidiError &e) {
				e.printMessage();
				exit(EXIT_FAILURE);
			}

			rtmo->openVirtualPort(TOASTER(PACKAGE_NAME));
			_out = (void*)rtmo;
		}

		void MidiOut::_CloseMidiOut() {
		}

		void MidiOut::_SetDefaults() {
			*Log << identity << ":  _SetDefaults " << GetHexString(_out) << std::endl;
			SendMidiMsg((RtMidiOut*)_out, 0xC0, 0x00);		// set ch.1 program to 0
			SendMidiMsg((RtMidiOut*)_out, 0xB0, 0x07, 0x7F);	// set ch.1 volume to 127
		}
	}

}
