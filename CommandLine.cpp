/*
 * CommandLine
 * Quentin
 */

#include "CommandLine.h"

CommandLine::CommandLine(istream &in)
{
    getline(in, commandEntered);
    vector<string> myStringVec;
    int otherInc = 0;
    noAndFlag = true;
    for (int i = 0; i < commandEntered.size(); i++)
    {
        if ((commandEntered[i] == ' ') && (commandEntered[i + 1] != ' '))
        {
            myStringVec.push_back(commandEntered.substr(otherInc, i - otherInc));
            otherInc = i + 1;
        }
    }
    if (commandEntered[commandEntered.size() - 1] != ' ')
    {
        myStringVec.push_back(commandEntered.substr(otherInc, commandEntered.size() - otherInc));
    }

    argc = myStringVec.size();
    argv = (char **)calloc(myStringVec.size() + 1, sizeof(char *) + 1);

    for (int i = 0; i < myStringVec.size(); i++)
    {
        if (myStringVec[i] == "&")
        {
            noAndFlag = false;
            argc--;
        }
        else
        {
            argv[i] = const_cast<char *>(myStringVec[i].c_str());
        }
    }
    argv[argc] = NULL;
}

CommandLine::CommandLine()
{
    noAndFlag = true;
    argc = 0;
    argv = NULL;
}

CommandLine::~CommandLine()
{
    if (argv[0] != NULL)
    {
        // free(argv);
    }
}

char *CommandLine::getCommand() const // return a pointer to the command portion of the command//line (i.e., argv[0]).
{
    return argv[0];
}

int CommandLine::getArgCount() const // return the number of command//line arguments on the command//line (i.e., argc).
{
    return argc;
}

char **CommandLine::getArgVector() const // return a pointer to a char* array, each entry of which points to one 'word' of the command//line (i.e., argv).
{
    return argv;
}

char *CommandLine::getArgVector(int i) const // return a pointer to the ith (zero//relative) command//line 'word' (i.e., argv[i]).
{
    return argv[i];
}

bool CommandLine::noAmpersand() const // returns true if and only if no ampersand was given on the command//line
{
    return noAndFlag;
}