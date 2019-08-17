/*
 *  MidiLoop.cpp
 *  8/16/19
 *  jmb
 *
 */

#include <string>
#include <iostream>
#include <cassert>
#include <RtMidi.h>
#include "Midi.h"
#include "MidiLoop.h"
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

		const char MidiLoop::type = 0xA1;

		MidiLoop::MidiLoop() {
			MidiLoop("");
		}

		MidiLoop::MidiLoop(string const& name) : Atom(name) {
		}

		MidiLoop::MidiLoop(const Atom* atm) {
			assert(0);
		}

		MidiLoop::~MidiLoop() {
		}

		Atom* MidiLoop::CtorWrapper(string name) {
			return new MidiLoop(name);
		}

		int MidiLoop::Command(string const& cmd) {
			//TODO:  commands to set channel name and to send messages

			if(cmd == "init") {
			} else return Atom::Command(cmd);
			return 0;
		}

		string MidiLoop::GetValueAsStdString() {
			return string("MidiLoop ") + identity + "@" + GetHexString(this);
		}

		void MidiLoop::Debug() {}

		void MidiLoop::SetValue(string const& val) {}

		int MidiLoop::OperatorEqu(Atom* atm) {
			*Log << "MidiLoop::" << __FUNCTION__ << ": stub" << std::endl;
			return -1;
		}

		int MidiLoop::_Procedure() {
			*Log << GetAbsolutePath() << std::endl;
			return 0;
		}

		int MidiLoop::_Declarate(string const& declarator, string const& subject) {
			return -1;
		}

		Atom* MidiLoop::_Interpret(Atom* atm) {
			return new MidiLoop(atm);
		}

		void* MidiLoop::GetRawData() {
			return NULL;
		}

		void MidiLoop::Tick(int time) {
		}

	}

}
