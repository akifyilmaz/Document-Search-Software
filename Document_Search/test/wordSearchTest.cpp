/*
 * wordSearchTest.cpp
 *
 *  Created on: Dec 16, 2020
 *      Author: akifdev18
 */

#include "gtest/gtest.h"
#include "wordSearch.h"
#include <fstream>
namespace {
class wordSearchTest : public ::testing::Test {
protected:
    wordSearch word_Search;
    std::string search_Result1 = "to: /home/akifdev18/dir/dir2/file1.txt (2) ";
    std::string search_Result2 = "be: /home/akifdev18/dir/dir2/file1.txt (2) ";
    std::string search_Result3 = "or: /home/akifdev18/dir/dir2/file1.txt (1) ";
    std::string search_Result4 = "not: /home/akifdev18/dir/dir2/file1.txt (1) ";
};
};
TEST_F(wordSearchTest, wordSearch) {
    // check the search results for library index "/home/akifdev18/dir/dir2/"
    ASSERT_TRUE(search_Result1.compare(word_Search.findWord("to"))==0);
    ASSERT_TRUE(search_Result2.compare(word_Search.findWord("be"))==0);
    ASSERT_TRUE(search_Result3.compare(word_Search.findWord("or"))==0);
    ASSERT_TRUE(search_Result4.compare(word_Search.findWord("not"))==0);
}



