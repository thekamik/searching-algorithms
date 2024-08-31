#include "graph.h"
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cmath>


void Graph::saveNodes(std::string path) {

    // Zapisuje mapę do pamięci w formie binarnej. Ta forma jest często ładowana
    std::ofstream outFile(path.c_str(), std::ios::binary);
    if (!outFile) {
        throw std::runtime_error("Error opening file for writing: ");
    }

    size_t size = nodes.size();
    outFile.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (const auto& node : nodes) {
        node.save(outFile);
    }

    outFile.close();
}


void Graph::loadNodes(std::string path) {
    nodes.clear();
    
    // Ładowana jest mapa, zapisana w pamięci
    std::ifstream inFile(path.c_str(), std::ios::binary);
    if (!inFile) {
        throw std::runtime_error("Error opening file for reading: ");
    }

    size_t size;
    inFile.read(reinterpret_cast<char*>(&size), sizeof(size));
    nodes.resize(size);
    for (auto& node : nodes) {
        node.load(inFile);
    }

    inFile.close();
}


void Graph::addNode(int nodeId, float xPos, float yPos) {
    // Check if this Id exist
    for (auto node: nodes) {
        if (node.id == nodeId) {
            throw std::runtime_error("Id already taken.");
        }
    }

    // Create node, and add it to vector
    VectorXY position;
    position.x = xPos;
    position.y = yPos;
    Node newNode(nodeId, position);
    nodes.push_back(newNode);
}


void Graph::addConnection(int startNode, int endNode, float weight) {
    inputValidation(startNode, endNode);

    Connection newConnection;
    newConnection.nodeId = endNode;
    newConnection.weight = weight; 
    
    int startNodeIndex = getNodeIndex(startNode);
    nodes[startNodeIndex].connections.push_back(newConnection);
}


void Graph::inputValidation(int start, int end) {
    bool startExist = false;
    bool endExist = false;

    for (auto node: nodes) {
        if (node.id == start) {
            startExist = true;
        }

        if (node.id == end) {
            endExist = true;
        }
    }

    if ((startExist == false) || (endExist == false)) {
        // Exception
        throw std::runtime_error("Wrong input.");
    }
}


int Graph::getNodeIndex(int nodeID) {
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i].id == nodeID) {
            // If node is in the vecor, return index
            return i;
        }
    }

    // Node not in the list
    return -1;
}


std::vector<int> Graph::getTrace(int start, int end) {
    std::vector<int> trace;
    int previousNode = end;

    int i = 0;
    while (previousNode != start) {
        trace.push_back(previousNode);
        previousNode = nodes[previousNode].previousNode;

        if (i > nodes.size()) {
            throw std::runtime_error("Algorithm error");
        }

        i++;
    }
    trace.push_back(start);

    std::reverse(trace.begin(), trace.end());

    return trace;
}


float Graph::euclideanDistance(VectorXY start, VectorXY end) {
    float x = end.x - start.x;
    float y = end.y - start.y;
    return sqrt(x * x + y * y);
}


float Graph::dijkstra(int start, int end) {
    inputValidation(start, end);

    std::vector<int> Q;

    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i].id == start) {
            nodes[i].distance = 0;
        }
        else {
            nodes[i].distance = std::numeric_limits<float>::max();
        }
        nodes[i].previousNode = -1;  // Undefined
        Q.push_back(nodes[i].id);
    }

    while (Q.size() > 0) {
        int actualNodeId = -1;
        float smallestDistance = std::numeric_limits<float>::max();
        
        // Find node with smallest distance
        for (auto node: Q) {
            int index = getNodeIndex(node);
            if (nodes[index].distance <= smallestDistance) {
                actualNodeId = node;
                smallestDistance = nodes[index].distance;
            } 
        }

        // Remove that node from Q
        Q.erase(std::remove(Q.begin(), Q.end(), actualNodeId), Q.end());

        // Update distance for each connection
        int index = getNodeIndex(actualNodeId);

        // For each connection that is still in Q
        for (auto connection: nodes[index].connections) {
            if (std::find(Q.begin(), Q.end(), connection.nodeId) != Q.end()) {
                int connectionIndex = getNodeIndex(connection.nodeId);
                float alt = nodes[index].findDistance(connection.nodeId) + nodes[index].distance;

                if (alt <= nodes[connectionIndex].distance) {
                    nodes[connectionIndex].distance = alt;
                    nodes[connectionIndex].previousNode = actualNodeId;
                }
            }
        }
    }

    // Return calculated distance
    int index = getNodeIndex(end);
    return nodes[index].distance;

}


float Graph::bellmanFord(int start, int end) {
    inputValidation(start, end);

    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i].id == start) {
            nodes[i].distance = 0;
        }
        else {
            nodes[i].distance = std::numeric_limits<float>::max();
        }
        nodes[i].previousNode = -1; // No previous node
    }

    // Relax edges
    for (int k = 0; k < nodes.size()-1; k++) {
        for (auto node: nodes) {
            for (auto connection: node.connections) {
                // Get node index
                int nodeIndex = getNodeIndex(connection.nodeId);
                float w = node.findDistance(connection.nodeId);

                // Check new distance
                if (node.distance + w < nodes[nodeIndex].distance) {
                    // update distance and predecessor
                    nodes[nodeIndex].distance = node.distance + w;
                    nodes[nodeIndex].previousNode = node.id;
                }
            }
        }        
    }

    // Check for negative-weight cycles
    for (auto node: nodes) {
        for (auto connection: node.connections) {
            // Get node index
            int nodeIndex = getNodeIndex(connection.nodeId);
            float w = node.findDistance(connection.nodeId);

            // Check new distance
            if (node.distance + w < nodes[nodeIndex].distance) {
                throw std::runtime_error("Graph contain negative-weight cycles.");
            }
        }
    }
        

    // Return calculated distance
    int index = getNodeIndex(end);
    return nodes[index].distance;
}


float Graph::aStar(int start, int end) {
    inputValidation(start, end);

    int endIndex = getNodeIndex(end);

    // Set of discovered nodes that may be expanded
    std::vector<int> openSet = {start};

    // Set nodes values
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i].previousNode = -1;

        if (nodes[i].id == start) {
            nodes[i].distance = 0;
            nodes[i].estimatedDistance = euclideanDistance(nodes[i].position, nodes[endIndex].position);
        }
        else {
            nodes[i].distance = std::numeric_limits<float>::max();      // gScore
            nodes[i].estimatedDistance = std::numeric_limits<float>::max();  // fScore
        }
    }

    // Execute algorithm
    while (openSet.size() > 0) {
        // Get Node with lowest fScore
        float lowestFScore = std::numeric_limits<float>::max();
        int bestNodeId = -1;
        for (int id: openSet) {
            int index = getNodeIndex(id);
            if (nodes[index].estimatedDistance <= lowestFScore) {
                bestNodeId = id;
                lowestFScore = nodes[index].estimatedDistance;
            }
        }
        int bestNodeIndex = getNodeIndex(bestNodeId);

        // If this is our target, return assigned distance
        if (bestNodeId == end) {
            return nodes[bestNodeIndex].distance;
        }

        // Remove node from openSet
        openSet.erase(std::remove(openSet.begin(), openSet.end(), bestNodeId), openSet.end());

        for (auto connection: nodes[bestNodeIndex].connections) {
            int neighborIndex = getNodeIndex(connection.nodeId);
            
            // Calculate new gScore
            float tentativeGScore = nodes[bestNodeIndex].distance + nodes[bestNodeIndex].findDistance(connection.nodeId);
            
            if (tentativeGScore < nodes[neighborIndex].distance) {
                // This path to neighbor is better than any previous one. Record it!
                nodes[neighborIndex].previousNode = bestNodeId;
                nodes[neighborIndex].distance = tentativeGScore;
                nodes[neighborIndex].estimatedDistance = tentativeGScore + euclideanDistance(nodes[neighborIndex].position, nodes[endIndex].position);
                
                // Check if node is in openSet
                bool nodeInOpenSet = false;
                for (auto i: openSet) {
                    if (i == connection.nodeId) {
                        nodeInOpenSet = true;
                    }
                }

                // If not, add it to openSet
                if (nodeInOpenSet == false) {
                    openSet.push_back(connection.nodeId);
                }
            }
        }
    }

    // Open set is empty but goal was never reached
    throw std::runtime_error("Open set is empty but goal was never reached");
}

Node Graph::getNode(int nodeID) {
    int index = getNodeIndex(nodeID);

    return nodes[index];
}