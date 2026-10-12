#include <iostream>
using namespace std;

//Array Stack
class ArrayStack {
    int a[100], n = 0;
public:
    bool empty() { return n == 0; }

    void push(int x) {
        if (n < 100) a[n++] = x;
    }

    void pop() {
        if (empty()) cout << "Stack empty\n";
        else cout << a[--n] << endl;
    }
};

//Linked Stack
class LinkedStack {
    struct Node {
        int data;
        Node* next;
        Node(int x, Node* p) : data(x), next(p) {}
    };
    Node* top = nullptr;
public:
    bool empty() { return top == nullptr; }

    void push(int x) {
        top = new Node(x, top);
    }

    void pop() {
        if (empty()) {
            cout << "Stack empty\n";
            return;
        }
        Node* temp = top;
        cout << temp->data << endl;
        top = top->next;
        delete temp;
    }

    ~LinkedStack() {
        while (!empty()) pop();
    }
};

//Array Queue
class ArrayQueue {
    int a[100], front = 0, n = 0;
public:
    bool empty() { return n == 0; }

    void enqueue(int x) {
        if (n < 100) {
            a[(front + n) % 100] = x;
            n++;
        }
    }

    void dequeue() {
        if (empty()) cout << "Queue empty\n";
        else {
            cout << a[front] << endl;
            front = (front + 1) % 100;
            n--;
        }
    }
};

//Linked Queue
class LinkedQueue {
    struct Node {
        int data;
        Node* next;
        Node(int x) : data(x), next(nullptr) {}
    };
    Node* front = nullptr, * back = nullptr;
public:
    bool empty() { return front == nullptr; }

    void enqueue(int x) {
        Node* p = new Node(x);
        if (empty()) front = back = p;
        else {
            back->next = p;
            back = p;
        }
    }

    void dequeue() {
        if (empty()) {
            cout << "Queue empty\n";
            return;
        }
        Node* temp = front;
        cout << temp->data << endl;
        front = front->next;
        if (!front) back = nullptr;
        delete temp;
    }

    ~LinkedQueue() {
        while (!empty()) dequeue();
    }
};

//Array Deque
class ArrayDeque {
    int a[100], front = 0, n = 0;
public:
    bool empty() { return n == 0; }

    void addFront(int x) {
        if (n < 100) {
            front = (front - 1 + 100) % 100;
            a[front] = x;
            n++;
        }
    }

    void addBack(int x) {
        if (n < 100) {
            a[(front + n) % 100] = x;
            n++;
        }
    }

    void removeFront() {
        if (empty()) cout << "Deque empty\n";
        else {
            cout << a[front] << endl;
            front = (front + 1) % 100;
            n--;
        }
    }

    void removeBack() {
        if (empty()) cout << "Deque empty\n";
        else {
            cout << a[(front + n - 1) % 100] << endl;
            n--;
        }
    }
};

//Linked Deque
class LinkedDeque {
    struct Node {
        int data;
        Node* prev, * next;
        Node(int x) : data(x), prev(nullptr), next(nullptr) {}
    };
    Node* front = nullptr, * back = nullptr;
public:
    bool empty() { return front == nullptr; }

    void addFront(int x) {
        Node* p = new Node(x);
        p->next = front;
        if (front) front->prev = p;
        else back = p;
        front = p;
    }

    void addBack(int x) {
        Node* p = new Node(x);
        p->prev = back;
        if (back) back->next = p;
        else front = p;
        back = p;
    }

    void removeFront() {
        if (empty()) {
            cout << "Deque empty\n";
            return;
        }
        Node* temp = front;
        cout << temp->data << endl;
        front = front->next;
        if (front) front->prev = nullptr;
        else back = nullptr;
        delete temp;
    }

    void removeBack() {
        if (empty()) {
            cout << "Deque empty\n";
            return;
        }
        Node* temp = back;
        cout << temp->data << endl;
        back = back->prev;
        if (back) back->next = nullptr;
        else front = nullptr;
        delete temp;
    }

    ~LinkedDeque() {
        while (!empty()) removeFront();
    }
};

int main() {
    ArrayStack s1;
    s1.pop();
    s1.push(1); s1.push(2); s1.pop(); s1.push(3);
    s1.push(4); s1.pop(); s1.push(5); s1.pop();
    s1.push(6); s1.pop(); s1.pop(); s1.pop();

    LinkedStack s2;
    s2.pop();
    s2.push(1); s2.push(2); s2.pop(); s2.push(3);
    s2.push(4); s2.pop(); s2.push(5); s2.pop();
    s2.push(6); s2.pop(); s2.pop(); s2.pop();

    ArrayQueue q1;
    q1.dequeue();
    q1.enqueue(1); q1.enqueue(2); q1.dequeue(); q1.enqueue(3);
    q1.enqueue(4); q1.dequeue(); q1.enqueue(5); q1.dequeue();
    q1.enqueue(6); q1.dequeue(); q1.dequeue(); q1.dequeue();

    LinkedQueue q2;
    q2.dequeue();
    q2.enqueue(1); q2.enqueue(2); q2.dequeue(); q2.enqueue(3);
    q2.enqueue(4); q2.dequeue(); q2.enqueue(5); q2.dequeue();
    q2.enqueue(6); q2.dequeue(); q2.dequeue(); q2.dequeue();

    ArrayDeque d1;
    d1.removeFront(); d1.addFront(1); d1.addBack(2);
    d1.removeFront(); d1.addFront(3); d1.addBack(4);
    d1.removeBack(); d1.addFront(5); d1.removeFront();
    d1.addBack(6); d1.removeBack(); d1.removeFront();

    LinkedDeque d2;
    d2.removeFront(); d2.addFront(1); d2.addBack(2);
    d2.removeFront(); d2.addFront(3); d2.addBack(4);
    d2.removeBack(); d2.addFront(5); d2.removeFront();
    d2.addBack(6); d2.removeBack(); d2.removeFront();

    return 0;
}
