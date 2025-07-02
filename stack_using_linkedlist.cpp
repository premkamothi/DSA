#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Stack{
    list<int> ll;

public:

    void push(int value){
        ll.push_front(value);
    }

    void pop(){
        ll.pop_front();
    }

    int top(){
        return ll.front();
    }

    bool isEmpty(){
        return ll.size()==0;
    }
};

int main(){

    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();


    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;


    return 0;
}
