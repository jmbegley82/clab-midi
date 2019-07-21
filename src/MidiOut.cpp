/*
 *  MidiOut.cpp
 *  7/20/19.
 *  jmb
 */

#include <string>
#include <iostream>
#include <cassert>
#include "MidiOut.h"
#include "Atom.h"
#include "Node.h"
#include "Notype.h"
#include "StringStuff.h"

namespace jmb {

	namespace common {
		
		const char MidiOut::type = 0xA0;
		
		MidiOut::MidiOut() {
			MidiOut("");
		}
		
		MidiOut::MidiOut(std::string const& name) : Atom(name) {
			//TODO: things
		}

		MidiOut::MidiOut(const Atom* atm) {
			assert(0);
		}
		
		MidiOut::~MidiOut() {
		}

		Atom* MidiOut::CtorWrapper(std::string name) {
			return new MidiOut(name);
		}
/*
		Atom* Atom::Dereference(std::string const& name) {
			// Applied to command string subjects and targets to convert them
			//   into Atom*s
			
			if(name == "") return this;
			else if(name[0] == '/') {
				// remove the leading slash
				std::string noSlash = name;
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
		
		int MidiOut::Command(std::string const& cmd) {
			return Atom::Command(cmd);
		}
		
		std::string MidiOut::GetValueAsStdString() {
			std::string retval = std::string("MidiOut ") + identity + "@" + std::hex(this);
			return retval;
		}
		
		void MidiOut::Debug() {}
		
		void MidiOut::SetValue(std::string const& val) {}
		
		int MidiOut::OperatorEqu(Atom* atm) {
			std::cout << "MidiOut::" << __FUNCTION__ << ": stub" << std::endl;
			return -1;
		}
		
		int MidiOut::_Procedure() {
			std::cout << GetAbsolutePath() << std::endl;
			return 0;
		}

		int MidiOut::_Declarate(std::string const& declarator, std::string const& subject) {
			return -1;
		}
		
		Atom* MidiOut::_Interpret(Atom* atm) {
			// default
			//std::cout << "MidiOut::_Interpret" << std::endl;
			return new MidiOut(atm);
		}
		
		void* MidiOut::GetRawData() {
			return NULL;
		}
		
		void MidiOut::Tick(int time) {
			// almost purely virtual
			//std::cout << GetAbsolutePath() << "::Tick(" << time << ")" << std::endl;
		}
	}

}
