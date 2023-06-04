// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <vector>
#include  "tree.h"

int fact(int n) {
    if (n > 1)
        return n * fact(n - 1);
    return 1;
}
std::vector<char> getPerm(const Tree& tree, int n) {
    if (tree.get_Size() == 0 || n > fact(tree.get_Size()))
        return {};
    if (tree.get_NumSet() == '*')
        n--;
    std::vector<char> resultat;
    int other_k = fact(tree.get_Size() - 1);
    resultat.push_back(tree[n / other_k].get_NumSet());
    std::vector<char> k = getPerm(tree[n / other_k], n % other_k);
    resultat.insert(resultat.end(), k.begin(), k.end());
    return resultat;
}
