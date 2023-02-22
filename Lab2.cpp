/*
 * Course: CS216-00x
 * Project: Lab 2
 * Purpose: practice how to run unix command from C++ program
 *          system() is used to invoke an operating command from a C++ program
 *          demo cowsay command using three different cow files
 * Author: (your name)
 */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream cowFile;
	cowFile.open("cowFiles.txt");
    int NUM_OF_COWS = 0;
    string cowNames= "";

if (cowFile.is_open())
{

	while (getline(cowFile, cowNames))
	{
		string command_str = "cowsay -f /usr/share/cowsay/cows/";
        command_str = command_str + cowNames;
        command_str = command_str + " Hello, CS216 Students!";
        const char* command = command_str.c_str();
        system(command);
        NUM_OF_COWS = NUM_OF_COWS + 1;
	}	
}

else
{
	cout << "Could not open File!" << endl;	
}


cowFile.close();

    cout << "There are " << NUM_OF_COWS << " cow Files stored in my VM:)" << endl;

    return 0;

    
}



