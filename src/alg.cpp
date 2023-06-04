// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <vector>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::vector<char> answer;
  if ( tree.rearrangements.size() < n ) {
       answer.push_back('1');
       answer.clear();
    } else {
        answer = tree.rearrangements[n - 1];
        reverse(answer.begin(), answer.end());
        answer.pop_back();
        reverse(answer.begin(), answer.end());
    }
    return answer;
}
