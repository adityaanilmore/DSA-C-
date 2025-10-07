#include<iostream>
using namespace std;
#include<vector>
class Demo{
public:
int SubArraySum(vector<int>&arr){
        
    int maxSum=0;
    for (int s=0;s<arr.size();s++){
        int cs=0;

        for (int e=s;e<arr.size();e++){
            cs+=arr[e];
            maxSum= max(cs,maxSum);

        }
    }
return maxSum;
}

};
int main(){

   vector< int> arr={1,2,3,4,5};
    Demo obj;
   int ans= obj.SubArraySum(arr);
   cout<<ans<<endl;
    return 0;

}