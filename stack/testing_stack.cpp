#include<iostream>
#include "my_stack.h"

using namespace std;

int main(){

    my_stack s;
    
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    s.pop();

    cout<< s.top() << endl;
    cout<< s.size() << endl;
    cout<< s.isEmpty() << endl;

    s.print();

    return 0;
}