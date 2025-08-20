#include <iostream>
using namespace std;

template <class T>
class Stack {
    int top;
    int capacity;
    T* arr;

public:
    Stack(int size) {
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == capacity - 1);
    }

    void push(T data) {
        if (isFull()) {
            cout << "Stack is Full. Cannot push " << data << endl;
            return;
        }
        arr[++top] = data;
        cout << data << " pushed into stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty. Nothing to pop." << endl;
            return;
        }
        cout << arr[top--] << " popped from stack." << endl;
    }

    T peek() {
        if (isEmpty()) {
            cout << "Stack is Empty. No top element." << endl;
            return -1;
        }
        return arr[top];
    }
};

int main() {
    Stack<int> s(5);

    s.push(11);
    s.push(12);
    s.push(13);

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    cout << "Top element after pop: " << s.peek() << endl;

    s.pop();
    s.pop();
    s.pop();

    return 0;
}