#include<bits/stdc++.h>
using namespace std;
int pri(int n){
    cout<<"Value is "<<n<<endl;
    return n;
}

void func(vector<int>&c,void(*fun)(int)){//passing the function as a parametre and catching the 
         for(int a:c){
             fun(a);
         }
}



int main(){
 vector<int>v;
 v.push_back(1);
 v.push_back(2);
 v.push_back(3);
 v.push_back(4);
 v.push_back(5);  
 //func(v,pri);
 int x=5;
 func(v, [](int v){cout<<"Value from lambda"<<v<<endl;});//Lambda Expressions
    return 0;
}