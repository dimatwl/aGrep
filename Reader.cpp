#include "Reader.h"

Reader::Reader(istream& inpStr){
    string cell;
    while(std::getline(inpStr,cell)){
        this->lines += cell + "\n";
    }
    this->myBaseIter = this->lines.begin();
    this->myLocalIter = this->myBaseIter;
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
	if (this->myLocalIter != this->lines.end()){
		st.push_back(*(this->myLocalIter++));
	}else{
		st.push_back(*this->myLocalIter);
	}
	return st;
}

string Reader::Reverse(const string& inpStr)
{
	int len = inpStr.size();
	string reverse = inpStr;
	for (int n = 0; n < len; ++n)
	{
		reverse[len - n - 1] = inpStr[n];
	}
	return reverse;
}

string Reader::PrintContext(unsigned int inpNum){
	string::iterator fwdIter = this->myLocalIter;
	string::iterator bwdIter = this->myBaseIter;
	string subStr;
	bool onBegin = true;
	if (bwdIter != this->lines.begin()){
		bwdIter--;
		onBegin = false;
	}
	for (int i = inpNum - 1; i >= 0; --i){
		if (bwdIter != this->lines.begin()){
			subStr.push_back(*(bwdIter--));
		} else if (!onBegin){
			subStr.push_back(*bwdIter);
			break;
		} else{
			break;
		}
	}
	subStr = this->Reverse(subStr);
	cout<<subStr;
	subStr.clear();

	string matched;
	matched += "\e[0;31m";
	for (string::iterator it = this->myBaseIter; it != myLocalIter; it++){
		matched += *it;
	}
	cout<<matched;
	subStr += "\e[0m";
	for (unsigned int i = 0; i < inpNum; ++i){
		if (fwdIter != this->lines.end()){
			subStr.push_back(*(fwdIter++));
		} else{
			//subStr.push_back(*fwdIter);
			break;
		}
	}
	cout<<subStr<<endl;
	return subStr;
}