//uzd2.1
#include <iostream>

// Node class definition
class Node {
public:
    int data;
    Node* next;
    
    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

// LinkedList class definition
class LinkedList {
private:
    Node* head;
public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning
    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to display the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Function to reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        head = prev; // Update the head to the new first node
    }
};

int main() {
    // Create a linked list object
    LinkedList myList;

    // Insert your numbers into the linked list
    myList.insert(1);
    myList.insert(230);
    myList.insert(30);
    myList.insert(3560);

    // Display the original linked list
    std::cout << "Original linked list: ";
    myList.display();

    // Reverse the linked list
    myList.reverse();

    // Display the reversed linked list
    std::cout << "Reversed linked list: ";
    myList.display();

    return 0;
}