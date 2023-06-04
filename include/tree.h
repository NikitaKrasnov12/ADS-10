// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

struct Node {
        char num;
        std::vector<Tree*> otherNum;
    };
class Tree {
private:
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
#endif  // INCLUDE_TREE_H_
