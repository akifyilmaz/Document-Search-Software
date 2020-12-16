/*
 * fileSystemAnalyzer.cpp
 *
 *  Created on: Dec 14, 2020
 *      Author: akifdev18
 */

#include "fileSystemAnalyzer.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>

fileSystemAnalyzer::fileSystemAnalyzer() {
    // TODO Auto-generated constructor stub

}

fileSystemAnalyzer::~fileSystemAnalyzer() {
    // TODO Auto-generated destructor stub
}

bool fileSystemAnalyzer::findFiles(const std::string path_dir, std::vector<std::string>& files)
{
    // this function searches the given path and writes the addresses of .txt files to the vector "files"


    // check if the given folder exists or not
    struct stat info;
    if (stat( path_dir.c_str(), &info)!=0) {
        std::cout<<"cannot access "<<path_dir<<"!"<<std::endl;
        return false;
    } else if (info.st_mode & S_IFDIR) {
        // path_dir is a directory
    }
    else {
        std::cout<<path_dir<<" is not a directory"<<"!"<<std::endl;
        return false;
    }
    //

    std::string txt(".txt");

    for(auto& p: fs::recursive_directory_iterator(path_dir)) {
        if (p.path().string().find(txt)!=std::string::npos)
            files.push_back(p.path());
    }

    if (files.size()!=0)
        return true;

    return false;
}
