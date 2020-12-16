/*
 * fileSystemAnalyzer.h
 *
 *  Created on: Dec 14, 2020
 *      Author: akifdev18
 */

#ifndef SRC_FILESYSTEMANALYZER_H_
#define SRC_FILESYSTEMANALYZER_H_

#include <experimental/filesystem>
#include <vector>
#include <string.h>

namespace fs = std::experimental::filesystem;

class fileSystemAnalyzer {
public:
    static fileSystemAnalyzer& getInstance() {
        static fileSystemAnalyzer instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }
    static fileSystemAnalyzer* getInstancePtr() {
        return &getInstance();
    }

public:
    fileSystemAnalyzer();
    virtual ~fileSystemAnalyzer();

public:
    bool findFiles(const std::string path_dir, std::vector<std::string>& files);

};

#endif /* SRC_FILESYSTEMANALYZER_H_ */
