//
// Created by Maria Chrysafis on 9/28/24.
//

#include "Tree.h"
#include "string_helper.h"
const string ASSIGN = "assign";
const string VARIABLE = "variable";

#include <utility>
Tree::Tree (string s) {
    this->currentNode = s;
}
Tree::Tree() {
    this->currentNode = "main";
}

void Tree::print() {
    cout << "current node: " << this->currentNode << '\n';
    for (auto& p: this->neighbors) {
        cout << "PARENT OF " << p.second->currentNode << " is " << p.first << '\n';
        p.second->print();
    }
}

void Tree::generate(vector<string> &vec, int i, int j) {
    for (int x = i; x <= j; x++) {
        this->currentNode = "main";
        string s = vec[x];
        if (isPrefixOf(s, "let")) {
            /*
             * This is a let statement
             */
            this->currentNode = ASSIGN;
            s = substring(s, 3, s.size() - 1);

        }
    }
}
