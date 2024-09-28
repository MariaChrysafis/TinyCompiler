//
// Created by Maria Chrysafis on 9/28/24.
//

#include <vector>
#include <map>
#include "Tree.h"
using namespace std;
class AbstractSyntaxTree {
public:
    Tree tree;
    map<string,int> values;
    void print();
    void generate (vector<string>);
    AbstractSyntaxTree(vector<string>);
};
