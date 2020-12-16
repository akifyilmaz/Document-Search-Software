/*
 * wordSearch.cpp
 *
 *  Created on: Dec 16, 2020
 *      Author: akifdev18
 */

#include "wordSearch.h"
#include <string>
#include <fstream>
#include <iostream>

wordSearch::wordSearch() {
    // TODO Auto-generated constructor stub

}

wordSearch::~wordSearch() {
    // TODO Auto-generated destructor stub
}

std::string wordSearch::findWord(std::string word)
{
    // this function reads the databas.dat file which is constructed previously under the
    // home directory and searches for the given word. If the word is found function returns related
    // paths and number of occurrences of that word. If word couldn't be find function returns empty
    // string.

    word = word + ":";
    char* home = getenv("HOME");
    std::string homedir(home);
    std::string file_path;
    file_path = homedir + "/database.dat";

    std::ifstream file;
    file.open(file_path.c_str());

    std::string str;
    while (std::getline(file,str)) {
        std::string key = str.substr(0, str.find(" "));
        if (word.compare(key)==0) {
            return str;
        }
    }
    return "";
}
