//SakhinetiPraveena
//Given an array print the maximum possible sum of the subarray(solved using Kadane's algorithm)
//O(n) solution
#include<bits/stdc++.h>
using namespace std;

int maxSubArray(int arr[],int n)
{
    int sum=0;
    int max_sum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum>max_sum) max_sum=sum;
        if(sum<0) sum=0;
    }
    return max_sum;
}

int main()
{
    int n;
    cout<<"Enter number of elements : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of the array : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Maximum sum of subarray is : "<<maxSubArray(arr,n);
}
