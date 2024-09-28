//
// Created by Maria Chrysafis on 9/28/24.
//
#include <iostream>
#include <vector>
#include "AbstractSyntaxTree.h"
using namespace std;
int main() {
    cout << "HELLO WORLD\n";
    vector<string> input = {"$x = $y + 10"};
    AbstractSyntaxTree asl(input);
    asl.tree.print();
}