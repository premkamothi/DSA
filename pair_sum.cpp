#include<iostream>
#include<vector>
using namespace std;
/**/

int main(){

    //acceding numbers
    vector<int> nums = {2,7,11,15};
    int target=9;
    int n=nums.size();

    /*
    //O(n^2)
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n-1; j++){
            if(nums[i]+nums[j]==target)
                cout<<nums[i]<<","<<nums[j];
        }
    }
    */


    int i=0,j=n-1;

    while(i<j){
        int pairSum = nums[i]+nums[j];

        if(pairSum>target)
            j--;
        else if(pairSum<target)
            i++;
        else{
            cout<<nums[i]<<","<<nums[j]<<endl;i++;j--;
        }

    }


    return 0;
}
