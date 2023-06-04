// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
 private:
    struct Node {
        char num;
        std::vector<Tree*> otherNum;
    };
    Node* nodeOp;
    explicit Tree(char numSet) {
        nodeOp = new Node;
        nodeOp->num = numSet;
    }
    void create(const std::vector<char>& other) {
        for (int i = 0; i < other.size(); i++) {
            std::vector<char> other_t = other;
            nodeOp->otherNum.push_back(new Tree(other_t[i]));
            other_t.erase(other_t.begin() + i);
            nodeOp->otherNum[i]->create(other_t);
        }
    }

 public:
    explicit Tree(const std::vector<char>& other) {
        nodeOp = new Node;
        nodeOp->num = '*';
        create(other);
    }
    char get_NumSet() const {
        return nodeOp->num;
    }
    Tree& operator[](int n) const {
        return *nodeOp->otherNum[n];
    }
    int get_Size() const {
        return nodeOp->otherNum.size();
    }
};

#endif  // INCLUDE_TREE_H_
