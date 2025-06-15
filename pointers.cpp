#include<iostream>
#include<vector>
using namespace std;

int main(){

    int a=10;//0x61fe4c
    cout<<&a<<endl;
    int *  ptr = &a;//gives address of a
    cout<<ptr<<endl;
    cout<<&ptr<<endl;

    int ** ptr2= &ptr;//pointer to pointer
    cout<<ptr2<<endl;

    cout<<*(&a)<<endl;//gives value at address a, dereference
    cout<<*(ptr)<<endl;// gives value of address which is value of ptr,100
    cout<<*(ptr2)<<endl;
    cout<<**(ptr2)<<endl;

    int **ptr3= NULL;
    cout<<*(ptr3)<<endl;






    return 0;
}
