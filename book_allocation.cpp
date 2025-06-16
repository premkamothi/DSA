#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int  maximumAllowedPage)  // O(n)
{

    int student= 1, page = 0;

    for(int i=0; i<n; i++)
    {

        if(arr[i]>maximumAllowedPage) return -1;

        if(page + arr[i]<=maximumAllowedPage)
        {
            page+=arr[i];
        }
        else
        {
            student++;
            page=arr[i];
        }
    }
    return student > m ? false : true;
}

int allocationOfBooks(vector<int> &arr, int n, int m)
{

    if(m>n)
    {
        return -1;
    }

    int sum = 0, ans=-1;
    for(int i=0; i<=n; i++)  // O(n)
    {
        sum += arr[i];
    }

    int low = 0, high=sum; // range of possible answers

    while(low<=high)  // O(log(range)) -> low to high all elements -> O(logN)
    {

        int mid = low + (high - low)/2;

        if(isValid(arr, n, m, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid +1;
        }

    }
    return ans;
}

int main()
{
    // TC -> O(logN*n)
    vector<int> arr = {2, 1, 3, 4};
    int n=4, m=2;

    cout<<allocationOfBooks(arr, n, m)<<endl; // answer 6
    return 0;
}
