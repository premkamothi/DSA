#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int>& arr, int n, int c,int minAllowdDistance)
{
    int cows=1, lastStallPossible=arr[0];
    for(int i=1; i<n; i++)
    {
        if((arr[i]-lastStallPossible)>=minAllowdDistance)
        {
            cows++;
            lastStallPossible=arr[i];
        }
        if(cows==c) return true;
    }
    return false;
}

int minDistance(vector<int>& arr, int n, int c)  // n= numbers of stalls, c=numbers of cows
{

    sort(arr.begin(), arr.end()); // add #include <algorithm>

    int low=1, high=arr[n-1]-arr[0], ans=-1; //high=maxValueArr-minValueArr

    while(low<=high)
    {
        int mid = low + (high - low)/2;
        if(isPossible(arr,n,c,mid))
        {
            ans=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }

    }
    return ans;
}


int main()
{
    int n,c;

    cout<<"Enter a number of stalls(array size) :";
    cin>>n;
    vector<int> arr(n);
    cout << "Enter elements of array :\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << "Enter number of cows: ";
    cin >> c;

    cout<<minDistance(arr, n, c)<<endl;



    return 0;


}
