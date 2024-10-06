#ifndef MAP_H
#define MAP_H

#include "node.h"
#include <vector>
#include <algorithm>
#include <optional>

typedef struct Trace {
    float distance;
    std::vector<int> trace;
} Trace;

class Graph {
public:
    
    void addNode(int nodeId, float xPos, float yPos);
    void addConnection(int startNode, int endNode, float weight); 
    
    void saveNodes(std::string path);
    void loadNodes(std::string path);

    Trace dijkstra(int start, int end);
    Trace bellmanFord(int start, int end);
    Trace aStar(int start, int end);

    // Functions based on randomnes. It may not return correct solution. This function make few attempts in path generating.
    std::optional<Trace> randomWalker(int start, int end, int numberOfAttempts, Trace defaultTrace = {0.0f, {}});
    std::optional<Trace> traceMutation(Trace originalTrace, int numberOfAttempts);

    std::vector<Node> nodes;
    Node getNode(int nodeID);    // Return node with given id
private:

    std::vector<int> backtrackTrace(int start, int end); 
    int getNodeIndex(int nodeID);    // Return index of node with given Id
    void inputValidation(int start, int end);   // Check if nodes exist

    float euclideanDistance(VectorXY start, VectorXY end);
};

#endif