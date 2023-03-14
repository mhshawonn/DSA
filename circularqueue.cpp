#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularQueue {
private:
    Node* front;
    Node* rear;
    int size;
public:
    CircularQueue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
            rear->next = front;
        }
        else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
        }
        else if (front == rear) {
            delete front;
            front = nullptr;
            rear = nullptr;
            size--;
        }
        else {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
            size--;
        }
    }

    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    int getRear() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        return rear->data;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.dequeue();
    std::cout << "Front element: " << cq.getFront() << std::endl;
    std::cout << "Rear element: " << cq.getRear() << std::endl;
    std::cout << "Size of queue: " << cq.getSize() << std::endl;
    return 0;
}
