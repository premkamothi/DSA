#include<iostream>
#include<vector>
using namespace std;

void merge_array(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int index=m+n-1;
    int i=m-1,j=n-1;
    while(i>=0 && j>=0)
    {
        if(nums1[i]>=nums2[j])
        {
            nums1[index]=nums1[i];
            index--;
            i--;
        }
        else
        {
            nums1[index]=nums2[j];
            index--;
            j--;
        }
    }
    while(j>=0)
    {
        nums1[index]=nums2[j];
        index--;
        j--;
    }
}

int main()
{
    int a,b;

    cout<<"Enter a number of elements for sorted array 1:";
    cin>>a;
    vector<int> a1(a);
    cout << "Enter elements of sorted array 1:\n";
    for (int i = 0; i < a; ++i)
    {
        cin >> a1[i];
    }

    cout<<"Enter a number of elements for sorted array 2:";
    cin>>b;
    vector<int> b1(b);
    cout << "Enter elements of sorted array 2:\n";
    for (int i = 0; i < b; ++i)
    {
        cin >> b1[i];
    }

    merge_array(a1, a, b1, b);

    cout << "Merged array:\n";
    for (int i = 0; i < a + b; ++i)
    {
        cout << a1[i] << " ";
    }
    cout << endl;
    return 0;


}
