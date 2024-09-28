//
// Created by Maria Chrysafis on 9/28/24.
//
#include <iostream>
#include <vector>
#include "AbstractSyntaxTree.h"
#include <fstream>
using namespace std;
int main() {
    std::ifstream file("/Users/mariachrysafis/TinyCompiler/code.txt");
    std::string str;
    vector<string> input = {};
    while (std::getline(file, str)) {
        cout << str << '\n';
        input.push_back(str);
    }
    cout << '\n';
    AbstractSyntaxTree asl(input);
    asl.generate(input);
    for (auto& p: asl.values) {
        cout << p.first << " " << p.second << '\n';
    }
}