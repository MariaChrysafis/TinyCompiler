//
// Created by Maria Chrysafis on 9/28/24.
//

#include "Tree.h"

#include <utility>
Tree::Tree() {
    this->currentNode = "main";
}
Tree::Tree(string s) {
    this->currentNode = std::move(s);
}

void Tree::print() {
    cout << "current node: " << this->currentNode << '\n';
    for (auto& p: this->neighbors) {
        cout << "PARENT OF " << p.second->currentNode << " is " << p.first << '\n';
        p.second->print();
    }
}
