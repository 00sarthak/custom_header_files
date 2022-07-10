#ifndef MY_STACK_H
#define MY_STACK_H

#include<vector>
#include<iostream>
using namespace std;

class my_stack{
    public:

    int front;
    std::vector<int> s;

    my_stack();
    void push(int value);
    int pop();
    int top();
    int size();
    bool isEmpty();
    void print();
};

my_stack::my_stack() {
    s = vector<int>() ;
    front = -1;
}

void my_stack::push(int value) {
    s.push_back(value);
    front++;
}

int my_stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    int value = s[front];
    s.pop_back();
    front--;
    return value;
}

int my_stack::top() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return s[front];
}

int my_stack::size() {
    return front + 1;
}

bool my_stack::isEmpty() {
    return front == -1;
}

void my_stack::print() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    for(int i = front;i >= 0; i--){
        cout << s[i] << " ";
    }
    cout << endl;
}


#endif 