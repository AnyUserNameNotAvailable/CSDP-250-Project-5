#include "BinaryTree.hpp"
#include <iostream>

void BinaryTree::inOrderTraversal() {
    inOrder(root);
}

void BinaryTree::postOrderTraversal() {
    postOrder(root);
}

void BinaryTree::inOrder(Node* currentNode) const{
    if (currentNode == nullptr) {
        return;
    } else {
        inOrder(currentNode->leftChild);
        std::cout << currentNode->data << " ";
        inOrder(currentNode->rightChild);
    }
}

void BinaryTree::postOrder(Node* currentNode) const{
    if (currentNode == nullptr) {
        return;
    } else {
        postOrder(currentNode->leftChild);
        postOrder(currentNode->rightChild);
        std::cout << currentNode->data << " ";
    }
}

void BinaryTree::clear(Node* currentNode) {
    if (currentNode == nullptr) {
        return;
    }

    clear(currentNode->leftChild);
    clear(currentNode->rightChild);

    if (currentNode->parent != nullptr) {
        if (currentNode->parent->leftChild == currentNode) {
            currentNode->parent->leftChild = nullptr;
        } else if (currentNode->parent->rightChild == currentNode) {
            currentNode->parent->rightChild = nullptr;
        }
    }

    delete currentNode;
    
    if (currentNode == root) {
        root = nullptr;
    }
}

void BinaryTree::insertNode(Node* &currentNode, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->parent = nullptr;
    newNode->leftChild = nullptr;
    newNode->rightChild = nullptr;
    if (currentNode == nullptr) {
        currentNode = newNode;

    } else if (value < currentNode->data) {
        insertNode(currentNode->leftChild, value);
    } else {
        insertNode(currentNode->rightChild, value);
    }
}

void BinaryTree::deleteNode(Node* &currentNode, int value) {
    if (currentNode == nullptr) {
        std::cerr << "Value not found" << std::endl;
        return;
    }
    if (value < currentNode -> data) {
        deleteNode(currentNode -> leftChild, value);
    } else if (value > currentNode -> data) {
        deleteNode(currentNode -> rightChild, value);
    } else/*if found*/{
        if (currentNode -> leftChild == currentNode -> rightChild)/*node is a left*/{
            delete currentNode;
            currentNode = nullptr;
        } else if (currentNode -> rightChild == nullptr)/*only left child*/{
            Node *temp = currentNode;
            currentNode = currentNode -> leftChild;
            currentNode -> parent = temp -> parent;
            delete temp;
        } else if (currentNode -> leftChild == nullptr) /*only right child*/ {
            Node *temp = currentNode;
            currentNode = currentNode -> rightChild;
            currentNode -> parent = temp -> parent;
            delete temp;
        }else{
            Node* replacement = currentNode -> rightChild;
            while (replacement -> leftChild != nullptr){
                replacement = replacement -> leftChild;
            }
            currentNode -> data = replacement -> data;
            deleteNode(currentNode->rightChild,replacement -> data);

        }

    }


}
//items needed to check if avl tree

    //getBalance: function that checks if every node left and right subtrees at most differ by one

    int BinaryTree::getBalanceFactor(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return getHeight(node->leftChild) - getHeight(node->rightChild);
    }
    //getHeight: function for height
    int BinaryTree::getHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + ((getHeight(node->leftChild) > getHeight(node->rightChild)) ? getHeight(node->leftChild) : getHeight(node->rightChild));
    }
    //check if avl
    bool BinaryTree::isAvl(Node* currentNode) {
        if (currentNode == nullptr) {
            return true;
        }

        // Check the balance of the current node
        int balanceFactor = getBalanceFactor(currentNode);
        if (balanceFactor > 1 || balanceFactor < -1) {
            return false;
        }

        // Recursively check left and right subtrees
        return isAvl(currentNode->leftChild) && isAvl(currentNode->rightChild);
    }
