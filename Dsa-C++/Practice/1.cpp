#include<iostream>
using namespace std;
int main(){
    int a=1;
    int b=1;
    int limit=8;

    cout<<a<<endl;
    cout<<b<<endl;


    while(b<limit){
            int temp=a+b;
            cout<<temp<<endl;
            a=b;
            b=temp;

    }

}