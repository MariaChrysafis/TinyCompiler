//
// Created by Maria Chrysafis on 9/28/24.
//

#include "AbstractSyntaxTree.h"
using namespace std;
AbstractSyntaxTree::AbstractSyntaxTree(vector<string> ans) {
    this->tree = Tree();
}

void AbstractSyntaxTree::print() {
    this->tree.print();
}

void AbstractSyntaxTree::generate(vector<string> vec) {
    this->tree.generate(vec, 0, (int)vec.size() - 1);
    this->tree.traverse_tree(this->values);
}