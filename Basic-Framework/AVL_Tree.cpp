/*
 * @Date: 2024-02-24 17:22:49
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0000-Basic-Framework/AVL_Tree.cpp
 * @Description: AVL 树的实现
 */
#include <iostream>
#include <queue>

struct Node {
    int data;
    int height;
    Node* left;
    Node* right;
    Node() : data(0), height(1), left(nullptr), right(nullptr) {}
    Node(int d) : data(d), height(1), left(nullptr), right(nullptr) {}
};
typedef Node node_t;
typedef Node* nodeptr_t;

class AVLTree {
private:
    // 左旋：右子树的左节点变成根节点，根节点变成左子树的右节点
    nodeptr_t leftRotate(nodeptr_t node) {
        nodeptr_t r = node->right;
        nodeptr_t t = r->left;
        r->left = node;
        node->right = t;
        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
        r->height = std::max(getHeight(r->left), getHeight(r->right)) + 1;
        return r;
    }
    nodeptr_t rightRotate(nodeptr_t n) {
        nodeptr_t l = n->left;
        nodeptr_t t = l->right;
        l->right = n;
        n->left = t;
        n->height = std::max(getHeight(n->left), getHeight(n->right)) + 1;
        l->height = std::max(getHeight(l->left), getHeight(l->right)) + 1;
        return l;
    }
    nodeptr_t makeBalance(nodeptr_t root) {
        int balance = getBalance(root);
        if (balance > 1) {
            // LL
            if (getBalance(root->left) >= 0) {
                return rightRotate(root);
            } else {
                // LR
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        } else if (balance < -1) {
            // RR
            if (getBalance(root->right) <= 0) {
                return leftRotate(root);
            } else {
                // RL
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }
        return root;
    }
    nodeptr_t insert(nodeptr_t root, int data) {
        if (!root) {
            return new node_t(data);
        }
        if (data < root->data) {
            root->left = insert(root->left, data);
        } else if (data > root->data) {
            root->right = insert(root->right, data);
        }
        root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));
        root = makeBalance(root);
        return root;
    }
    nodeptr_t remove(nodeptr_t root, int data) {
        if (!root) return root;
        if (!search(data)) return root;
        if (data < root->data) {
            root->left = remove(root->left, data);
        } else if (data > root->data) {
            root->right = remove(root->right, data);
        } else {
            nodeptr_t r = root->right;
            if (!root->right) {
                nodeptr_t l = root->left;
                delete root;
                root = l;
            } else if (!root->left) {
                delete root;
                root = r;
            } else {
                while (r->left) {
                    r = r->left;
                }
                root->data = r->data;
                root->right = remove(root->right, r->data);
            }
        }
        if (!root) return root;
        root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));
        root = makeBalance(root);
        return root;
    }
public:
    nodeptr_t root;
    AVLTree() : root(nullptr) {}
    AVLTree(nodeptr_t r) : root(r) {}
    ~AVLTree() {
        std::queue<nodeptr_t> q;
        q.push(root);
        while (!q.empty()) {
            nodeptr_t n = q.front();
            q.pop();
            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
            delete n;
        }
    }
    int getHeight(nodeptr_t root) { return root ? root->height : 0; }
    int getBalance(nodeptr_t root) {
        return root ? getHeight(root->left) - getHeight(root->right) : 0;
    }
    void insert(int data) { root = insert(root, data); }
    void remove(int data) { root = remove(root, data); }
    nodeptr_t search(int data) {
        nodeptr_t n = root;
        while (n) {
            if (data < n->data) {
                n = n->left;
            } else if (data > n->data) {
                n = n->right;
            } else {
                return n;
            }
        }
        return nullptr;
    }
    void print() {
        std::queue<nodeptr_t> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 1; i <= size; ++i) {
                nodeptr_t n = q.front();
                q.pop();
                std::cout << n->data << " ";
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    nodeptr_t tmp = new node_t(6);
    AVLTree* avl = new AVLTree(tmp);
    avl->insert(5);
    avl->insert(2);
    avl->insert(7);
    avl->insert(9);
    avl->insert(10);
    avl->insert(1);
    avl->print();
    avl->remove(2);
    std::cout << "After removing 2:" << std::endl;
    avl->print();
    return 0;
}