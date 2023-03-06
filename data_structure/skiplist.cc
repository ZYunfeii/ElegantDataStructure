#include <string.h>
#include <stdlib.h>
#include <iostream>
class Node {
public:
    int value;
    int height;
    Node** next;

    Node(int value, int height) : value(value), height(height) {
        next = new Node*[height];
        memset(next, 0, height * sizeof(Node*));
    }

    ~Node() {
        delete[] next;
    }
};

class SkipList {
public:
    SkipList() {
        head = new Node(0, max_height);
    }

    ~SkipList() {
        Node* p = head;
        while (p) {
            Node* q = p->next[0];
            delete p;
            p = q;
        }
    }

    void insert(int value) {
        Node* update[max_height];
        Node* p = head;
        for (int i = current_height - 1; i >= 0; i--) {
            while (p->next[i] && p->next[i]->value < value) {
                p = p->next[i];
            }
            update[i] = p;
        }
        p = p->next[0];
        if (p && p->value == value) {
            return;
        }
        int height = random_height();
        if (height > current_height) {
            for (int i = current_height; i < height; i++) {
                update[i] = head;
            }
            current_height = height;
        }
        p = new Node(value, height);
        for (int i = 0; i < height; i++) {
            p->next[i] = update[i]->next[i];
            update[i]->next[i] = p;
        }
    }

    void remove(int value) {
        Node* update[max_height];
        Node* p = head;
        for (int i = current_height - 1; i >= 0; i--) {
            while (p->next[i] && p->next[i]->value < value) {
                p = p->next[i];
            }
            update[i] = p;
        }
        p = p->next[0];
        if (!p || p->value != value) {
            return;
        }
        for (int i = 0; i < current_height; i++) {
            if (update[i]->next[i] == p) {
                update[i]->next[i] = p->next[i];
            }
        }
        delete p;
        while (current_height > 1 && !head->next[current_height - 1]) {
            current_height--;
        }
    }

    bool contains(int value) {
        Node* p = head;
        for (int i = current_height - 1; i >= 0; i--) {
            while (p->next[i] && p->next[i]->value < value) {
                p = p->next[i];
            }
        }
        p = p->next[0];
        return p && p->value == value;
    }
private:
    Node* head;
    int current_height = 1;
    const int max_height = 16;
    int random_height() {
        int height = 1;
        while (height < max_height && rand() % 2 == 0) {
            height++;
        }
        return height;
    }
};

int main() {
    SkipList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.remove(3);
    std::cout << list.contains(3) << std::endl; // 输出 0
    std::cout << list.contains(4) << std::endl; // 输出 1
    return 0;
}