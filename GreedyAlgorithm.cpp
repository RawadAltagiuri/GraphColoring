#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Node{
    public:
        int color;
        vector<Node*>adj;
        Node(){
            this->color=0;
        }
};

void solution(Node& graph, int& colors){
    if(graph.color!=0) return;
    unordered_set<int>set;
    for(Node* i : graph.adj){
        if(i->color!=0){
            set.insert(i->color);
        }
    }
    int color = 1;
    for(auto s : set){
        if(set.count(color))
            color++;
    }
    if(color>colors) colors=color;
    graph.color = color;
    for(Node* i : graph.adj){
        solution(*i, colors);
    }
}

int main(){
    Node* graph = new Node[6];
    graph[0].adj = { &graph[1], &graph[2] ,&graph[5]};
    graph[1].adj = { &graph[0], &graph[2], &graph[3] };
    graph[2].adj = { &graph[0], &graph[1], &graph[3], &graph[5]};
    graph[3].adj = { &graph[1], &graph[2], &graph[4] };
    graph[4].adj = { &graph[3], &graph[5] };
    graph[5].adj = { &graph[0], &graph[2], &graph[4]};


    int colors = 0;
    solution(graph[0], colors);
    cout << "Colors assigned to nodes:W" << endl;
    for (int i = 0; i < 6; i++) {
        cout << "Node " << i << ": " << graph[i].color << endl;
    }
    delete[] graph;
    cout << colors;
}

