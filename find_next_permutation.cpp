#include<iostream>
#include<vector>
using namespace std;


void nextPermutation(vector<int>& nums)
{
    int pivot = -1, n = nums.size();

    // find the pivot
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            pivot = i;
            break;
        }
    }

    if (pivot == -1)
    {
        int i = pivot + 1, j = n - 1;
        while (i <= j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        return;
    }

    // to find next smallest permuation after pivot
    for (int i = n - 1; i > pivot; i--)
    {
        if (nums[i] > nums[pivot])
        {
            swap(nums[i], nums[pivot]);
            break;
        }
    }

    // reverse elements after pivot index, it must be in increasing order
    int i = pivot + 1, j = n - 1;
    while (i <= j)
    {
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
}

int main()
{
    int n;
    cout<<"Enter a number of elements:";
    cin>>n;

    vector<int> vec(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }

    nextPermutation(vec);
    for (int i = 0; i < n; ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;


}
