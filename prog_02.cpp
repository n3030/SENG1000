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

    // Declaring and initializing the variable of type MyData
    MyData myArgs;

    // Checking if argv[1] is a positive integer
    myArgs.howMany = atoi(argv[1]);
    if (myArgs.howMany <= 0) {
        cout << "Error: First argument should be a positive integer." << endl;
        return 1;
    }

    // Copying the argv[2], argv[3], and argv[4] into the struct fields
    strncpy(myArgs.theText, argv[2], 20);
    myArgs.theText[20] = '\0'; // Null-terminate the string

    strncpy(myArgs.directoryPath, argv[3], 20);
    myArgs.directoryPath[20] = '\0'; // Null-terminate the string

    strncpy(myArgs.filename, argv[4], 20);
    myArgs.filename[20] = '\0'; // Null-terminate the string

    // Creating a C-style string for the full file path
    const int MAX_PATH_LENGTH = strlen(myArgs.directoryPath) + strlen(myArgs.filename) + 2; // +2 for slash and null terminator
    char fullFilePath[MAX_PATH_LENGTH];

    // Constructing the full file path
    cout << "Directory path: " << myArgs.directoryPath << endl;
    cout << "Filename: " << myArgs.filename << endl;

    strcpy(fullFilePath, myArgs.directoryPath);
    strcat(fullFilePath, "/");
    strcat(fullFilePath, myArgs.filename);

    // Opening the file for writing
    ofstream outputFile(fullFilePath);

    // The lines to the file
    for (int i = 0; i < myArgs.howMany; ++i) {
        outputFile << myArgs.theText << "\n";
    }

    // Close the file
    outputFile.close();

    cout << "File " << fullFilePath << " created successfully." << endl;

    return 0;
}
