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
  Node* root;
  void createRearrangements(Node* node) {
        if (node->manyNum.empty()) {
            manyNum.push_back(node->num);
            rearrangements.push_back(manyNum);
            manyNum.pop_back();
        }
        for (Node* otherNums : node->otherNum) {
            manyNum.push_back(node->num);
            generateRearrangements(otherNums);
            manyNum.pop_back();
        }
  }
  void createRearrangementTree(Node* node, std::vector<char> other) {
        if (other.empty()) {
            return;
        }
        for (int i = 0; i < other.size(); i++) {
            Node* root1 = new Node;
            root1->number = other[i];
            node->otherNum.push_back(root1);
            std::vector<char> otherVec;
            for (char u : other) {
                if (u == other[i]) {
                    continue;
                }
                otherVec.push_back(u);
            }
            createRearrangementTree(otherVec, root1);
        }
    }

 public:
  std::vector<std::vector<char>> rearrangements;
  explicit Tree(const std::vector<char>& numbers) {
    std::vector<char> goVec;
    manyNum = numbers;
    root = new Node;
    root->root1 = 0;
    createRearrangements(root);
    createRearrangementTree(root, numbers);
  }
};
#endif  // INCLUDE_TREE_H_
