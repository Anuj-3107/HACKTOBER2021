#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define all(n) n.begin(),n.end() 
#define vec vector<int>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vp(it,arr)  for(auto it:arr){cout<<it<<;}
#define LOOP(i,a,b) for(int i=a;i<b;i++)
#define MAX 1000000
using namespace std;
bitset<MAX> isprime;
vector<int>primes;
void gen_primes(){
    isprime.set();
    isprime[0]=isprime[1]=false;
    for(ll i=2;i*i<=MAX;i++){
        if(isprime[i]){
            for(ll j=i;j*i<=MAX;j++){
              isprime[j*i]=false;
            }
        }
    }
    primes.push_back(2);
    for(ll k=3;k<=MAX;k+=2){
          if(isprime[k]){
              primes.push_back(k);
          }
    }
}


int main()
{
  gen_primes();
  //First 100 prime numbers
  for(int f=0;f<100;f++){
      cout<<primes[f]<<" ";
  }
return 0;
}