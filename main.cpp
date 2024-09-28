//
// Created by Maria Chrysafis on 9/28/24.
//
#include <iostream>
#include <vector>
#include "AbstractSyntaxTree.h"
using namespace std;
int main() {
    vector<string> input = {"let $x = $y + 10"};
    AbstractSyntaxTree asl(input);
    asl.tree.parse_expression("5+10*3+10");
    cout << asl.tree.traverse_tree();
}