
#include <algorithm>
#include <iostream>
#include <cassert>
#include <algorithm>


struct Tree {
    int value;
    Tree *left;
    Tree *right;

    explicit Tree(int val) : value(val), left(nullptr), right(nullptr) {}
};

Tree *New_node(int item) {
    Tree *temp = new Tree(item);
    return temp;
}

void Inorder(Tree *root) {
    if (root != nullptr) {
        Inorder(root->left);
        std::cout << root->value << std::endl;
        Inorder(root->right);
    }
}

Tree *Insert(Tree *tree, int key) {
    if (tree == nullptr) return New_node(key);
    if (key < tree->value) tree->left = Insert(tree->left, key);
    else tree->right = Insert(tree->right, key);
    return tree;
}

Tree *Delete_key(Tree *root, int key) {
    if (root == nullptr) return root;

    if (root->value > key) {
        root->left = Delete_key(root->left, key);
        return root;
    } else if (root->value < key) {
        root->right = Delete_key(root->right, key);
        return root;

    }

    if (root->left == nullptr) {
        Tree *temp = root->right;
        delete root;
        return temp;
    } else if (root->right == nullptr) {
        Tree *temp = root->right;
        delete root;
        return temp;
    } else {
        Tree *succParent = root;
        Tree *succ = root->right;
        while (succ->left != nullptr) {
            succParent = succ;
            succ = succ->left;
        }

        if (succParent != nullptr) succParent->left = succ->right;
        else succParent->right = succ->right;

        root->value = succ->value;

        delete succ;
        return root;


    }
}

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


    Tree* root = NULL;
    root = Insert(root, 50);
    root = Insert(root, 30);
    root = Insert(root, 20);
    root = Insert(root, 40);
    root = Insert(root, 70);
    root = Insert(root, 60);
    std::cout << "Start\n";
    Inorder(root);
    root = Delete_key(root, 50);
    std::cout << "Deleted key 50\n";
    Inorder(root);
    root = Delete_key(root, 70);
    std::cout << "Deleted key 70\n";
    Inorder(root);
    root = Delete_key(root, 100);
    std::cout << "Try to delete key 100\n";
    Inorder(root);
    return 0;



}