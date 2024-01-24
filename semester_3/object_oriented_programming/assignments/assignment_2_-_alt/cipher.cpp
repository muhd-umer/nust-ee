// Including libraries for I/O operations and file handling
#include <iostream>
#include <fstream>
#include <string> // To utilize getline for reading the original
// content until a linebreak is encountered

using namespace std;

// Simple function to convert a character into its ASCII index
int ascii_cipher(char a)
{
    int r;
    r = int(a);
    return r;
}

int main()
{
    fstream contentFile, cipherFile;
    string text;
    // Reading the story to cipher
    contentFile.open("story.txt", ios::in);
    cipherFile.open("storycoded.txt", ios::out);

    if (contentFile.is_open()) {

        // Reads all the lines of the story in a sequential manner
        // Serves as a good solution to linebreaks in the content
        while (getline(contentFile, text)) {

            /* For Coder's Own Convenience
            Checking if the lines are being read correctly
            for (int i = 0; i < text.length(); i++)
            {
                cout << text[i];
            }
            cout << endl; */

            // Saving the coded data into storycoded.txt
            if (cipherFile.is_open()) {
                // Ciphered Text
                for (int i = 0; i < text.length(); i++) {
                    cipherFile << ascii_cipher(text[i]) << " ";
                }
                // Line break corresponding to those
                // in the original text if any present
                cipherFile << endl;
            }
        }
        contentFile.close();
        cipherFile.close();
    }
    return 0;
}