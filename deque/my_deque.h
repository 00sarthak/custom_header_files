#ifndef MY_DEQUE_H
#define MY_DEQUE_H

#include <iostream>

using namespace std;

class my_deque {

    int front;
    int size;
    int cap;
    int *arr;

public:

    my_deque(int size);
    void push_back(int value);
    void push_front(int value);
    void pop_back();
    void pop_front();
    int peek_back();
    int peek_front();
    bool is_empty();
    bool is_full();
    void print();

};

my_deque:: my_deque(int cap) {
    this->cap = cap;
    size=0;
    arr= new int[cap];
    front = 0;
}

bool my_deque:: is_empty() {
    return size==0;
}

bool my_deque:: is_full() {
    return size==cap;
}

void my_deque:: push_back(int value) {
    if(is_full()) {
        cout<<"Deque is full"<<endl;
        return;
    }

    int index = (front+size)%cap;
    arr[index] = value;
    size++;
}

void my_deque:: push_front(int value) {
    if(is_full()) {
        cout<<"Deque is full"<<endl;
        return;
    }

    front = (front-1+cap)%cap;
    arr[front] = value;
    size++;
}

void my_deque:: pop_back() {
    if(is_empty()) {
        cout<<"Deque is empty"<<endl;
        return;
    }
    size--;
}

void my_deque:: pop_front() {
    if(is_empty()) {
        cout<<"Deque is empty"<<endl;
        return;
    }
    front = (front+1)%cap;
    size--;
}

int my_deque:: peek_back() {
    if(is_empty()) {
        cout<<"Deque is empty"<<endl;
        return -1;
    }
    return arr[(front+size-1)%cap];
}

int my_deque:: peek_front() {
    if(is_empty()) {
        cout<<"Deque is empty"<<endl;
        return -1;
    }
    return arr[front];
}

void my_deque:: print() {
    for(int i=0; i<size; i++) {
        cout<<arr[(front+i)%cap]<<" ";
    }
    cout<<endl;
}


#endif