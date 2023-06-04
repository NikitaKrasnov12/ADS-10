// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>

class Tree {
 private:
    struct Node {
        std::vector<Node*> otherNum;
        char num;
    };
    std::vector<std::vector<char>> rearrangements;
    Node* root;
    std::vector<char> manyNum;
    void createRearrangements(Node* node1, std::vector<char> nowVal) {
        if (node1->num) {
            nowVal.push_back(node1->num);
        }
        if (node1->otherNum.empty()) {
            rearrangements.push_back(nowVal);
            return;
        }
        for (int i = 0; i < node1->otherNum.size(); i++) {
            createRearrangements(node1->otherNum[i], nowVal);
        }
    }
    void createRearrangementTree(std::vector<char> other, Node* node1) {
        if (other.empty()) {
            return;
        }
        int j = 0;
        for (int i = 0; i < other.size(); i++) {
            Node* root1 = new Node;
            root1->num = other[i];
            node1->otherNum.push_back(root1);
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

 public:
  explicit Tree(const std::vector<char> other) {
    manyNum = other;
    std::vector<char> goVec;
    root = new Node;
    root->num = 0;
    createRearrangements(root, goVec);
    createRearrangementTree(manyNum, root);
  }
  std::vector<char> getOrdPerm(int n)const {
        if (n - 1 > rearrangements.size()) {
            return std::vector<char>();
        }
        return rearrangements[n - 1];
  }
};
#endif  // INCLUDE_TREE_H_
