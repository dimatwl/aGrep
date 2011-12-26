#include "Reader.h"

Reader::Reader(istream& inpStr){
    string cell;
    while(std::getline(inpStr,cell)){
        this->lines += cell + "\n";
    }
    this->myBaseIter = this->lines.begin();
}

bool Reader::AtEnd(unsigned int inpPatternSize){
	string::iterator subStrIter = this->myBaseIter;
	for (unsigned int i = 0; i < inpPatternSize - 1; i++){
		if (subStrIter == this->lines.end()){
			return true;
		}
		subStrIter++;
	}
    return subStrIter == this->lines.end();
}

void Reader::NextBaseChar(){
	this->myBaseIter++;
	this->myLocalIter = this->myBaseIter;
}

string Reader::GetNextChar(){
	string st;
	st.push_back(*(this->myLocalIter++));
	return st;
}

string Reader::GetContext(unsigned int inpNum){
	string::iterator fwdIter = this->myBaseIter;
	string::iterator bwdIter = this->myBaseIter;
	string subStr;
	subStr.resize(inpNum);
	bwdIter--;
	for (unsigned int i = inpNum - 1; i >= 0; --i){
		subStr[i] = *(bwdIter--);
	}
	for (unsigned int i = 0; i < inpNum; ++i){
		subStr += *(fwdIter++);
	}
	return subStr;
}