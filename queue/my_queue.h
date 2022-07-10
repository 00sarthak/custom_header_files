#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include<vector>
#include<iostream>
using namespace std;

class my_queue {
    public:

    int front;
    int rear;
    vector<int> s;

    my_queue();
    void enqueue(int value);
    int dequeue();
    int front_element();
    int rear_element();
    int size();
    bool isEmpty();
    void print();
};

my_queue::my_queue() {
    s = vector<int>() ;
    front = 0;
    rear = -1;
}

void my_queue:: enqueue(int value) {
    s.push_back(value);
    rear++;
}

int my_queue:: dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    int value = s[front];
    //s.erase(s.begin());
    front++;
    return value;
}

int my_queue:: front_element() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return s[front];
}

int my_queue:: rear_element() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return s[rear];
}

int my_queue:: size() {
    return rear - front + 1;
}

bool my_queue:: isEmpty() {
    return size()==0;
}

void my_queue:: print(){
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    for (int i = front; i <= rear; i++) {
        cout << s[i] << " ";
    }
    cout << endl;
}



#endif