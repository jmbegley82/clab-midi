/*
 *  main.cpp
 *  08/??/2019
 *  jmb
 *
 */


#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include "Clab.h"
#include "Clab-midi.h"
#include "Types.h"
#include "Atom.h"
#include "Node.h"
#include "Integer.h"
#include "Float.h"
#include "String.h"
#include "Notype.h"
#include "MidiOut.h"
#include "Midi.h"
#include "Time.h"
#include "Clock.h"
#include "Log.h"
#include "StringManip.h"

using jmb::common::Atom;
using jmb::common::Node;
using jmb::common::MidiOut;
using jmb::common::Clock;
using jmb::common::Types::AddMapping;
using jmb::common::ClabInit;
using jmb::common::ClabMidiInit;
using jmb::common::Log;
using jmb::common::GetHexString;
using jmb::Midi::GetNoteFromSignal;
using std::endl;
using std::cin;

void test0() {
	*Log << ":::Version Variable Test - Clab:::" << endl;
	*Log << "Clab reports version string:  " << jmb::common::ClabVersionString() << endl;
	*Log << "Clab reports major version:   " << jmb::common::ClabVersionMajor() << endl;
	*Log << "Clab reports minor version:   " << jmb::common::ClabVersionMinor() << endl;
	*Log << "Linked using Clab major version:   " << CLAB_VERSION_MAJOR << endl;
	*Log << "Linked using Clab minor version:   " << CLAB_VERSION_MINOR << endl;
	*Log << endl;
}

void test1() {
	*Log << ":::Version Variable Test - Clab-midi:::" << endl;
	*Log << "Clab-midi reports version string:  " << jmb::common::ClabMidiVersionString() << endl;
	*Log << "Clab-midi reports major version:   " << jmb::common::ClabMidiVersionMajor() << endl;
	*Log << "Clab-midi reports minor version:   " << jmb::common::ClabMidiVersionMinor() << endl;
	*Log << "Linked using Clab-midi major version:   " << CLAB_MIDI_VERSION_MAJOR << endl;
	*Log << "Linked using Clab-midi minor version:   " << CLAB_MIDI_VERSION_MINOR << endl;
	*Log << endl;
}

Node* test2() {
	*Log << ":::MidiOut object test:::" << endl;
	//Node root("root");
	Node* retval = new Node("root");
	//root.Command("MidiOut out1");
	retval->Command("MidiOut out1");
	Atom* out1 = retval->Dereference("out1");
	assert(out1 != NULL);
	assert(out1->identity == "out1");
	*Log << "/out1 address appears to be:  " << GetHexString(out1) << endl;
	*Log << endl;
	return retval;
}

void test3(Node* root) {
	*Log << ":::MidiOut functionality test:::" << endl;
	*Log << "root identity is " << root->identity << endl;
	root->Command("/out1 := init");
	//root->Command("/out1 := test");
	//root->Command("/out1 := send 0xC0 0x00");
	*Log << endl;
	
}

void test4() {
	*Log << ":::GetNoteFromSignal test:::" << endl;
	*Log << "Signal 0   is C-2; GNFS thinks it is " << GetNoteFromSignal(0) << endl;
	*Log << "Signal 127 is " << GetNoteFromSignal(127) << endl;
	*Log << "Signal 255 is " << GetNoteFromSignal(255) << "empty because it is not a valid signal" << endl;
	*Log << endl;
}

void test5(Node* root) {
	*Log << ":::MidiLoop object test:::" << endl;
	*Log << "Creating MidiLoop object named loop1 in root..." << endl;
	root->Command("MidiLoop loop1");
	// more shenanigans
}

int main(int argc, char** argv) {
	ClabInit();
	ClabMidiInit();
	*Log << "The test begins...  now." << endl;
	*Log << endl;

	test0();
	test1();
	//MidiOut* root = (MidiOut*)test2();
	Node* root = test2();

	*Log << "Press ENTER to continue" << endl;
	cin.ignore();

	test3(root);

	*Log << "Press ENTER to continue" << endl;
	cin.ignore();

	test4();

	test5(root);

	return 0;
}
