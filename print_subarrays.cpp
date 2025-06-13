#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n=7;
    int arr[n] = {3,-4,5,4,-1,7,-8};


    /* O(n^3)
    for(int start=0; start<n; start++){
         for(int end=start; end<n; end++){
             for(int i=start; i<=end; i++){
                     cout<<arr[i];
             }
             cout<<" ";
         }
         cout<<endl;
     }
     */

    //brute force method, O(n^2)
    int maxSum = INT_MIN,currentSum = 0;
    /*
    for(int start=0; start<n; start++){

       for(int end=start; end<n; end++){

           currentSum+= arr[end];
           maxSum=max(currentSum, maxSum);
       }
    }
    */

    //most optimizes, kadane's algorithm, dynamic programming algorithm, O(n)
    for(int start=0; start<n; start++)
    {
        currentSum+=arr[start];
        maxSum = max(currentSum, maxSum);
        if(currentSum<0)
            currentSum=0;
    }


    cout<<maxSum<<endl;
    return 0;
}

