#include <iostream>

class Queue {
private:
    int data[100];
    int frontIndex;
    int rearIndex;
    int size;

public:
    Queue() : frontIndex(0), rearIndex(-1), size(0) {}

    void enqueue(int value) {
        if (size == 100) {
            std::cout << "Queue is full!\n";
            return;
        }
        rearIndex = (rearIndex + 1) % 100;
        data[rearIndex] = value;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty!\n";
            return;
        }
        frontIndex = (frontIndex + 1) % 100;
        size--;
    }

    int front() const {
        if (isEmpty()) {
            std::cerr << "Queue is empty!\n";
            return -1;
        }
        return data[frontIndex];
    }

    bool isEmpty() const {
        return size == 0;
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty!\n";
            return;
        }
        std::cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            std::cout << data[(frontIndex + i) % 100] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Initial queue:\n";
    queue.display();

    std::cout << "Front element: " << queue.front() << "\n";

    queue.dequeue();
    std::cout << "\nQueue after dequeue:\n";
    queue.display();
}
