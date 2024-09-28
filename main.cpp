//
// Created by Maria Chrysafis on 9/28/24.
//
#include <iostream>
#include <vector>
#include "AbstractSyntaxTree.h"
using namespace std;
int main() {
    vector<string> input = {"let $y = 3", "let $x = $y + 10"};
    AbstractSyntaxTree asl(input);
    asl.tree.generate(input, 0, (int)input.size() - 1);
    asl.tree.print();
    map<string,int> values;
    asl.tree.traverse_tree(values);
    cout << values["$x"] << " " << values["$y"] << '\n';
}