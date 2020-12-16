/*
 * wordSearch.h
 *
 *  Created on: Dec 16, 2020
 *      Author: akifdev18
 */

#ifndef SRC_WORDSEARCH_H_
#define SRC_WORDSEARCH_H_

#include <string>

class wordSearch {
public:
    static wordSearch& getInstance() {
        static wordSearch instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }
    static wordSearch* getInstancePtr() {
        return &getInstance();
    }

    wordSearch();
    virtual ~wordSearch();

    virtual std::string findWord(std::string word);
};

#endif /* SRC_WORDSEARCH_H_ */
