#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define all(n) n.begin(),n.end() 
#define vec vector<int>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vp(it,arr)  for(auto it:arr){cout<<it<<;}
#define LOOP(i,a,b) for(int i=a;i<b;i++)
using namespace std;
bitset<1000005>cubes;
unordered_map<long long int,long long int>m;
void gen_cubes(long long int n){
     cubes.set();
     for(long long int a=2;a*a*a<=n;a++){
         if(cubes[a]){
             for(long long int c=1;c*a*a*a<=n;c++){
                   cubes[a*a*a*c]=false;
             }
         }
     }
   long long int c=1;
   m[1]=1;
   for(int i=2;i<=n;i++){
       if(cubes[i]){
           m[i]=++c;
       }
   }

}
int main(){
gen_cubes(1000005);
int n;
cin>>n;
for(int d=1;d<=n;d++){
    int a;
    cin>>a;
    if(cubes[a]){
        cout<<"Case "<<d<<": "<<m[a]<<endl;
    }else{
        cout<<"Case "<<d<<": "<<"Not Cube Free"<<endl;
    }
}



return 0;
}