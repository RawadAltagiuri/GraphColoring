#include <iostream>
#include <vector>
#include <unordered_set>
#include "NODECLASS.H"
#include "Parser.h"
using namespace std;

void solution(Node& graph, int& colors){
    if(graph.color!=0) return; //if the graph has been colored return, stopping condition.
    unordered_set<int>set;

    for(Node* i : graph.adj){
        if(i->color!=0){
            set.insert(i->color);
        }
    }
    int color = 1; //we start with the minimum color which is one
    for(auto s : set){
        if(set.count(color)) //if the adjacent nodes have the color then increase to a different color.
            color++;
    }

    if(color>colors) colors=color; //this line is to check how many colors we used.

    graph.color = color; //set the graph color

    // for(Node* i : graph.adj){
    //     solution(*i, colors); //visit its adjacent graphs.
    // }
}

int main(){
    int size = 0;
    Node* graph = parse("Instance.col", size); //the file that contains our instance

    int colors = 0;
    for(int i = 1; i < size; i++){ // coloring the graphs
        solution(graph[i], colors);
    }

    cout << "Colors assigned to nodes:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Node " << i << ": " << graph[i].color << endl;
    }
    delete[] graph;
    cout << colors;
}

