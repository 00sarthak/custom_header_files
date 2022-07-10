#include <iostream>
#include "my_deque.h"

using namespace std;

int main(){

    my_deque d(10);
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);

    d.push_front(5);
    d.push_front(6);
    d.push_front(7);

    d.print();

    d.pop_back();
    d.pop_front();
    
    d.print();

    cout<<d.peek_back()<<endl;
    cout<<d.peek_front()<<endl;
    cout<<d.is_empty()<<endl;
    cout<<d.is_full()<<endl;


    return 0;
}