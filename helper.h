//
// Created by Maria Chrysafis on 9/28/24.
//
#include <iostream>
#include <cassert>
using namespace std;
bool isPrefixOf (string s, string prefix) {
    if (prefix.size() > s.size()) {
        return false;
    }
    for (int i = 0; i < prefix.size(); i++) {
        if (s[i] != prefix[i]) {
            return false;
        }
    }
    return true;
}

string substring (string s, int i, int j) {
    string ans = "";
    for (int x = i; x <= j; x++) {
        ans += s[x];
    }
    return ans;
}

string remove_character (string s, char c) {
    string ans = "";
    for (char ch: s) {
        if (ch != c) {
            ans += ch;
        }
    }
    return ans;
}

int get_index_of (string s, char c) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            return i;
        }
    }
    return -1;
}

bool is_number (char c) {
    return '0' <= c and c <= '9';
}

vector<string> get_vec (vector<string> ans, int i, int j) {
    vector<string> res;
    for (int x = i; x <= j; x++) {
        res.push_back(ans[x]);
    }
    return res;
}