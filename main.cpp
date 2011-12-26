#include "main.h"


int main (int argc, char** argv) { 
    if (argc == 1) return 0;
    //Reader reader(cin);
    string pattern;
    unsigned int dist;
    //if (string(argv[1]) == string("-f")){
        ifstream input(argv[2] , ifstream::in);
        Reader reader = Reader(input);
        pattern = string(argv[3]);
        dist = atoi(argv[4]);
    //}
    //else{
        //reader = Reader(cin);
        //pattern = string(argv[1]);
        //dist = atoi(argv[2]);
    //}

    void *lib_handle;
    lib_handle = dlopen("./levenshtein_automata.so", RTLD_NOW);
    LevenshteinAutomata* (*Create)();
    Create = (LevenshteinAutomata*(*)()) dlsym(lib_handle, "Create");
    LevenshteinAutomata* alg = Create();
    FuzzyLib* matcher = new FuzzyLib(alg);
    matcher->SetPattern(pattern,dist);
    int i = 0;
    //Реализация 2
    while (! reader.AtEnd(pattern.size())){
        bool matched = false;
        bool unacceptable = false;
        //i = 1;
        string subStr;
        while (!unacceptable){
            matcher->ProcessSymbols(reader.GetNextChar());
            matched = matcher->IsMatched();
            unacceptable = matcher->IsUnacceptable();
            if (matched){
                cout<<i<<") ";
                reader.PrintContext(30);
                ++i;
            }
        }
        reader.NextBaseChar();
        matcher->ResetCurrentTestString();
    }

    return 0;
}
