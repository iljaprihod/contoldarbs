#include <iostream>
#include <stack>

class QueueUsingStacks {
private:
    std::stack<int> inbox; // Stack for enqueue operations
    std::stack<int> outbox; // Stack for dequeue operations

public:
    // Function to enqueue an element into the queue
    void enqueue(int value) {
        inbox.push(value);
    }

    // Function to dequeue an element from the queue
    int dequeue() {
        if (outbox.empty()) {
            // Transfer elements from inbox to outbox
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }
        
        if (outbox.empty()) {
            std::cout << "Queue is empty\n";
            return -1; // Assuming -1 represents an error or empty queue
        }

        int frontValue = outbox.top();
        outbox.pop();
        return frontValue;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (inbox.empty() && outbox.empty());
    }
};

int main() {
    QueueUsingStacks queue;

    // Enqueue some elements into the queue
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    // Dequeue elements and display them
    std::cout << "Dequeuing elements: ";
    while (!queue.isEmpty()) {
        std::cout << queue.dequeue() << " ";
    }
    std::cout << std::endl;

    return 0;
}