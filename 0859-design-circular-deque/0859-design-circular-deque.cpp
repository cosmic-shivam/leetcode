class MyCircularDeque {
private:
    int *deque;  // Array to hold the elements of the deque
    int front;   // Points to the front element
    int rear;    // Points to the rear element
    int size;    // Maximum size of the deque
    int count;   // Current number of elements in the deque

public:
    // Initializes the deque with a maximum size of k
    MyCircularDeque(int k) {
        size = k;
        deque = new int[size];
        front = 0;
        rear = 0;
        count = 0;
    }

    // Adds an item at the front of the deque
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        front = (front - 1 + size) % size;  // Move front pointer backwards in a circular manner
        deque[front] = value;
        count++;
        return true;
    }

    // Adds an item at the rear of the deque
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        deque[rear] = value;
        rear = (rear + 1) % size;  // Move rear pointer forward in a circular manner
        count++;
        return true;
    }

    // Deletes an item from the front of the deque
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % size;  // Move front pointer forward in a circular manner
        count--;
        return true;
    }

    // Deletes an item from the rear of the deque
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        rear = (rear - 1 + size) % size;  // Move rear pointer backwards in a circular manner
        count--;
        return true;
    }

    // Returns the front item from the deque
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return deque[front];
    }

    // Returns the last item from the deque
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return deque[(rear - 1 + size) % size];  // Get the element before rear pointer
    }

    // Checks if the deque is empty
    bool isEmpty() {
        return count == 0;
    }

    // Checks if the deque is full
    bool isFull() {
        return count == size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */