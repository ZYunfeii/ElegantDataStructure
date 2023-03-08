#include <iostream>
#include <queue>

template<typename T>
class Heap {
public:
    Heap() : root(nullptr), size_(0) {}

    void push(const T& value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
        } else {
            std::queue<Node*> q;
            q.push(root);
            while (!q.empty()) {
                Node* cur = q.front();
                q.pop();
                if (cur->left == nullptr) {
                    cur->left = newNode;
                    break;
                } else if (cur->right == nullptr) {
                    cur->right = newNode;
                    break;
                } else {
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
            heapifyUp(newNode);
        }
        size_++;
    }

    void pop() {
        if (root == nullptr) {
            return;
        }
        Node* lastNode = findLastNode();
        if (lastNode == root) {
            delete lastNode;
            root = nullptr;
        } else {
            std::swap(lastNode->value, root->value);
            if (lastNode->parent->left == lastNode) {
                lastNode->parent->left = nullptr;
            } else {
                lastNode->parent->right = nullptr;
            }
            delete lastNode;
            heapifyDown(root);
        }
        size_--;
    }

    const T& top() const {
        if (root == nullptr) {
            throw std::out_of_range("Heap is empty");
        }
        return root->value;
    }

    bool empty() const {
        return size_ == 0;
    }

    int size() const {
        return size_;
    }

private:
    struct Node {
        T value;
        Node* parent;
        Node* left;
        Node* right;

        Node(const T& value) : value(value), parent(nullptr), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int size_;

    void heapifyUp(Node* node) {
        while (node->parent != nullptr && node->value > node->parent->value) {
            std::swap(node->value, node->parent->value);
            node = node->parent;
        }
    }

    void heapifyDown(Node* node) {
        while (node != nullptr) {
            Node* maxNode = node;
            if (node->left != nullptr && node->left->value > maxNode->value) {
                maxNode = node->left;
            }
            if (node->right != nullptr && node->right->value > maxNode->value) {
                maxNode = node->right;
            }
            if (maxNode == node) {
                break;
            }
            std::swap(node->value, maxNode->value);
            node = maxNode;
        }
    }

    Node* findLastNode() {
        std::queue<Node*> q;
        q.push(root);
        Node* lastNode = nullptr;
        while (!q.empty()) {
            lastNode = q.front();
            q.pop();
            if (lastNode->left != nullptr) {
                q.push(lastNode->left);
            }
            if (lastNode->right != nullptr) {
                q.push(lastNode->right);
            }
        }
        return lastNode;
    }
};
