#ifndef Parser
#define Parser
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "NODECLASS.H"

using namespace std;

// Function to parse the DIMACS graph file
void parseDIMACS(const string& filename, vector<vector<int>>& adjacencyList) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    int numVertices = 0;
    int numEdges = 0;

    while (getline(file, line)) {
        if (line.empty() || line[0] == 'c') {
            // Ignore empty lines or comment lines starting with 'c'
            continue;
        }
        else if (line[0] == 'p') {
            // Process the problem line to extract the number of vertices and edges
            sscanf(line.c_str(), "p edge %d %d", &numVertices, &numEdges);
            adjacencyList.resize(numVertices + 1); // Adjust size to accommodate 1-based indexing
        }
        else {
            // Process the edge lines
            int u, v;
            sscanf(line.c_str(), "%*c %d %d", &u, &v);
            adjacencyList[u].push_back(v);
            adjacencyList[v].push_back(u);
        }
    }

    file.close();
}

Node* parse(string fname, int& size) {
    string filename = fname; // Replace with the actual filename
    vector<vector<int>> adjacencyList;

    // Parse the DIMACS graph file
    parseDIMACS(filename, adjacencyList);
    Node* graph = new Node[adjacencyList.size()]; //create a graph

    // Display the adjacency list representation of the graph
    for (int u = 1; u < adjacencyList.size(); ++u) {
        for (int v : adjacencyList[u]) {
            graph[u].adj.push_back(&graph[v]); //connect the adjacent.
        }
    }
    size = adjacencyList.size();//we will pass the size back to know how many we will color
    return graph;
}


#endif