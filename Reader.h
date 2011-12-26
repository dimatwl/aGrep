#ifndef __READER_H__
#define __READER_H__

#include <string>
#include <vector>
#include <istream>
#include <iostream>

using std::string;
using std::vector;
using std::istream;
using std::cin;
using std::string;


class Reader{
    string lines;
    string::iterator myBaseIter;
    string::iterator myLocalIter;

public:
    Reader(istream& inpStr);
    bool AtEnd(unsigned int inpPatternSize);
    
    void NextBaseChar();
    string GetNextChar();
    string GetContext(unsigned int inpNum);
};

#endif /* __READER_H__ */