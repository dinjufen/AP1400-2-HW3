#include "bst.h"
#include <queue>
#include <iostream>
BST::Node::Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}

BST::Node::Node() {}

BST::Node::Node(const Node& node) : value(node.value), left(node.left), right(node.right), parent(parent) {}

BST::Node::Node(int value) : value(value) {}

BST::Node*& BST::get_root() {
    return root;
}


void BST::bfs(const std::function<void(Node*& node)>& func) const {
    std::queue<Node*> queue;
    queue.push(root);
    while (!queue.empty()) {
        auto& front = queue.front();
        func(front);
        if (front->left) {
            queue.push(front->left);
        }
        if (front->right) {
            queue.push(front->right);
        }
        queue.pop();
    }
}

size_t BST::length() {
    size_t length = 0;
    bfs([&length](Node *&node) {
        length++;
    });
    return length;
}

bool BST::add_node(int value) {
    if (!root) {
        root = new Node(value);
        return true;
    }
    Node* cur = root, *pre = nullptr;
    while (cur) {
        if (cur->value == value) {
            return false;
        }
        pre = cur;
        if (cur->value > value) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    if (!pre) {
        return false;
    }
    cur = new Node(value);
    if (pre->value > value) {
        pre->left = cur;
    } else {
        pre->right = cur;
    }
    cur->parent = pre;
    return true;
}

BST::Node** BST::find_node(int value) {
    if (!root) return nullptr;
    Node* node = root;
    while (node) {
        if (node->value == value) {
            break;
        }
        if (node->value > value) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    if (node) {
        return &node;
    }
    return nullptr;
}

BST::Node** BST::find_parrent(int value) {
    auto node = find_node(value);
    if (node && *node) {
        return &((*node)->parent);
    }
    return nullptr;
}

BST::Node** BST::find_successor(int value) {
    auto node = root;
    Node** res = nullptr;
    while (node) {
        if (node->value > value) {
            res = &node;
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    return res;
}

bool BST::delete_node(int value) {

    return true;
}