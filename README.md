# Document-Search-Software

An efficient document search software which indexes the documents for a given library path for future search operations. Inverted-index data structures is used in this application. 

## Description

Application for indexing and searching for a given library on a Linux system.
Consist of 3 modules and tests for these modules
Modules: 
* Filesystem analyzer for discovering .txt files for a given library
* Library indexer that creates an inverted-index and serialize the table to the home directory.
* Library searcher that searches the inverted-index table for a given word. 

## Build

### librarySearch Software

* build codes under the "src" directory and exclude test folder.
* c++17 language standart should be used when building the code.
* build with -lstdc++fs library.

### librarySearch Test Software

* build codes under the "test" directory by including src files but exclude src/main.cpp file.
* c++17 language standart should be used when building the code.
* googleTestLib should be added to include paths which can be found in "googleTestLib" folder.
* pthread and -lstdc++fs libraries should be added to the build

## Usage of Software

* librarySearch Software is developed as a command line utility which takes 2 parameter:
 - ./librarySearch -index "_path_to_library_"
 - ./librarySearch -search "_some_word_"

binaries for librarySearch and librarySearchTest can be found in "binaries" folder.

## Examples

"dir" folder is added as an example library. It can be used in order to test librarySearch Software.
