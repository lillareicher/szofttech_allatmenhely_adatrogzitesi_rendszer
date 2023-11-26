#include "adminisztrator.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool Adminisztrator::felhasznaloTorles(const string& filename, int id) {
	ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return false;
    }

    // Read content from the file and store it in a stringstream
    ostringstream modifiedContent;
    string line;
    int currentId;

    while (getline(inputFile, line)) {
        istringstream lineStream(line);

        // Assuming the ID is the first field in each line
        if (lineStream >> currentId) {
            if (currentId != id) {
                // If the ID doesn't match the target, append the line to the modified content
                modifiedContent << line << '\n';
            }
        }
        else {
            cerr << "Error reading ID from file!" << endl;
            return false;
        }
    }

    inputFile.close();  // Close the file

    // Now, open the same file in output mode (truncating the content)
    ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        cerr << "Error opening file for writing!" << endl;
        return false;
    }

    // Write the modified content back to the file
    outputFile << modifiedContent.str();

    outputFile.close();  // Close the file

    cout << "ID " << id << " deleted successfully." << endl;

    return true;
}

void Adminisztrator::rangAdas(int ID, int randID) {
}

void Adminisztrator::kervenyFelulvizsgalat(string& kerveny) {
}