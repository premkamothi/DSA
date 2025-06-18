#include<iostream>
#include<vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
        int rightSum=0;
        for(int i:nums){
            rightSum+=i;
        }
        int leftSum=0;
        for(int i = 0;i<=nums.size()-1;i++){

            rightSum-=nums[i];

            if(leftSum==rightSum){
                return i;
            }

            leftSum+=nums[i];
        }
        return -1;
    }

int main(){
    int n;
    cout<<"Enter a number of elements:";
    cin>>n;

    vector<int> vec(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }

    cout<<"Pivot at index:"<<pivotIndex(vec)<<endl;

    return 0;


}
