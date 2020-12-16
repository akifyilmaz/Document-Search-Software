/*
 * libraryIndexerTest.cpp
 *
 *  Created on: Dec 16, 2020
 *      Author: akifdev18
 */

#include "gtest/gtest.h"
#include "libraryIndexer.h"
#include <fstream>
namespace {
class libraryIndexerTest : public ::testing::Test {
protected:
    libraryIndexer library_Indexer;
    std::vector<std::string> file_path_vector = {"/home/akifdev18/dir/dir2/file1.txt"};
    std::vector<std::string> db = {"not: /home/akifdev18/dir/dir2/file1.txt (1) ",
            "or: /home/akifdev18/dir/dir2/file1.txt (1) ",
            "to: /home/akifdev18/dir/dir2/file1.txt (2) ",
            "be: /home/akifdev18/dir/dir2/file1.txt (2) "};

};
};
TEST_F(libraryIndexerTest, libraryIndexer) {
    // check the inverted index table for the file1.txt which path is "/home/akifdev18/dir/dir2/".
    library_Indexer.setFileList(file_path_vector);
    library_Indexer.createInvertedIndex();

    int counter = 0;
    std::ifstream file;
    char* home = getenv("HOME");
    std::string homedir(home);
    std::string file_path;
    file_path = homedir + "/database.dat";
    file.open(file_path.c_str());
    std::string str;
    while (std::getline(file,str)) {
        ASSERT_TRUE(str.compare(db[counter])==0);
        counter++;
    }
}



