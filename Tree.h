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
    void generate(vector<string>&vec, int i, int j);
    Tree(string s);
    Tree();
    void print();
    vector<string> parse_expression(string s);
    void expression(vector<string> vec);
    int traverse_tree(map<string,int>& values);
};
