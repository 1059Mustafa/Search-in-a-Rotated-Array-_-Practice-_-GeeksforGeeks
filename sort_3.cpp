#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int find_the_index(int arr[],int n)
{
    int l=0;
    int r=n-1;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(m>0&&m<n-1)
        {
            if(arr[m-1]>arr[m]&&arr[m+1]>arr[m])
            {
                return m;
            }
            else if(arr[m]>arr[0])
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        else if(m==0)
        {
            if(arr[0]>arr[1])
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if(m==n-1)
        {
            if(arr[n-2]>arr[n-1])
            {
                return n-1;
            }
            else
            {
                return n-2;
            }
        }
    }
}

int find(int arr[],int l,int r,int k)
{
    while(l<=r)
    {
        int m=(l+r)/2;
        if(arr[m]==k)
        {
            return m;
        }
        else if(arr[m]>k)
        {
            r=m-1;
        }
        else
        {
            l=m+1;
        }
    }
    
    return -1;
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int x;
        cin>>x;
        int v=find_the_index(arr,n);
        int p=find(arr,0,v-1,x);
        int k=find(arr,v,n,x);
        
        cout<<max(p,k)<<endl;
    }
	return 0;
}
