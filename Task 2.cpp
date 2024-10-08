#include <iostream>

class Queeue {
private:
    int arr[100];
    int frontIndex;
    int backIndex;
    int size;

public:
    Queeue() : frontIndex(0), backIndex(-1), size(0) {}

    void enqueue(int value) {
        if (size == 100) return;
        backIndex = (backIndex + 1) % 100;
        arr[backIndex] = value;
        size++;
    }

    void dequeue() {
        if (isEmpty()) return;
        frontIndex = (frontIndex + 1) % 100;
        size--;
    }

    int front() const {
        if (isEmpty()) return -1;
        return arr[frontIndex];
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
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

    void reverseFirstKElements(int K) {
        if (K > size) {
            std::cout << "Invalid K value.\n";
            return;
        }

        int temp[100];
        for (int i = 0; i < K; ++i) {
            temp[i] = front();
            dequeue();
        }

        for (int i = K - 1; i >= 0; --i) {
            enqueue(temp[i]);
        }

        for (int i = 0; i < size - K; ++i) {
            enqueue(front());
            dequeue();
        }
    }
};

//int main() {
//    Queeue q;
//
//    for (int i = 1; i <= 8; ++i) {
//        q.enqueue(i);
//    }
//
//    std::cout << "Initial queue:\n";
//    q.displayQueue();
//
//    int K;
//    std::cout << "Enter the value of K (1 to 8): ";
//    std::cin >> K;
//
//    q.reverseFirstKElements(K);
//
//    std::cout << "Final queue after reversing the first " << K << " elements:\n";
//    q.displayQueue();
//
//    return 0;
//}
