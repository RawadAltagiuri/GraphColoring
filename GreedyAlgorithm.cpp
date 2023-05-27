#include <iostream>
#include <vector>
#include <unordered_set>
#include "NODECLASS.H"
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

    for(Node* i : graph.adj){
        solution(*i, colors); //visit its adjacent graphs.
    }
}

int main(){
    Node* graph = new Node[6]; //forming the graph;
    //the function multiadd takes two parameters, the first one is the vertex you want to add the adjacents to, and the second is a vector of the indexes of the parameters.
    graph->multiadd(0, {1, 2, 5});                          // graph[0].adj = { &graph[1], &graph[2] ,&graph[5]};
    graph->multiadd(1, {0, 2, 3});                          // graph[1].adj = { &graph[0], &graph[2], &graph[3] };
    graph->multiadd(2, {0, 1, 3, 5});                       // graph[2].adj = { &graph[0], &graph[1], &graph[3], &graph[5]};
    graph->multiadd(3, {1, 2, 4});                      // graph[3].adj = { &graph[1], &graph[2], &graph[4] };
    graph->multiadd(4, {3, 5});                        // graph[4].adj = { &graph[3], &graph[5] };
    graph->multiadd(5, {0, 2, 4});                  // graph[5].adj = { &graph[0], &graph[2], &graph[4]};
    int colors = 0;
    solution(graph[0], colors);
    cout << "Colors assigned to nodes:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << "Node " << i << ": " << graph[i].color << endl;
    }
    delete[] graph;
    cout << colors;
}

