#include<bits/stdc++.h>
using namespace std;


int findRotationCount(int nums[], int n)
{
   
    int low = 0, high = n - 1;
 
  
    while (low <= high)
    {
        
        if (nums[low] <= nums[high]) {
            return low;
        }
 
        int mid = (low + high) / 2;
 
        
        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;
 
      
 
        if (nums[mid] <= nums[next] && nums[mid] <= nums[prev]) {
            return mid;
        }
 
      
 
        else if (nums[mid] <= nums[high]) {
            high = mid - 1;
        }
 
       
        else if (nums[mid] >= nums[low]) {
            low = mid + 1;
        }
    }
 
 
    return -1;
}
 

int main(){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(findRotationCount(a,n)!=-1){
            cout<<findRotationCount(a,n)<<endl;
        }
        else{
            cout<<"Not exist\n";
        }
}