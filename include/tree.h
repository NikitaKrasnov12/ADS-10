// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>

class Tree {
 private:
  struct Node {
  char num;
  std::vector<Node*> otherNum;
};
  std::vector<char> manyNum;
  Node* root;
  void createRearrangementTree(Node* node, std::vector<char> other) {
        if (other.empty()) {
            return;
        }
        for (auto ot : other) {
            Node* root1 = new Node;
            root1->num = ot;
            node->otherNum.push_back(root1);
            std::vector<char> notall = other;
            notall.erase(
                std::remove(notall.begin(), notall.end(), ot),
                notall.end());
            createRearrangementTree(root1, notall);
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
    root = new Node;
    root->num = '*';
    createRearrangements(root);
    createRearrangementTree(root, other);
  }
};
#endif  // INCLUDE_TREE_H_
