/*
 * main.cpp
 *
 *  Created on: Dec 13, 2020
 *      Author: akifdev18
 */
#include "fileSystemAnalyzer.h"
#include "libraryIndexer.h"
#include "wordSearch.h"
#include <unordered_map>
#include <map>
#include <iostream>

int main(int argc, char* argv[]) {

    std::string command;
    std::string argument;

    if (argc != 3) {
        std::cerr<<"invalid argument."<<std::endl
                << "Usage: " << argv[0] << "<command [-index || -search]>"
                <<" <argument [path_to_library || some_word]>\n";
        return 1;
    }

    try {
        command = std::string(argv[1]);
        argument = std::string(argv[2]);
    } catch (std::exception const& e) {
        std::cerr << "Invalid address." << std::endl;
        return 1;
    }

    if (command.compare("-index")==0) {
        std::vector<std::string> files;

        if (fileSystemAnalyzer::getInstance().findFiles(argument, files)==true) {

            libraryIndexer::getInstance().setFileList(files);

            libraryIndexer::getInstance().createInvertedIndex();
        } else {
            std::cerr<<"Couldn't find any *.txt file, check your library_path."<<std::endl;
        }
    }else if ( command.compare("-search")==0) {
       std::string result = wordSearch::getInstance().findWord(argument);
       if (result.compare("")==0)
           std::cout<<argument<<" couldn't be found in the given library"<<std::endl;
       std::cout<<result<<std::endl;
    } else {
        std::cerr<<"invalid command."<<std::endl;
    }

    return 0;
}



