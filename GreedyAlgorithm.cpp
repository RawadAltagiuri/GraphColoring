#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include "NODECLASS.H"
#include "Parser.h"
#include <chrono>
using namespace std;
auto start = chrono::steady_clock::now();

vector<Node*> HighestDegVector(Node& graph){

    priority_queue<pair<int, Node*>>pq;

    for(int i = 0; i < graph.adj.size(); i++){
        pq.push({graph.adj[i]->adj.size(), graph.adj[i]});
    }

    vector<Node*>returnal;

    for(int i = 0; i < graph.adj.size() ; i++){
        returnal.push_back(pq.top().second);
        pq.pop();
    }
    
    return returnal;
}

void solution(Node& graph, int& colors){
    if(graph.color!=-1) return; //if the graph has been colored return, stopping condition.
    unordered_set<int>set;

    for(Node* i : graph.adj){
        if(i->color!=-1){
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

    // graph.adj = HighestDegVector(graph); this ordered the adjacent nodes from highest degree to smallest
    
    for(Node* i : graph.adj){
        solution(*i, colors); //visit its adjacent graphs.
    }
}

int HighestDeg(Node* graph, int size){
    int s = 1;
    for(int i = 1; i < size; i++){
        if(graph[i].adj.size() > graph[s].adj.size()){
            s = i;
        }
    }
    return s;
}

int main(){
     
    int size = 0;
    Node* graph = parse("miles750.col", size); //the file that contains our instance
    // int sDeg = HighestDeg(graph, size); //s degree is the vertex with the smallest degree
    int colors = 0;//this will be the number of colors we needed to color the graph
    
    solution(graph[1], colors);
    

    cout << "Colors assigned to nodes:" << endl;
    for (int i = 1; i < size; i++) {
        cout << "Node " << i << ": " << graph[i].color << endl;
    }
    delete[] graph;
    cout << colors << endl;
    auto end = chrono::steady_clock::now(); //used to measure time
    auto diff = end-start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
}

