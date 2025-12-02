#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
string str="Aditya";
string str1="ayAtid";

if(str.length()!=str1.length()){
    cout<<" anagram"<<endl;
}

sort(str.begin(),str.end());
sort(str1.begin(),str1.end());

if(str==str1){
    //anagram
}
else{
    //not anagram
}

}