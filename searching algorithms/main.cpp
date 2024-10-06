#include <iostream>
#include "graph.h"

void displayTrace(Trace trace) {
    // function to display calculated trace
    std::cout << "Trace: [";
    for (int i = 0; i < trace.trace.size(); i++) {
        
        std::cout << trace.trace[i];
        if (i < trace.trace.size() - 1) {
            std::cout << ", ";
        }
        else {
            std::cout << "]" << std::endl << std::endl;
        }
    }
}

int main() {

    // Create Graph instance
    Graph map;

    // Create nodes
    map.addNode(0, 598, 146);           // id, xPos, yPos
    map.addNode(1, 274, 339);           // id, xPos, yPos
    map.addNode(2, 955, 279);           // id, xPos, yPos
    map.addNode(3, 620, 374);           // id, xPos, yPos
    map.addNode(4, 151, 554);           // id, xPos, yPos
    map.addNode(5, 562, 649);           // id, xPos, yPos
    map.addNode(6, 1048, 596);          // id, xPos, yPos
    map.addNode(7, 816, 795);           // id, xPos, yPos
    map.addNode(8, 288, 782);           // id, xPos, yPos
    map.addNode(9, 376, 507);           // id, xPos, yPos
    map.addNode(10, 854, 512);          // id, xPos, yPos
    map.addNode(11, 208.714, 117.857);  // id, xPos, yPos
    map.addNode(12, 1077.29, 93.8571);  // id, xPos, yPos
    map.addNode(13, 1107, 868.714);     // id, xPos, yPos
    map.addNode(14, 43, 836.714);       // id, xPos, yPos
    map.addNode(15, 17.8571, 291.571);  // id, xPos, yPos
    //---------------------------------------------------------------------------------
    map.addConnection(0, 3, 229.0589443789524);     // startId, endId, weight
    map.addConnection(0, 11, 390.30195777756484);   // startId, endId, weight
    map.addConnection(0, 12, 482.11802094550455);   // startId, endId, weight
    map.addConnection(0, 2, 380.9698150772578);     // startId, endId, weight
    map.addConnection(1, 11, 230.57859450738266);   // startId, endId, weight
    map.addConnection(1, 4, 247.69739602991388);    // startId, endId, weight
    map.addConnection(1, 3, 347.76572574076357);    // startId, endId, weight
    map.addConnection(2, 10, 253.9488137400921);    // startId, endId, weight
    map.addConnection(2, 0, 380.9698150772578);     // startId, endId, weight
    map.addConnection(3, 1, 347.76572574076357);    // startId, endId, weight
    map.addConnection(3, 0, 229.0589443789524);     // startId, endId, weight
    map.addConnection(3, 10, 271.6615541441225);    // startId, endId, weight
    map.addConnection(3, 7, 464.3888456886104);     // startId, endId, weight
    map.addConnection(4, 1, 247.69739602991388);    // startId, endId, weight
    map.addConnection(4, 9, 229.85647695899283);    // startId, endId, weight
    map.addConnection(4, 14, 302.6403902257596);    // startId, endId, weight
    map.addConnection(4, 15, 294.2720031899229);    // startId, endId, weight
    map.addConnection(5, 8, 304.5734722525913);     // startId, endId, weight
    map.addConnection(5, 9, 234.00854685246006);    // startId, endId, weight
    map.addConnection(5, 7, 292.97098832478275);    // startId, endId, weight
    map.addConnection(5, 6, 488.8813762049031);     // startId, endId, weight
    map.addConnection(6, 12, 502.9964176019646);    // startId, endId, weight
    map.addConnection(6, 13, 279.0231635474016);    // startId, endId, weight
    map.addConnection(6, 5, 488.8813762049031);     // startId, endId, weight
    map.addConnection(6, 10, 211.40482492128697);   // startId, endId, weight
    map.addConnection(7, 13, 300.19119540053134);   // startId, endId, weight
    map.addConnection(7, 8, 528.1600136322324);     // startId, endId, weight
    map.addConnection(7, 3, 464.3888456886104);     // startId, endId, weight
    map.addConnection(7, 5, 292.97098832478275);    // startId, endId, weight
    map.addConnection(8, 9, 288.73690446494714);    // startId, endId, weight
    map.addConnection(8, 14, 251.03510072497832);   // startId, endId, weight
    map.addConnection(8, 7, 528.1600136322324);     // startId, endId, weight
    map.addConnection(8, 5, 304.5734722525913);     // startId, endId, weight
    map.addConnection(9, 4, 229.85647695899283);    // startId, endId, weight
    map.addConnection(9, 8, 288.73690446494714);    // startId, endId, weight
    map.addConnection(9, 5, 234.00854685246006);    // startId, endId, weight
    map.addConnection(9, 10, 478.02614991232434);   // startId, endId, weight
    map.addConnection(10, 9, 478.02614991232434);   // startId, endId, weight
    map.addConnection(10, 3, 271.6615541441225);    // startId, endId, weight
    map.addConnection(10, 6, 211.40482492128697);   // startId, endId, weight
    map.addConnection(10, 2, 253.9488137400921);    // startId, endId, weight
    map.addConnection(11, 15, 258.0753961027862);   // startId, endId, weight
    map.addConnection(11, 1, 230.57859450738266);   // startId, endId, weight
    map.addConnection(11, 0, 390.30195777756484);   // startId, endId, weight
    map.addConnection(12, 0, 482.11802094550455);   // startId, endId, weight
    map.addConnection(12, 6, 502.9964176019646);    // startId, endId, weight
    map.addConnection(13, 6, 279.0231635474016);    // startId, endId, weight
    map.addConnection(13, 7, 300.19119540053134);   // startId, endId, weight
    map.addConnection(14, 8, 251.03510072497832);   // startId, endId, weight
    map.addConnection(14, 4, 302.6403902257596);    // startId, endId, weight
    map.addConnection(15, 11, 258.0753961027862);   // startId, endId, weight
    map.addConnection(15, 4, 294.2720031899229);    // startId, endId, weight


    // Select start and end nodes to test algorithms
    int startNode = 1;
    int endNode = 13;

    // Test Dijkstra algorithm
    std::cout << "Dijkstra" << std::endl;
    Trace trace1 = map.dijkstra(startNode, endNode);
    std::cout << "Distance: " << trace1.distance << std::endl;

    displayTrace(trace1);

    // Test Bellman-Ford algorithm
    std::cout << "Bellman-Ford" << std::endl;
    Trace trace2 = map.bellmanFord(startNode, endNode);
    std::cout << "Distance: " << trace2.distance << std::endl;

    displayTrace(trace2);

    // Test A* algorithm
    std::cout << "A*" << std::endl;
    Trace trace3 = map.aStar(startNode, endNode);
    std::cout << "Distance: " << trace3.distance << std::endl;

    displayTrace(trace3);
    

    /*
    Console output:
        Dijkstra
        Distance: 1109.86
        Trace: [1, 3, 10, 6, 13]

        Bellman-Ford
        Distance: 1109.86
        Trace: [1, 3, 10, 6, 13]

        A*
        Distance: 1109.86
        Trace: [1, 3, 10, 6, 13]
    */


    // Test Random Walker
    std::cout << "Random Walker" << std::endl;
    auto traceResult = map.randomWalker(startNode, endNode, 10);

    if (traceResult) {
        std::cout << "Distance: " << traceResult->distance << std::endl;

        Trace t = traceResult.value();
        displayTrace(t);

        // Try to mutate trace

        std::cout << "Mutation" << std::endl;

        // the intersection point is returned twice
        auto mutationResult = map.traceMutation(t, 10);

        if (mutationResult) {
            std::cout << "Distance: " << mutationResult->distance << std::endl;

            Trace tm = mutationResult.value();
            displayTrace(tm);            
        }
        else {
            std::cout << "impossible to generate mutation" << std::endl;
        }
    }
    else {
        std::cout << "impossible to generate trace" << std::endl;
    }
    
    return 0;
}
