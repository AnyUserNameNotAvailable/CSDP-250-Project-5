#include "BinaryTree.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {

    const int arraySize = 35;
    int randomNumbers[arraySize];
    std::srand(std::time(0)); 
    BinaryTree B;

    std::cout << "Generating Array of Random Numbers: ";
    for (int i = 0; i < arraySize; i++) {
        randomNumbers[i] = std::rand() % 100;  // Generates random numbers less than 100
        std::cout << randomNumbers[i] << " ";
    }
    std::cout << "\n";
    

    for (int i = 0; i < arraySize; ++i) {
        B.addNode(randomNumbers[i]);
    }

    //  Display the binary search tree with inorder traversal
    std::cout << "Inorder Traversal: ";
    B.inOrderTraversal();
    std::cout << "\n";

    std::cout << "Now you may delete a node from the tree" << std::endl;
    std::cout << "Would you like to continue y or n: ";
    char choice;
    std::cin >> choice;

    switch (choice){
        case 'y':
            int value;
            std::cout << "Which value will you delete: ";
            std::cin >> value;
            B.removeNode(value);

            //display in postOrder
            B.postOrderTraversal();
            std::cout <<"\n";
            if(B.checkAvl()){
                std::cout << "Tree is Avl Tree" << std::endl;
            } else{
                std::cout << "Tree is not Avl Tree" << std::endl;
            }

            break;
        
        case 'n':
            std::cout << "Ending program...";
            exit(0);
            break;
        default:
            std::cout << "Invalid Input" << std::endl;
            break;
    }
    std::cout << "Program End Successfully";
    return 0;
}