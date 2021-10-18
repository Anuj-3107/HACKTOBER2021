#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define all(n) n.begin(),n.end() 
#define vec vector<int>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vp(it,arr)  for(auto it:arr){cout<<it<<;}
#define LOOP(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main(){
int i;
cin>>i;
while(i--){
    map<int,int>arr;
    int a,b,c;
    cin>>a>>b>>c;
    int max=a;
    if(b>max){
        max=b;
    }
    if(c>max){
        max=c;
    }
    arr[a]++;
    arr[b]++;
    arr[c]++;
    if(arr[a]==3){
       cout<<1<<" "<<1<<" "<<1<<endl;
    }else{
        if(arr[a]==2||arr[b]==2){
              if(max==a){
                  cout<<"0 ";
              }else{
                  cout<<max-a+1<<" ";
               }
           if(max==b){
                  cout<<"1 ";
              }else{
                  cout<<max-b+1<<" ";
            }

        if(max==c){
                  cout<<1<<endl;
              }else{
                  cout<<max-c+1<<endl;
              }



        }else{
            if(max==a){
                  cout<<0<<" ";
              }else{
                  cout<<max-a+1<<" ";
               }
           if(max==b){
                  cout<<0<<" ";
              }else{
                  cout<<max-b+1<<" ";
            }

        if(max==c){
                  cout<<0<<endl;
              }else{
                  cout<<max-c+1<<endl;
              }

        }
    }

 
}
return 0;
}