// Including libraries for I/O operations and file handling
#include <iostream>
#include <fstream>
#include <string> // To utilize getline for reading the original
// content until a linebreak is encountered

using namespace std;

// Function to convert a character into its ASCII index
int ascii_cipher(char a)
{
    int r;
    r = int(a);
    return r;
}

// Function to convert an integer into its ASCII equivalent
char ascii_decipher(int a)
{
    char r;
    r = char(a);
    return r;
}

int main()
{
    /* 
        Part of Program to CIPHER the original story.txt and
        write it into storycoded.txt
    */

    fstream contentFile, cipherFile;
    string text;
    // Reading the story to cipher
    contentFile.open("story.txt", ios::in);
    cipherFile.open("storycoded.txt", ios::out);

    if (contentFile.is_open()) {

        // Reads all the lines of the story in a sequential manner
        // Serves as a good solution to linebreaks in the content
        while (getline(contentFile, text)) {

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

    /* 
        Part of program to DECIPHER the ciphered storycoded.txt
        and display the results on the console
    */

    int d_text;
    string dump;
    int* ptr;

    // Reading the story to cipher
    cipherFile.open("storycoded.txt", ios::in);

    if (cipherFile.is_open()) {
        // This piece of code serves purely a purpose
        // to allocate appropiate memory for the dynamic array
        getline(cipherFile, dump);
        int dma = dump.length();

        ptr = new int[dma];
        cipherFile.seekg(0); // Resets the pointer to the start of file

        // Loop to fill the dynamic array with integers from the file
        int counter = 0;
        while (cipherFile >> d_text) { // Loops through the whole file
            // looking for integers, skipping whitespace
            ptr[counter] = d_text;
            counter++;
        }

        // Decoding and displaying output on console
        for (int i = 0; i < counter; i++) {
            cout << ascii_decipher(ptr[i]);
        }

        cipherFile.close();
    }

    return 0;
}