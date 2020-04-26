//
// Created by AL865 on 4/18/2020.
//

#ifndef PROJECT_2_STUFF_GRAPHER_H
#define PROJECT_2_STUFF_GRAPHER_H

#include "node.h"
#include <stack>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <iostream> //for testing to be removed

class grapher {
private:
    std::string fileOutput;

    std::queue<nodeAndChildren> returnPathSegments(std::queue<nodeAndChildren>, int);
    std::string createGraphvisStrings(std::queue<nodeAndChildren>);
    std::string nodeHeader(int);
    std::string nodeContent(std::string);
    std::string parentChildRelationship(std::string, std::string);
    std::string contentLine(std::vector<char>);

public:
    grapher();
    void generateGraphFiles(std::queue<nodeAndChildren>, int); //uses the method in private

};

#endif //PROJECT_2_STUFF_GRAPHER_H
