/*
 *  MidiLoop.h
 *  8/16/19
 *  jmb
 *
 */


#ifndef MIDILOOP_H
#define MIDILOOP_H

#include <string>
#include "Atom.h"

namespace jmb {

	namespace common {

		class Node;

		class MidiLoop : public Atom {
		public:
			MidiLoop();
			MidiLoop(std::string const& name);
			MidiLoop(const Atom* atm);
			~MidiLoop();
			static Atom* CtorWrapper(std::string name);
			static const char type;
			//bool isEphemeral;

			//Atom* GetRoot();
			//char GetType();
			//void LeaveParent();
			//std::string identity;
			//Node* parent;
			//bool containsValidData;
			//bool wasUpdated;
			//bool eraseMe;

			//virtual Atom* Dereference(std::string const& name);
			virtual int Command(std::string const& cmd);
			//virtual int Command(std::string const& op, Atom* target);
			virtual void SetValue(std::string const& val);
			virtual std::string GetValueAsStdString();
			//virtual std::string GetAbsolutePath();
			virtual void Debug();
			virtual int OperatorEqu(Atom* atm); //  =
			//virtual int OperatorAdd(Atom* atm); // +=
			//virtual int OperatorSub(Atom* atm); // -=
			//virtual int OperatorMul(Atom* atm); // *=
			//virtual int OperatorDiv(Atom* atm); // /=
			//virtual int OperatorPow(Atom* atm); // ^=
			virtual void* GetRawData();
			virtual void Tick(int time);
		protected:
			virtual int _Procedure();
			virtual int _Declarate(std::string const& declarator, std::string const& subject);
			virtual Atom* _Interpret(Atom* atm);
			char _type;
		private:
		};

	}

}

#endif //MIDILOOP_H
