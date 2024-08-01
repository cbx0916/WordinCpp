// main.cpp

#include <cstdlib>
#include <iostream>
#include <string>

int main() {
    // Text to be saved in the .docx file
    std::string text = "This is a sample text saved in a .docx file using Python and python-docx.";

    // Construct the command to execute the Python script with the text argument
    std::string command = "python savedocx.py \"" + text + "\"";

    // Execute the Python script
    int result = system(command.c_str());

    // Check if the execution was successful
    if (result != 0) {
        std::cerr << "Failed to execute Python script.\n";
        getchar();
        return 1;
    }
    getchar();
    return 0;
}
