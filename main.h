#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdlib.h>
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include "general_algorithm.h"
#include "matching_algorithm.h"
#include "LCS.h"
#include "levenshtein.h"
#include "levenshtein_automata.h"
#include "libfuzzy.h"
#include <dlfcn.h>
#include "Reader.h"


using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ifstream;

using libfuzzy::FuzzyLib;
using libfuzzy::LevenshteinAutomata;

#endif /* __MAIN_H__ */