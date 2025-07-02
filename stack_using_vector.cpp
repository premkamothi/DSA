#include<iostream>
#include<vector>
using namespace std;

class Stack{
    vector<int> v;

public:

    void push(int value){
        v.push_back(value);
    }

    void pop(){
        v.pop_back();
    }

    int top(){
        return v[v.size()-1];
    }

    bool isEmpty(){
        return v.size()==0;
    }
};

int main(){

    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.pop();s.pop();

    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;


    return 0;
}
