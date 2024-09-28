//
// Created by Maria Chrysafis on 9/28/24.
//
#include <iostream>
#include <map>
using namespace std;
class Tree {
public:
    map<string,Tree*> neighbors;
    string currentNode;
    void generate (vector<string>&, int i, int j);
    Tree(string s);
    Tree();
    void print();
};
