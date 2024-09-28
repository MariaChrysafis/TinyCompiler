//
// Created by Maria Chrysafis on 9/28/24.
//
#include <iostream>
#include <vector>
#include "AbstractSyntaxTree.h"
using namespace std;
int main() {
    vector<string> input = {"let $y = 3", "let $x = $y * $y + 10"};
    AbstractSyntaxTree asl(input);
    asl.generate(input);
//    asl.tree.traverse_tree(values);
    cout << asl.values["$x"] << " " << asl.values["$y"] << '\n';
}