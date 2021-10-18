#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define all(n) n.begin(),n.end() 
#define vec vector<int>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vp(it,arr)  for(auto it:arr){cout<<it<<;}
#define LOOP(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int power(int a,int b ){
    if(b==1||b==0) return pow(a,b);
    return a*power(a,b-1);
}
int power_optimised(int a,int b){
    if(b==1||b==0) return pow(a,b);
    int temp=power_optimised(a,b/2);
    if(b%2==0){
        return temp*temp;
    }else{
        return temp*temp*a;
    }
}

int main(){
    cout<<power(2,2)<<endl;
    cout<<power(3,4)<<endl;
    cout<<power_optimised(2,2)<<endl;
    cout<<power_optimised(3,5)<<endl;
return 0;
}