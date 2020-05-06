#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

int dirDepth=2;

void printDir()
{
    switch(dirDepth)
    {
        default: cout << "C:\\"; break;
        case 1: cout << "C:\\Windows"; break;
        case 2: cout << "C:\\Windows\\System32"; break;
    }
}

string str_tolower(string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return tolower(c); } );
    return s;
}

bool startsWith(const string& str, const string& start) {
    int l = start.length();
    if (&start == &str) return true;
    if (l > str.length()) return false;
    for (size_t i = 0; i < l; ++i) {
        if (start[i] != str[i]) return false;
    }
    return true;
}

void fakeTree()
{
    cout << "\nScanning system: ";

    for (int i=0; i<=100; ++i) {

        if (i<100) cout << i << '%';
        else if (i>=100) continue;

        Sleep(((rand() % 2) + 1)*1000+1000);

        if (i<10) cout << "\b\b";
        else if (i<100) cout << "\b\b\b";

        int r = (rand() % 2) + 1;
        i+=r;
        if (i>100) i -= 100-i;
    }
    cout << "100%";

    cout << endl << "Found 1 threat(s):" << endl;
    cout << " * Unsecured non-Microsoft affiliated connection. May be a scammer.\n\n";

}

void parseInput(string input)
{
    if (input == "") return;

    string lower = str_tolower(input);
    if (startsWith(lower, "tree") || startsWith(lower, "dir"))
    {
        fakeTree();
    }
    else if (startsWith(lower, "cd..") || startsWith(lower, "cd ..")) dirDepth --;
    else if (startsWith(lower, "cd"))
    {
        printDir(); cout << endl << endl;
    }
    else if (startsWith(lower, "netstat")) { system("netstat"); cout << endl; }
    else if (startsWith(lower, "ipconfig")) { system("ipconfig"); cout << endl; }
    else
    {
        string out = "'" + input + "' is not recognized as an internal or external command,\n"+
                     "operable program or batch file.\n";
        cout << out << endl;
    }
}


string getInput()
{
    string tmp;

    printDir(); cout << '>';

    std::getline(std::cin, tmp);

    return tmp;
}

int main()
{
    srand((unsigned) time(0));

    cout << "Microsoft Windows [Version 10.0.18363.592]\n" <<
            "(c) 2019 Microsoft Corporation. All rights reserved.\n\n";


    while (1)
    {
        string input = getInput();
        parseInput(input);
    }

    return 0;
}
