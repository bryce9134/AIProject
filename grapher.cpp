//
// Created by AL865 on 4/24/2020.
//
#include "grapher.h"

grapher::grapher(){
    fileOutput = "digraph D { \n node [shape=plaintext fontname=\"Sans serif\" fontsize=\"8\"]; \n \n";
}

void grapher::generateGraphFiles(std::queue<nodeAndChildren> nAndC, int setting){
    std::string fileName = "tree";
    std::ofstream fout;

    std::queue<nodeAndChildren> tree = returnPathSegments(nAndC, setting);
    createGraphvisStrings(tree);

    switch (setting){
        case beginning:
            fileName += "Beginning.dot";
            fout.open(fileName);
            break;
        case middle1:
            fileName += "Middle1.dot";
            fout.open(fileName);
            break;
        case middle2:
            fileName += "Middle2.dot";
            fout.open(fileName);
            break;
        case end:
            fileName += "End.dot";
            fout.open(fileName);
            break;
    }

    if(!fout){
        std::cout << "problem opening file" << std::endl;
        return;
    }

    fout << fileOutput;
    fout.close();
}

std::queue<nodeAndChildren> grapher::returnPathSegments(std::queue<nodeAndChildren> nAndC, int setting){
    int totalSize = nAndC.size(),
        numberOfSegments;

    std::queue<nodeAndChildren> cutUpQueue;

    switch (setting){
        case beginning:
            numberOfSegments = totalSize * 10 / 100;
            for(int i = 0; i < numberOfSegments; i++){
                nodeAndChildren temp = nAndC.front();
                cutUpQueue.push(temp);
                nAndC.pop();
            }
            break;
        case middle1:
            numberOfSegments = totalSize * 40 / 100;
            for(int i = 0; i < numberOfSegments; i++){
                nodeAndChildren temp = nAndC.front();
                cutUpQueue.push(temp);
                nAndC.pop();
            }
            break;
        case middle2:
            numberOfSegments = totalSize * 60 / 100;
            for(int i = 0; i < numberOfSegments; i++){
                nodeAndChildren temp = nAndC.front();
                cutUpQueue.push(temp);
                nAndC.pop();
            }
            break;
        case end:
            return nAndC;
    }
    return cutUpQueue;
}

/*
 * task_menu [ label=<
   <table border="1" cellborder="0" cellspacing="1">
     <tr><td align="left"><b>Task 1</b></td></tr>
     <tr><td align="left">1 2 3</td></tr>
     <tr><td align="left">4 5 6</td></tr>
     <tr><td align="left">7 8  *</td></tr>
     <tr><td align="left"><font color="darkgreen">done</font></td></tr>
   </table>>];
 */
/*
  task_menu        -> task_ingredients;
  task_ingredients -> task_cook;
  task_invitation  -> task_cook;
  task_table       -> task_eat;
  task_cook        -> task_eat;

}
 */
std::string grapher::createGraphvisStrings(std::queue<nodeAndChildren> nAndC){
    int numberOfTreeSections = nAndC.size();
    int nodeNumber = 0;

    std::string topOfFile;
    std::string bottomOfFile;

    std::string parent;
    std::string newParent;
    std::vector<std::string> childrenNames;

    const std::string tableSettings = "<table border=\"1\" cellborder=\"0\" cellspacing=\"1\">\n";
    const std::string nodeTail = "<tr><td align=\"left\"><font color=\"darkgreen\">done</font></td></tr>\n"
                                 "   </table>>];\n\n";

    while(numberOfTreeSections != 0){
        nodeAndChildren currentFamily = nAndC.front();
        nAndC.pop();

        //If its the root
        if(parent.empty()){
            nodeNumber++;
            parent = "node_" + std::to_string(nodeNumber);
            //top of file parent
            topOfFile += nodeHeader(nodeNumber);
            topOfFile += tableSettings;
            topOfFile += contentLine(currentFamily.first.eightState);
        }

        //top of file children
        int numberOfChildren = currentFamily.second.size();
        std::string childName;
        for(int i = 0; i < numberOfChildren; i++){
            nodeNumber++;
            if(currentFamily.second[i].parent == nAndC.front().first.parent){
                newParent = "node_" + std::to_string(nodeNumber);
            }
            topOfFile += nodeHeader(nodeNumber);
            childName = "node_" + std::to_string(nodeNumber);
            childrenNames.push_back(childName);
            topOfFile += tableSettings;
            topOfFile += contentLine(currentFamily.second[i].eightState);
        }

        //Connecting parent and children in bottom
        for(const auto& kid : childrenNames){
            bottomOfFile += parentChildRelationship(parent, kid);
        }
        childrenNames.clear();
        parent = newParent;
        numberOfTreeSections--;
    }

    return (topOfFile + bottomOfFile + "\n}");
}

std::string grapher::contentLine(std::vector<char> node){
    std::string temp;
    std::string contentLine;
    std::string finalContentLine;
    for(int i = 0; i < 9; i++){
        if(i % 3 == 0 && i != 0){
            temp += node[i];
            contentLine = nodeContent(temp);
            finalContentLine += contentLine;
            temp.clear();
            contentLine.clear();
        }
        temp += node[i] + " ";
    }

    return finalContentLine;
}

std::string grapher::nodeHeader(int nodeNumber){
    return ("node_" + std::to_string(nodeNumber) + "[ label=<\n");
}

std::string grapher::nodeContent(std::string item){
    std::string n = "<tr><td align=\"left\">" + item + "</td></tr>\n";
    return n;
}

std::string grapher::parentChildRelationship(std::string nodeHeader1, std::string nodeHeader2){
    std::string n = nodeHeader1 + " -> " + nodeHeader2 + ";\n";
    return n;
}