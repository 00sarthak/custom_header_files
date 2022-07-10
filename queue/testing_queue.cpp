#include<iostream>
#include "my_queue.h"

int main(){

    my_queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();

    cout << q.front_element() << endl;
    cout<< q.rear_element() << endl;
    cout << q.size() << endl;
    cout << q.isEmpty() << endl;
    

    q.print();

    return 0;
}