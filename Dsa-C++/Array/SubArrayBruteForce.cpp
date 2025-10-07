#include<iostream>
using namespace std;
#include<vector>
class Demo{
public:
void SubArray(vector<int>&arr){
        
    
    for (int s=0;s<arr.size();s++){

        for (int e=s;e<arr.size();e++){

        for(int i=s;i<=e;i++){
            cout<<arr[i];
        }    
        cout<<" ";
        }
        cout<<endl;

        }
    }

};
int main(){

   vector< int> arr={1,2,3,4,5};
    Demo obj;
    obj.SubArray(arr);
    return 0;

}