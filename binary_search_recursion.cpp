#include<iostream>
#include<vector>
using namespace std;

int binarySearchRecursive(vector<int> arr, int target, int low, int high)
{

        if(low<=high)
        {
            int mid = low + (high-low)/2;

            if(target>arr[mid])
            {
                return binarySearchRecursive(arr, target, mid+1, high);
            }
            else if(target<arr[mid])
            {
                return binarySearchRecursive(arr, target, low, mid-1);
            }
            else
            {
                return mid;
            }
        }

    return -1;

}

int binarySearch(vector<int> arr, int target){
    return binarySearchRecursive(arr, target, 0, arr.size()-1);
}

int main()
{
    vector<int> nums = {3,4,5,6,7,8,9,12};
    int tar = 9;

    cout<<"At index:" <<binarySearch(nums, tar)<<endl;
    return 0;
}
