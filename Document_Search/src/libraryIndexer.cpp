/*
 * libraryIndexer.cpp
 *
 *  Created on: Dec 14, 2020
 *      Author: akifdev18
 */

#include "libraryIndexer.h"
#include "fileSystemAnalyzer.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <stdlib.h>

libraryIndexer::libraryIndexer() {
    // TODO Auto-generated constructor stub

}

libraryIndexer::~libraryIndexer() {
    // TODO Auto-generated destructor stub
}

void libraryIndexer::createInvertedIndex()
{
    // this function reads .txt files in the given path and writes new words to the unordered_map
    // as key. The value of the unordered_map is a map which keys are related file path and values are
    // related number of words.

    std::unordered_map<std::string, std::map<std::string, uint32_t>> dictionary;
    for (auto& p: fileList) {
        std::fstream file;
        std::string s;
        uint32_t count = 1;
        file.open(p.c_str());
        while (file>>s) {
            if ( (dictionary.find(s)==dictionary.end()) || (dictionary.find(s)->second.find(p)==dictionary.find(s)->second.end()) ) {
                if (dictionary.find(s)==dictionary.end()) {
                    std::map<std::string, uint32_t> temp_map;
                    temp_map.emplace(p, count);
                    dictionary.emplace(s, temp_map);
                } else {
                    dictionary.find(s)->second.emplace(p, count);
                }
            } else {
                auto iter_umap = dictionary.find(s);
                if (iter_umap!=dictionary.end()) {
                    std::map temp_map = iter_umap->second;
                    auto iter_map = temp_map.find(p);
                    if (iter_map!=temp_map.end()) {
                        iter_map->second = iter_map->second+1;
                        iter_umap->second = temp_map;
                    }
                }
            }
        }
    }

    // after completing the construction of the inverted index table write the table to the disk.
    writeToDisk(dictionary);
}

void libraryIndexer::setFileList(const std::vector<std::string> list)
{
    fileList = list;
}

std::vector<std::string> libraryIndexer::getFileList()
{
    return fileList;
}

void libraryIndexer::writeToDisk(const std::unordered_map<std::string, std::map<std::string, uint32_t>> dictionary)
{
    // this function writes the given inverted index table to the home directory with the name "database.dat"

    std::ofstream outdata;

    char* home = getenv("HOME");
    std::string homedir(home);
    std::string file_path;
    file_path = homedir + "/database.dat";

    outdata.open(file_path);


    for (auto const& i: dictionary) {
        outdata<< i.first<< ": ";
        for (auto const& j : i.second) {
            outdata<< j.first << " (" << j.second << ") ";
        }
        outdata<<std::endl;
    }

    outdata.close();
}
