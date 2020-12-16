/*
 * fileSystemAnalyzerTest.cpp
 *
 *  Created on: Dec 16, 2020
 *      Author: akifdev18
 */

#include "gtest/gtest.h"
#include "fileSystemAnalyzer.h"
namespace {
  class fileSystemAnalyzerTest : public ::testing::Test {
  protected:
      fileSystemAnalyzer file_System_Analyzer;
      std::string path_dir = "/home/akifdev18/dir/";
      std::vector<std::string> files;
      std::vector<std::string> filesTest = { "/home/akifdev18/dir/dir1/dir3/dir5/file4.txt",
              "/home/akifdev18/dir/dir1/dir3/file4.txt", "/home/akifdev18/dir/dir1/file2.txt",
              "/home/akifdev18/dir/file3.txt", "/home/akifdev18/dir/dir2/file1.txt" };
      };
  };
// check if the constructed vector by fileSystemAnalyzer is same or not with the real .txt files for
// given example path (/home/akifdev18/dir/).
  TEST_F(fileSystemAnalyzerTest, fileSystemAnalyzer) {
    ASSERT_TRUE(file_System_Analyzer.findFiles(path_dir, files));
    EXPECT_EQ(files, filesTest);
  }
