#include <iostream>

class Queeue {
private:
    int arr[100];
    int frontIndex;
    int backIndex;
    int size;

public:
    Queeue() : frontIndex(0), backIndex(-1), size(0) {}

    void push(int value) {
        if (size == 100) return;
        backIndex = (backIndex + 1) % 100;
        arr[backIndex] = value;
        size++;
    }

    void pop() {
        if (isEmpty()) return;
        frontIndex = (frontIndex + 1) % 100;
        size--;
    }

    int front() const {
        if (isEmpty()) return -1;
        return arr[frontIndex];
    }

    int back() const {
        if (isEmpty()) return -1;
        return arr[backIndex];
    }

    bool isEmpty() const {
        return size == 0;
    }

    void displayQueue() const {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }
        std::cout << "Queue elements: ";
        for (int i = 0; i < size; ++i) {
            std::cout << arr[(frontIndex + i) % 100] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    Queeue q;
    int choice, value;

    while (true) {
        std::cout << "\n1. Push to queue\n2. Display front and back\n3. Display entire queue\n4. Pop from queue\n5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter value to push: ";
            std::cin >> value;
            q.push(value);
            std::cout << "Value pushed into the queue.\n";
            break;
        case 2:
            if (!q.isEmpty()) {
                std::cout << "Front: " << q.front() << ", Back: " << q.back() << "\n";
            }
            else {
                std::cout << "Queue is empty.\n";
            }
            break;
        case 3:
            q.displayQueue();
            break;
        case 4:
            if (!q.isEmpty()) {
                std::cout << "Popping value from queue.\n";
                q.pop();
            }
            else {
                std::cout << "Queue is empty.\n";
            }
            break;
        case 5:
            return 0;
        default:
            std::cout << "Invalid choice, try again.\n";
            break;
        }
    }

    return 0;
}
