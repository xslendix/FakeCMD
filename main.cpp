#include <signal.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

int dirDepth=2;

bool _running=true;

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

    for (int i=0; i<=100 && _running; ++i) {

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
    //_running=true;

    cout << endl << "Found 1 threat(s):" << endl;
    cout << " * Unsecured non-Microsoft affiliated connection. May be a scammer.\n\n";
}

void cmd()
{
    cout << "Microsoft Windows [Version 10.0.18363.592]\n" <<
            "(c) 2019 Microsoft Corporation. All rights reserved.\n\n";
}

void help()
{
    cout    << "For more information on a specific command, type HELP command-name\n"
            << "ASSOC          Displays or modifies file extension associations.\n"
            << "ATTRIB         Displays or changes file attributes.\n"
            << "BREAK          Sets or clears extended CTRL+C checking.\n"
            << "BCDEDIT        Sets properties in boot database to control boot loading.\n"
            << "CACLS          Displays or modifies access control lists (ACLs) of files.\n"
            << "CALL           Calls one batch program from another.\n"
            << "CD             Displays the name of or changes the current directory.\n"
            << "CHCP           Displays or sets the active code page number.\n"
            << "CHDIR          Displays the name of or changes the current directory.\n"
            << "CHKDSK         Checks a disk and displays a status report.\n"
            << "CHKNTFS        Displays or modifies the checking of disk at boot time.\n"
            << "CLS            Clears the screen.\n"
            << "CMD            Starts a new instance of the Windows command interpreter.\n"
            << "COLOR          Sets the default console foreground and background colors.\n"
            << "COMP           Compares the contents of two files or sets of files.\n"
            << "COMPACT        Displays or alters the compression of files on NTFS partitions.\n"
            << "CONVERT        Converts FAT volumes to NTFS.  You cannot convert the\n"
            << "               current drive.\n"
            << "COPY           Copies one or more files to another location.\n"
            << "DATE           Displays or sets the date.\n"
            << "DEL            Deletes one or more files.\n"
            << "DIR            Displays a list of files and subdirectories in a directory.\n"
            << "DISKPART       Displays or configures Disk Partition properties.\n"
            << "DOSKEY         Edits command lines, recalls Windows commands, and\n"
            << "               creates macros.\n"
            << "DRIVERQUERY    Displays current device driver status and properties.\n"
            << "ECHO           Displays messages, or turns command echoing on or off.\n"
            << "ENDLOCAL       Ends localization of environment changes in a batch file.\n"
            << "ERASE          Deletes one or more files.\n"
            << "EXIT           Quits the CMD.EXE program (command interpreter).\n"
            << "FC             Compares two files or sets of files, and displays the\n"
            << "               differences between them.\n"
            << "FIND           Searches for a text string in a file or files.\n"
            << "FINDSTR        Searches for strings in files.\n"
            << "FOR            Runs a specified command for each file in a set of files.\n"
            << "FORMAT         Formats a disk for use with Windows.\n"
            << "FSUTIL         Displays or configures the file system properties.\n"
            << "FTYPE          Displays or modifies file types used in file extension\n"
            << "               associations.\n"
            << "GOTO           Directs the Windows command interpreter to a labeled line in\n"
            << "               a batch program.\n"
            << "GPRESULT       Displays Group Policy information for machine or user.\n"
            << "GRAFTABL       Enables Windows to display an extended character set in\n"
            << "               graphics mode.\n"
            << "HELP           Provides Help information for Windows commands.\n"
            << "ICACLS         Display, modify, backup, or restore ACLs for files and\n"
            << "               directories.\n"
            << "IF             Performs conditional processing in batch programs.\n"
            << "LABEL          Creates, changes, or deletes the volume label of a disk.\n"
            << "MD             Creates a directory.\n"
            << "MKDIR          Creates a directory.\n"
            << "MKLINK         Creates Symbolic Links and Hard Links\n"
            << "MODE           Configures a system device.\n"
            << "MORE           Displays output one screen at a time.\n"
            << "MOVE           Moves one or more files from one directory to another\n"
            << "               directory.\n"
            << "OPENFILES      Displays files opened by remote users for a file share.\n"
            << "PATH           Displays or sets a search path for executable files.\n"
            << "PAUSE          Suspends processing of a batch file and displays a message.\n"
            << "POPD           Restores the previous value of the current directory saved by\n"
            << "               PUSHD.\n"
            << "PRINT          Prints a text file.\n"
            << "PROMPT         Changes the Windows command prompt.\n"
            << "PUSHD          Saves the current directory then changes it.\n"
            << "RD             Removes a directory.\n"
            << "RECOVER        Recovers readable information from a bad or defective disk.\n"
            << "REM            Records comments (remarks) in batch files or CONFIG.SYS.\n"
            << "REN            Renames a file or files.\n"
            << "RENAME         Renames a file or files.\n"
            << "REPLACE        Replaces files.\n"
            << "RMDIR          Removes a directory.\n"
            << "ROBOCOPY       Advanced utility to copy files and directory trees\n"
            << "SET            Displays, sets, or removes Windows environment variables.\n"
            << "SETLOCAL       Begins localization of environment changes in a batch file.\n"
            << "SC             Displays or configures services (background processes).\n"
            << "SCHTASKS       Schedules commands and programs to run on a computer.\n"
            << "SHIFT          Shifts the position of replaceable parameters in batch files.\n"
            << "SHUTDOWN       Allows proper local or remote shutdown of machine.\n"
            << "SORT           Sorts input.\n"
            << "START          Starts a separate window to run a specified program or command.\n"
            << "SUBST          Associates a path with a drive letter.\n"
            << "SYSTEMINFO     Displays machine specific properties and configuration.\n"
            << "TASKLIST       Displays all currently running tasks including services.\n"
            << "TASKKILL       Kill or stop a running process or application.\n"
            << "TIME           Displays or sets the system time.\n"
            << "TITLE          Sets the window title for a CMD.EXE session.\n"
            << "TREE           Graphically displays the directory structure of a drive or\n"
            << "               path.\n"
            << "TYPE           Displays the contents of a text file.\n"
            << "VER            Displays the Windows version.\n"
            << "VERIFY         Tells Windows whether to verify that your files are written\n"
            << "               correctly to a disk.\n"
            << "VOL            Displays a disk volume label and serial number.\n"
            << "XCOPY          Copies files and directory trees.\n"
            << "WMIC           Displays WMI information inside interactive command shell.\n"
            << "\n"
            << "For more information on tools see the command-line reference in the online help.\n"
            << "\n";
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
    else if (startsWith(lower, "exit")) exit(0);
    else if (startsWith(lower, "cmd")) cmd();
    else if (startsWith(lower, "help")) help();
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

    cmd();

    SetConsoleTitle("Administrator: Command Prompt");

    while (1)
    {
        string input = getInput();
        parseInput(input);
    }

    return 0;
}
