#ifndef NODECLASS
#define NODECLASS
#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
        int id;
        int color;
        vector<Node*>adj;
        Node(){
            this->id = 0;
            this->color=-1;
        }
        void add(int, int);
        void multiadd(int, vector<int>&);
};
void Node::add(int vertex, int adj){
    this[vertex].adj.push_back(&this[adj]);
}
void Node::multiadd(int vertex, vector<int>&vec){
    for(int i : vec){
        this[vertex].adj.push_back(&this[i]);
    }
}
#endif