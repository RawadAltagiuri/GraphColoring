#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include "NODECLASS.H"
#include "Parser.h"
#include <chrono>
using namespace std;
// Function to perform graph coloring using DSatur algorithm
void colorGraph(vector<vector<int>>& graph, int numVertices, int &colors)
{
    vector<int> saturationDegree(numVertices, 0);
    vector<int> color(numVertices, -1);

    // Start with the vertex with the highest degree (most neighbors)
    int startVertex = 0;
    int maxDegree = 0;
    for (int i = 0; i < numVertices; i++) {
        int degree = count(graph[i].begin(), graph[i].end(), 1);
        if (degree > maxDegree) {
            maxDegree = degree;
            startVertex = i;
        }
    }
    if(startVertex!=0)
        color[startVertex] = 1;

    
    for (int i = 1; i < numVertices; i++)
    {
        // // Initialize saturation degree for each vertex
        // saturationDegree[i] = 0;

        // We will use this to check the colors of each adjacent vertex of the current [i] vertex
        unordered_set<int> usedColors;

        // Calculate saturation degree for current vertex
        for (int j = 0; j < numVertices; j++)
        { 
            if (graph[i][j] && color[j] != -1)
                usedColors.insert(color[j]);
        }

        saturationDegree[i] = usedColors.size();
    }

    // Assign colors to remaining vertices
    for (int i = 1; i < numVertices; i++)
    {
        // Find the vertex with the highest saturation degree
        int maxSaturation = -1;
        int vertex = -1;

        for (int j = 0; j < numVertices; j++)
        {
            if (color[j] == -1 && saturationDegree[j] > maxSaturation)
            {
                maxSaturation = saturationDegree[j];
                vertex = j;
            }
        }
        // Assign the lowest possible color to the selected vertex
        unordered_set<int> usedColors;

        for (int j = 0; j < numVertices; j++)
        {
            if (graph[vertex][j] && color[j] != -1)
                usedColors.insert(color[j]);
        }

        int chosenColor = 1;

        while (usedColors.find(chosenColor) != usedColors.end())
            chosenColor++;
        if(chosenColor > colors) colors = chosenColor;
        if(vertex!=0 )color[vertex] = chosenColor;

        // Update saturation degree for the adjacent vertices
        for (int j = 1; j < numVertices; j++)
        {
            if (graph[vertex][j] && color[j] == -1)
                saturationDegree[j]++;
        }
    }

    // Print the assigned colors
    std::cout << "Vertex\tColor\n";
    for (int i = 0; i < numVertices; i++)
    {
        std::cout << i << "\t" << color[i] << "\n";
    }
}

vector<vector<int>> turnToMatrix(Node* graph, int size){//turns the graph into a matrix
    vector<vector<int>>vec(size, vector<int>(size, 0));
    Node* temp = graph;
    for(int i = 0; i < vec.size(); i++){
        for(Node* n : temp->adj){
            vec[i][n->id]=1;
        }
        temp++;
    }
    return vec;
}


int main()
{
    int size = 0;
    Node* actualGraph = parse("homer.col", size);
    vector<vector<int>>graph = turnToMatrix(actualGraph, size);
    int numVertices = graph.size();
    int colors = 0;
    auto start = chrono::steady_clock::now();
    colorGraph(graph, numVertices, colors);
    auto end = chrono::steady_clock::now(); //used to measure time
    auto diff = end-start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    std::cout << colors << endl;
}
