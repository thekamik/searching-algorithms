#ifndef MAP_H
#define MAP_H

#include "node.h"
#include <vector>
#include <algorithm>


class Graph {
public:
    
    void addNode(int nodeId, float xPos, float yPos);
    void addConnection(int startNode, int endNode, float weight); 
    
    void saveNodes(std::string path);
    void loadNodes(std::string path);

    float dijkstra(int start, int end);
    float bellmanFord(int start, int end);
    float aStar(int start, int end);

    std::vector<int> getTrace(int start, int end); 
    std::vector<Node> nodes;
    Node getNode(int nodeID);    // Return node with given id
private:
    int getNodeIndex(int nodeID);    // Return index of node with given Id
    void inputValidation(int start, int end);   // Check if nodes exist

    float euclideanDistance(VectorXY start, VectorXY end);
};

#endif