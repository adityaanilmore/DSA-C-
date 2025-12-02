#include<iostream>
#include<vector>
using namespace std;

int binary(vector <int> arr,int target){
     int s=0;
    int e=arr.size()-1;
    
    int mid=s+(e-s)/2;


    while(s<=e){
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+e/2;
    }
    return -1;

}
int main(){

   vector <int> arr={1,2,3,4,5,6};
   int target=4;
   binary(arr,target);
}