


#include <iostream>
#include <queue>
#include <unordered_map>


struct Node {
    int data;
    Node *left, *right;
};

bool Are_anagrams(Node *root1, Node *root2) {
    if (root1 == nullptr && root2 == nullptr) return true;
    if (root1 == nullptr || root2 == nullptr) return false;

    std::queue<Node *> q1, q2;
    q1.push(root1);
    q2.push(root2);

    std::unordered_map<int, int> m;
    while (!q1.empty() && !q2.empty()) {
        int n1 = q1.size(), n2 = q2.size();

        if (n1 != n2) return false;
        if (n1 == 0) break;
        while (--n1) {
            Node *node1 = q1.front();
            q1.pop();
            ++m[node1->data];
            if (node1->left != nullptr) q1.push(node1->left);
            if (node1->right != nullptr) q1.push(node1->right);

        }
        while (--n2) {
            Node *node2 = q2.front();
            q2.pop();
            if (m.find(node2->data) == m.end()) return false;
            --m[node2->data];

            if (m[node2->data == 0]) m.erase(node2->data);

            if (node2->left != nullptr) q2.push(node2->left);
            if (node2->right != nullptr) q2.push(node2->right);
        }
        if (m.size() > 0) return false;

    }
    if (q1.empty() && q2.empty()) return true;
    return false;


}

Node *newNode(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;

}

void inorder(Node *root) {
    if (root == nullptr) return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

bool is_identical(Node *root1, Node *root2) {
    if (root1 == nullptr && root2 == nullptr) return 1;
    else if (root1 == nullptr || root2 == nullptr) return false;
    else {
        if (root1->data == root2->data && is_identical(root1->left, root2->left)
            && is_identical(root1->right, root2->right))
            return true;
        else return false;

    }
}


bool is_small(Node *root, int data) {
    if(root->data >= data) return false;
    if (root->left !=  nullptr)
        return is_small(root->left, data);
    if(root->right != nullptr)
        return is_small(root->right, data);
    return true;
}

int main() {
    Node *root1 = newNode(5);
    root1->right = newNode(8);
    root1->left = newNode(3);
    root1->left->left = newNode(1);
    root1->left->right = newNode(4);
    std::cout << "Test 1: > " << is_small(root1->left, root1->data) << std::endl;


    Node *root2 = newNode(5);
    root2->right = newNode(8);
    root2->left = newNode(3);
    root2->left->left = newNode(1);
    root2->left->right = newNode(5);
    std::cout << "Test 2: > " << std::boolalpha << is_small(root2->left, root1->data);





    return 0;
}