#include "main.h"


int main (int argc, char** argv) { 
    if (argc == 1) return 0;
    Reader reader(cin);
    string pattern;
    unsigned int dist;
    if (string(argv[1]) == string("-f")){
        ifstream input(argv[2] , ifstream::in);
        reader = Reader(input);
        pattern = string(argv[3]);
        dist = atoi(argv[4]);
    }
    else{
        pattern = string(argv[1]);
        dist = atoi(argv[2]);
    }


    void *lib_handle;
    lib_handle = dlopen("./levenshtein_automata.so", RTLD_NOW);
    LevenshteinAutomata* (*Create)();
    Create = (LevenshteinAutomata*(*)()) dlsym(lib_handle, "Create");
    LevenshteinAutomata* alg = Create();
    FuzzyLib* matcher = new FuzzyLib(alg);
    matcher->SetPattern(pattern,dist);

    //Реализация 2
    while (! reader.AtEnd(pattern.size())){
        bool matched = false;
        bool unacceptable = false;
        //i = 1;
        string subStr;
        while (!matched && !unacceptable){
            matcher->ProcessSymbols(reader.GetNextChar());
            matched = matcher->IsMatched();
            unacceptable = matcher->IsUnacceptable();
        }
        if (matched){
            cout<<reader.GetContext(10)<<endl;
        }
        reader.NextBaseChar();
    }

    return 0;
}
