// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
 private:
    struct Node {
        std::vector<Node*> otherNum;
        char num;
    };
    std::vector<std::vector<char>> rearrangements;
    Node* root;
    std::vector<char> manyNum;
    void createRearrangementTree( Node* node1, std::vector<char> other) {
        if (other.empty()) {
            return;
        }
        int j = 0;
        for (int i = 0; i < other.size(); i++) {
            Node* root1 = new Node;
            root1->num = other[i];
            node1->otherNum.push_back(root1);
            std::vector<char> notall;
            for (char k : other) {
                if (k == other[i]) {
                    continue;
                }
                notall.push_back(k);
            }
            createRearrangementTree(root1, notall);
        }
    }
    void createRearrangements(Node* node2, std::vector<char> nowVal) {
        if (node2->num) {
            nowVal.push_back(node2->num);
        }
        if (node2->otherNum.empty()) {
            rearrangements.push_back(nowVal);
            return;
        }
        for (int i = 0; i < node2->otherNum.size(); i++) {
            createRearrangements(node2->otherNum[i], nowVal);
        }
    }

 public:
  explicit Tree(const std::vector<char> other) {
    manyNum = other;
    std::vector<char> goVec;
    root = new Node;
    root->num = 0;
    createRearrangements(root, goVec);
    createRearrangementTree( root, manyNum);
  }
  std::vector<char> getOrdPerm(int n)const {
        if (n - 1 > rearrangements.size()) {
            return std::vector<char>();
        }
        return rearrangements[n - 1];
  }
};
#endif  // INCLUDE_TREE_H_
