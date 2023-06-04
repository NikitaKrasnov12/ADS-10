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
  void createRearrangements(Node* node, std::vector<char> nowVal) {
        if (node->num) {
            nowVal.push_back(node->num);
        }
        if (node->otherNum.empty()) {
            rearrangements.push_back(nowVal);
            return;
        }
        for (int i = 0; i < node->otherNum.size(); i++) {
            createRearrangements(node->otherNum[i], nowVal);
        }
    }

 public:
  std::vector<std::vector<char>> rearrangements;
  explicit Tree(const std::vector<char> other) {
    manyNum = other;
    std::vector<char> goVec;
    root = new Node;
    root->num = 0;
    createRearrangements(root, goVec);
    createRearrangementTree(manyNum, root);
  }
  std::vector<char> getOrdPerm(int n)const {
        if (n - 1 > tree.rearrangements.size()) {
            return std::vector<char>();
        }
        return tree.rearrangements[n - 1];
  }
};
#endif  // INCLUDE_TREE_H_
