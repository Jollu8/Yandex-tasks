


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

int main() {
    Node *root1 = newNode(5);
    Node *root2 = newNode(5);
    root1->left = newNode(3);
    root1->right = newNode(8);
    root1->left->left = newNode(2);
    root1->left->right = newNode(4);
    std::cout << "Root1: ";
    inorder(root1);

    root2->left = newNode(3);
    root2->right = newNode(8);
    root2->left->left = newNode(2);
    root2->left->right = newNode(4);
    std::cout << "\nRoot2: ";
    inorder(root2);
    std::cout << "\nTest 1: -> ";
    std::cout << std::boolalpha << is_identical(root1, root2) << std::endl;

    Node *root3 = newNode(5);
    Node *root4 = newNode(6);
    root3->left = newNode(3);
    root3->right = newNode(8);
    root3->left->left = newNode(2);
    root3->left->right = newNode(4);
    std::cout << "\n\nRoot3: ";
    inorder(root3);

    root4->left = newNode(3);
    root4->right = newNode(8);
    root4->left->left = newNode(2);
    root4->left->right = newNode(4);
    std::cout << "\nRoot4: ";
    inorder(root4);
    std::cout << "\nTest 2: -> ";
    std::cout << std::boolalpha << is_identical(root3, root4) << std::endl;




    return 0;
}