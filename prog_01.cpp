#include <iostream>
#include <cstring>

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

   // Declareing the variable of type MyData
   MyData myArgs;

   // Checking if argv[1] is a positive integer
   myArgs.howMany = atoi(argv[1]);
   if (myArgs.howMany <= 0) {
       cout << "Error: First argument should be a positive integer." << endl;
       return 1;
   }

   // Copy the argv[2], argv[3], and argv[4] into the struct fields
   strncpy(myArgs.theText, argv[2], 20);
   myArgs.theText[20] = '\0'; // Null-terminate the string

   strncpy(myArgs.directoryPath, argv[3], 20);
   myArgs.directoryPath[20] = '\0'; // Null-terminate the string

   strncpy(myArgs.filename, argv[4], 20);
   myArgs.filename[20] = '\0'; // Null-terminate the string

   // If all checks pass, proceed with the program
   cout << "Number: " << myArgs.howMany << endl;
   cout << "String 1: " << myArgs.theText << endl;
   cout << "String 2: " << myArgs.directoryPath << endl;
   cout << "String 3: " << myArgs.filename << endl;

   return 0; // exiting main by returning 0
}
