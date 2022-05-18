#include <iostream>
#include "unistd.h"
#include "pipeline.h"

using namespace std;

int main(int argc, char *argv[]) {

	int opt;
	WindowSize ws = ZERO;
	bool forwarding = false;
	string fileName = "instruction.txt";
	while ((opt = getopt(argc,argv,"f:i:")) != EOF) {
        switch (opt) {
            case 'f': ws = WindowSize(stoi(optarg)); break;
            case 'i': fileName.assign(optarg); break;
            case '?': fprintf(stderr, "usage is \n -i fileName : to run input file fileName \n -f windowSize : for setting forwarding windows size (0, 1, or 2) ");
            default: cout << endl; abort();
        }
    }

    if (ws) forwarding = true; // forward is unused variable.

    cout << "\nStarting..." << endl;

    switch (ws)
    {
        case ONE:
            cerr << "\33[1;32mForwarding is enabled with window size set to 1.\33[m" << endl;
            break;
        case TWO:
            cerr << "\33[1;32m" "Forwarding is enabled with window size set to 2.\33[m" << endl;
            break;
        default:
            cerr << "\33[1;31m" "Forwarding is disabled.\33[m" << endl;
            break;
    }
    cout << flush;

	cout << "Loading application..." << fileName << endl;
	Application application;
	application.loadApplication(fileName);
	cout << "Initializing pipeline..." << endl;
	Pipeline pipeline(&application);
	pipeline.forwarding = forwarding;
	pipeline.ws = ws;

	do {
		pipeline.cycle();
		pipeline.printPipeline();

	} while(!pipeline.done());

	cout << "\33[1;33m" "Completed in " << pipeline.cycleTime - 1 << " cycles.\33[m" << endl;
	return 0;
}
