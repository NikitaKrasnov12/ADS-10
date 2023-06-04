// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>

struct Node {
    std::vector<Node*> otherNum;
    char num;
};
class Tree {
 private:
  Node* root;
    std::vector<char> manyNum;
    void createRearrangementTree(std::vector<char> other, Node* node) {
        if (other.empty()) {
            return;
        }
        int j = 0;
        for (int i = 0; i < other.size(); i++) {
            Node* root1 = new Node;
            root1->num = other[i];
            node->otherNum.push_back(root1);
            std::vector<char> notall;
            for (char j : other) {
                if (j == other[i]) {
                    continue;
                }
                notall.push_back(j);
            }
            createRearrangementTree(notall, root1);
        }
    }
  void createRearrangements(Node* node) {
        if (node->otherNum.empty()) {
            manyNum.push_back(node->num);
            rearrangements.push_back(manyNum);
            manyNum.pop_back();
        }
        for (Node* root1 : node->otherNum) {
            manyNum.push_back(node->num);
            createRearrangements(root1);
            manyNum.pop_back();
        }
  }

 public:
  std::vector<std::vector<char>> rearrangements;
  explicit Tree(const std::vector<char> other) {
    manyNum = other;
    std::vector<char> goVec;
    root = new Node;
    root->num = 0;
    createRearrangements(root);
    createRearrangementTree(manyNum, root);
  }
};
#endif  // INCLUDE_TREE_H_
