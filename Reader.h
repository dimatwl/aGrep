#ifndef __READER_H__
#define __READER_H__

#include <string>
#include <vector>
#include <istream>
#include <iostream>
#include <stdlib.h>

using std::string;
using std::vector;
using std::istream;
using std::cin;
using std::string;
using std::cout;
using std::endl;


class Reader{
    string lines;
    string::iterator myBaseIter;
    string::iterator myLocalIter;

    string Reverse(const string& inpStr);
public:
    Reader(istream& inpStr);
    bool AtEnd(unsigned int inpPatternSize);
    
    void NextBaseChar();
    string GetNextChar();
    string PrintContext(unsigned int inpNum);
};

#endif /* __READER_H__ */