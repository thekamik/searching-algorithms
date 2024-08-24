#include "node.h"
#include <cmath>

Node::Node() {
    id = -1; // or any default value
    position = VectorXY{0, 0}; // or any default value
}

Node::Node(int nodeId, VectorXY nodePossition) {
    id = nodeId;
    position = nodePossition;
}

float Node::findDistance(int targetId) {
    for (auto connection: connections) {
        if (connection.nodeId == targetId) {
            return connection.weight;
        }
    }

    throw std::runtime_error("No connection to this node.");
}