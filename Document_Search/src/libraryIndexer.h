/*
 * libraryIndexer.h
 *
 *  Created on: Dec 14, 2020
 *      Author: akifdev18
 */

#ifndef SRC_LIBRARYINDEXER_H_
#define SRC_LIBRARYINDEXER_H_

#include <unordered_map>
#include <map>
#include <string>
#include <vector>

class libraryIndexer {
public:
    static libraryIndexer& getInstance() {
        static libraryIndexer instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }
    static libraryIndexer* getInstancePtr() {
        return &getInstance();
    }


    libraryIndexer();
    virtual ~libraryIndexer();
private:
    std::vector<std::string> fileList;
    virtual void writeToDisk(const std::unordered_map<std::string, std::map<std::string, uint32_t>> dictionary);

public:
    virtual void createInvertedIndex();

    virtual void setFileList(const std::vector<std::string> list);
    virtual std::vector<std::string> getFileList();



};

#endif /* SRC_LIBRARYINDEXER_H_ */
