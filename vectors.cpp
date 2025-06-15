/*
-dynamic in nature means fixed size
-STL: Standard template library, toolbox,
-Implemented code of stack and all, only use not write whole code
-index from 0
-vector functions
-size
-push_back
-pop_back
-front
-back
-at, for particular index
-put &, pass by referenec
*/


#include <iostream>
#include <vector>
using namespace std;

int main(){

   /*

    vector<int> vec ={1,2,3};
    cout << vec[0] << endl;

    vector<int> vect(3,0);
    cout << vect[0] << endl;
    cout << vect[1] << endl;
    cout << vect[2] << endl;

    */

    vector<char> vect = {'a', 'b', 'c', 'd', 'e'};

    //gives size
    cout << "size = " << vect.size() << endl;

    //add element at the end
    vect.push_back('c');
    cout << "after push_back size = " << vect.size() << endl;

    //pop last element
    vect.pop_back();
    cout << "after pop_back size=" << vect.size() << endl;

    //print first value
    cout << "front value = "<<vect.front() << endl;

    //print last value
    cout << "last value = " << vect.back() << endl;

    cout << "at index=" << vect.at(3) << endl;

    //it gives value at index, for each loop
    for(char value: vect){
        cout << value<< endl;
    }

    vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);

    cout<< vec.size()<<endl;

    //it will double the vector in actual memory if number of element>size.
    cout <<vec.capacity() << endl;

    return 0;
}
