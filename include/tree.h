// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

struct Node {
  char num;
  std::vector<Node*> otherNum;
};
class Tree {
 private:
  std::vector<char> manyNum;
  Node* root==nullptr;
  void createRearrangements(Node* node) {
        if (node->otherNum.empty()) {
            manyNum.push_back(node->num);
            rearrangements.push_back(manyNum);
            manyNum.pop_back();
        }
        for (Node* otherNums : node->otherNum) {
            manyNum.push_back(node->num);
            createRearrangements(otherNums);
            manyNum.pop_back();
        }
  }
  void createRearrangementTree(Node* node, std::vector<char> other) {
        if (other.empty()) {
            return;
        }
        for (auto ot : other) {
            Node* root1 = new Node;
            root1->num = ot;
            node->children.push_back(root1);
            std::vector<char> notall = other;
            remaining.erase(
                std::remove(notall.begin(), notall.end(), ot),
                notall.end());
            createRearrangementTree(notall, root1);
        }
    }

 public:
  std::vector<std::vector<char>> rearrangements;
  explicit Tree(const std::vector<char>& numbers) {
    std::vector<char> goVec;
    manyNum = numbers;
    root = new Node;
    root->num = 0;
    createRearrangements(root);
    createRearrangementTree(root, numbers);
  }
};
#endif  // INCLUDE_TREE_H_
