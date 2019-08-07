/*
 *  MidiOut.cpp
 *  7/20/19.
 *  jmb
 */

#include <string>
#include <iostream>
#include <cassert>
#include <RtMidi.h>
#include "MidiOut.h"
#include "Atom.h"
#include "Node.h"
#include "Notype.h"
#include "StringManip.h"
#include "Log.h"
#include "config.h"
#include "toaster.h"

using std::string;

namespace jmb {

	namespace common {
		
		const char MidiOut::type = 0xA0;
		
		MidiOut::MidiOut() {
			MidiOut("");
		}
		
		MidiOut::MidiOut(string const& name) : Atom(name) {
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

		MidiOut::MidiOut(const Atom* atm) {
			assert(0);
		}
		
		MidiOut::~MidiOut() {
		}

		Atom* MidiOut::CtorWrapper(string name) {
			return new MidiOut(name);
		}
/*
		Atom* Atom::Dereference(string const& name) {
			// Applied to command string subjects and targets to convert them
			//   into Atom*s
			
			if(name == "") return this;
			else if(name[0] == '/') {
				// remove the leading slash
				string noSlash = name;
				noSlash.erase(0, 1);
				// get top level Atom
				Atom* root = this;
				while(root->parent != NULL) {
					root = (Atom*)root->parent;
				}
				// pass noSlash to the root
				return root->Dereference(noSlash);
			} else //return NULL;
			{
				return new Notype(name);  // is it wise to put that into identity?
			}
		}
*/
		
		int MidiOut::Command(string const& cmd) {
			return Atom::Command(cmd);
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
	}

}
