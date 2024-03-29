#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

// Struct definition
struct MyData {
    int howMany;
    char theText[21];
    char directoryPath[21];
    char filename[21];
};

int main(int argc, char* argv[]) {
    // Checking if the program has exactly four arguments
    if (argc != 5) {
        cout << "Error: Incorrect number of arguments." << endl;
        cout << "Usage: program <positive_integer> <string1> <string2> <string3>" << endl;
        return 1;
    }
	
	// ---?

    return 0;
}