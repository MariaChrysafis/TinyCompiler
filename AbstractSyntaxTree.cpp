//
// Created by Maria Chrysafis on 9/28/24.
//

#include "AbstractSyntaxTree.h"
AbstractSyntaxTree::AbstractSyntaxTree(vector<std::string> ans) {
    this->tree = Tree("main");
}

void AbstractSyntaxTree::print() {
    this->tree.print();
}

void AbstractSyntaxTree::generate(vector<std::string>) {

}