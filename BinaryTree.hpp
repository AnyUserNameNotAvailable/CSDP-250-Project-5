#include <iostream>

#ifndef BinaryTree_hpp
#define BinaryTree_hpp


class BinaryTree {
private:
    struct Node {
        int data;
        Node* parent;
        Node* leftChild;  // Updated naming for consistency
        Node* rightChild;
    };

    Node* root;
    bool isAvlTree;
    void insertNode(Node* &currentNode, int value);  // Updated name for consistency
    void clear(Node* currentNode);
    void inOrder(Node* currentNode)const;
    void postOrder(Node* currentNode) const;
    void deleteNode(Node* &currentNode, int value);

    //AVL Tree Functions
    bool isAvl(Node* currentNode);
    int getBalanceFactor(Node* node);
    int getHeight(Node* node);


public:
    BinaryTree() {
        root = nullptr;
        isAvlTree = false;
    }
    
    ~BinaryTree() {
        clearTree();
    }

    void addNode(int value) {
        insertNode(root, value);
    }
    void removeNode(int value){
        deleteNode(root, value);
    }

    void clearTree() {
        clear(root);
    }
    bool checkAvl(){
        isAvlTree = isAvl(root);
        return isAvlTree;
    }
    
    void inOrderTraversal();
    void postOrderTraversal();
};

#endif /* BinaryTree_hpp */