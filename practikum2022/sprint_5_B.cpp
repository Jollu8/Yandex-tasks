
#include <algorithm>
#include <iostream>
#include <cassert>


struct Tree {
    int value;
    Tree *left;
    Tree *right;

    explicit Tree(int val) : value(val), left(nullptr), right(nullptr) {}
};

int height(Tree *tree) {
    if (tree == nullptr) return 0;
    return 1 + std::max(height(tree->left), height(tree->right));
}

bool Solution(const Tree *root) {

    if (root == nullptr) return true;

    int lh = height(root->left);
    int rh = height(root->right);
    if (std::abs(lh - rh) <= 1 && Solution(root->left) && Solution(root->right)) return true;

    return false;

}

int main() {
    Tree *tree1 = new Tree(0);
    tree1->right = new Tree(0);
    tree1->left = new Tree(2);
    assert(Solution(tree1) == true);


    Tree *tree2 = new Tree(1);
    tree2->left = new Tree(2);
    tree2->right = new Tree(0);
    tree2->left->right = new Tree(3);
    tree2->left->left = new Tree(6);
    assert(Solution(tree2) == true);

    Tree *tree3 = new Tree(0);
    tree3->left = new Tree(2);
    tree3->right = new Tree(7);
    tree3->right->right = new Tree(8);
    tree3->right->left = new Tree(4);
    tree3->right->left->left = new Tree(12);
    assert(Solution(tree3) == false);
    std::cout << "Done\n";


}