#ifndef BST_H
#define BST_H
#include <functional>
#include <ostream>

class BST
{
public:
    class Node
    {
        public:
            Node(int value, Node* left, Node* right);
            Node();
            Node(const Node& node);
            explicit Node(int value);
            int value = 0;
            Node* left = nullptr;
            Node* right = nullptr;
            Node* parent = nullptr;

            friend std::ostream& operator<<(std::ostream& os, const BST::Node& node) {
                os << node.value;
                return os;
            }

            friend bool operator==(const BST::Node& lhs, const BST::Node& rhs) {
                return lhs.value == rhs.value;
            }
            friend bool operator==(const BST::Node& lhs, int rhs) {
                return lhs.value == rhs;
            }
            friend bool operator==(int lhs, const BST::Node& rhs) {
                return lhs == rhs.value;
            }
            friend bool operator!=(const BST::Node& lhs, const BST::Node& rhs) {
                return lhs.value != rhs.value;
            }
            friend bool operator!=(const BST::Node& lhs, int rhs) {
                return lhs.value != rhs;
            }
            friend bool operator!=(int lhs, const BST::Node& rhs) {
                return lhs != rhs.value;
            }
            friend bool operator<(const BST::Node& lhs, const BST::Node& rhs) {
                return lhs.value < rhs.value;
            }
            friend bool operator<(const BST::Node& lhs, int rhs) {
                return lhs.value < rhs;
            }
            friend bool operator<(int lhs, const BST::Node& rhs) {
                return lhs < rhs.value;
            }
            friend bool operator>(const BST::Node& lhs, const BST::Node& rhs) {
                return lhs.value > rhs.value;
            }
            friend bool operator>(const BST::Node& lhs, int rhs) {
                return lhs.value > rhs;
            }
            friend bool operator>(int lhs, const BST::Node& rhs) {
                return lhs > rhs.value;
            }
            friend bool operator<=(const BST::Node& lhs, const BST::Node& rhs) {
                return lhs.value <= rhs.value;
            }
            friend bool operator<=(const BST::Node& lhs, int rhs) {
                return lhs.value <= rhs;
            }
            friend bool operator<=(int lhs, const BST::Node& rhs) {
                return lhs <= rhs.value;
            }
            friend bool operator>=(const BST::Node& lhs, const BST::Node& rhs) {
                return lhs.value >= rhs.value;
            }
            friend bool operator>=(const BST::Node& lhs, int rhs) {
                return lhs.value >= rhs;
            }
            friend bool operator>=(int lhs, const BST::Node& rhs) {
                return lhs >= rhs.value;
            }
    };

    Node*& get_root();
    void bfs(const std::function<void(Node*& node)>& func) const;
    size_t length();
    bool add_node(int value);
    Node** find_node(int value);
    Node** find_parrent(int value);
    Node** find_successor(int value);
    bool delete_node(int value);

private:
    Node* root = nullptr;
    friend std::ostream& operator<<(std::ostream& os, const BST& bst) {
        bst.bfs([&os](Node*& node) {
            os << node << " ";
        });
        return os;
    }
};

#endif //BST_H