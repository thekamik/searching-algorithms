#ifndef NODE_H
#define NODE_H

#include <vector>
#include <chrono>
#include <fstream>

typedef struct VectorXY {
    float x;                // Vector x component
    float y;                // Vector y component
} VectorXY;

typedef struct Connection {
    int nodeId;
    float weight;
} Connection;

class Node {
public:
    Node(); // Default constructor
    Node(int nodeId, VectorXY nodePossition); // Constructor
    
    float findDistance(int targetId);
    int id;
    VectorXY position;
    std::vector<Connection> connections;

    // Algorithm variables
    float distance;             // Distance to that node
    float estimatedDistance;    // Estimated distance to that node
    int previousNode;     // Trace to that node

    // Serialize the node to a binary stream
    void save(std::ofstream &outFile) const {
        outFile.write(reinterpret_cast<const char*>(&id), sizeof(id));
        outFile.write(reinterpret_cast<const char*>(&position), sizeof(position));
        size_t connSize = connections.size();
        outFile.write(reinterpret_cast<const char*>(&connSize), sizeof(connSize));
        outFile.write(reinterpret_cast<const char*>(connections.data()), connSize * sizeof(Connection));
    }

    // Deserialize the node from a binary stream
    void load(std::ifstream &inFile) {
        inFile.read(reinterpret_cast<char*>(&id), sizeof(id));
        inFile.read(reinterpret_cast<char*>(&position), sizeof(position));
        size_t connSize;
        inFile.read(reinterpret_cast<char*>(&connSize), sizeof(connSize));
        connections.resize(connSize);
        inFile.read(reinterpret_cast<char*>(connections.data()), connSize * sizeof(Connection));
    }
};

#endif