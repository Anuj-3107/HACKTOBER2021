//selection sort
#include<iostream>
using namespace std;
 void selectionsort(int a[],int n){
     for(int i=0;i<n-1;i++)//fnd out smallest element idx in the unsorted array
     { int min_index=i;
         for(int j=i;j<=n-1;j++)
         {
            if(a[j]<a[min_index]){
                min_index=j;
            }
         }//after this loop we can do swap finally
         swap(a[i],a[min_index]);
     }
 }



int main(){
    int n;
    cin>>n;
    int a[1000];
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
   
selectionsort(a,n);
for(int i=0;i<n;i++)
{
    cout<<a[i]<<" ,";
}
return 0;
}