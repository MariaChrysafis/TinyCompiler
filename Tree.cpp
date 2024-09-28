//
// Created by Maria Chrysafis on 9/28/24.
//

#include "Tree.h"
#include "helper.h"
#include <utility>
#include <string>
using namespace std;
const string ASSIGN = "assign";
const string VARIABLE = "variable";
const string LEFTOPERATION = "left";
const string RIGHTOPERATION = "right";

Tree::Tree (string s) {
    this->currentNode = s;
}
Tree::Tree() {
    this->currentNode = "main";
}

void Tree::print() {
    cout << "current node: " << this->currentNode << '\n';
    if (this->neighbors.size() == 0) {
        return;
    }
    cout << "{";
    for (auto& p: this->neighbors) {
        cout << "EDGE TO " << p.second->currentNode << " is " << p.first << '\n';
        p.second->print();
    }
    cout << "}\n";
}

void Tree::parse_expression(string s) {
    //parse into a bunch of strings
    vector<string> res;
    for (int i = 0; i < s.size(); i++) {
//        cout << "WHEE " << s[i] << '\n';
        if (is_number(s[i])) {
            int num = 0;
            for (int j = i; j < s.size(); j++) {
                if (is_number(s[j])) {
                    num = 10 * num + (s[j] - '0');
                    i = j;
                } else {
                    break;
                }
            }
            res.push_back(to_string(num));
        } else if (s[i] != ' ') {
            string ans = ""; ans += s[i];
            res.push_back(ans);
        }
    }
    for (string s: res) {
        cout << s << ',';
    }
    cout << '\n';
    this->expression(res);
}

void Tree::expression(vector<string> strings) {
    if (strings.size() == 1) {
        this->currentNode = strings[0];
        return;
    }
    for (string op: {"+", "-", "*", "/"}) {
        for (int i = 0; i < strings.size(); i++) {
            if (strings[i] == op) {
                this->currentNode = strings[i];
                this->neighbors[LEFTOPERATION] = new Tree();
                this->neighbors[LEFTOPERATION]->expression(get_vec(strings, 0, i - 1));
                this->neighbors[RIGHTOPERATION] = new Tree();
                this->neighbors[RIGHTOPERATION]->expression(get_vec(strings, i + 1, (int)strings.size() - 1));
                return;
            }
        }
    }
}


int Tree::traverse_tree () {
    auto apply_operation = [&] (char c, int x, int y) -> int {
        switch(c) {
            case '+' :
                return x + y;
            case '-' :
                return x - y;
            case '*' :
                return x * y;
            case '/' :
                return x / y;
            default :
                assert(false);
        }
    };
    if (this->neighbors.empty()) {
        return stoi(this->currentNode);
    }
    if (this->currentNode == "+" || this->currentNode == "-" || this->currentNode == "/" or this->currentNode == "*") {
        return apply_operation(this->currentNode[0], this->neighbors[LEFTOPERATION]->traverse_tree(), this->neighbors[RIGHTOPERATION]->traverse_tree());
    }
    assert(false);
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
            s = remove_character(s, ' ');
            for (int ind = 0; ind < s.size(); ind++) {
                if (s[ind] == '=') {
                    string variable = substring(s, 0, ind - 1);
                    string expression = substring(s, ind + 1, (int)s.size() - 1);
                    this->neighbors["VARIABLE"] = new Tree(variable);
                    this->neighbors["EXPRESSION"] = new Tree(expression);
                }
            }
        } else {
            /*
             * Just a regular expression
             */
            //find the first parenthesis
        }
    }
}
