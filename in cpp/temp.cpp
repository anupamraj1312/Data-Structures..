#include<bits/stdc++.h>
using namespace std;
int linearSearch(int* arr,int num,int len)
	{
		for(int i=0;i<len;i++)
		{
			if(arr[i]==num)
			{
				return i+1;
			}
		}
		return -1;
	}

int binarySearch(int arr[],int num,int len)
	{
		int start=0,endd=len-1;
		while(start<=endd)
		{
			int mid=(start+endd)/2;
			if(arr[mid]==num)
			{
				return mid+1;
			}
			else if(num<arr[mid])
			{
				endd=mid-1;
			}
			else
			{
				start=mid+1;
			}
		}
		return -1;
	}
int interpolationSearch(int arr[],int num,int len)
	{
		int start=0;
		int endd=len-1;
		while(start<=endd)
		{
			int pos = start + (((double)(endd-start) /
              (arr[endd]-arr[start]))*(num - arr[start]));
			if(arr[pos]==num)
			{
				return pos+1;
			}
			else if(num<arr[pos])
			{
				endd=pos-1;
			}
			else if(num>arr[pos])
			{
				start=pos+1;
			}
		}
		return -1;
	}
	int main() {
		cout<<"enter size of the array";
		int n;
		cin>>n;
		int arr[n];
		cout<<"enter array elements";
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		cout<<"enter number to be searched";
		int num;
		cin>>num;
		cout<<"enter  your choice"<<endl;
        cout<<"1.linear search"<<endl;
		cout<<"2.binary search"<<endl;
		cout<<"3.interpolation search"<<endl;
		int option;
		cin>>option;
		int ans;
        switch(option)
			{
			case 1: ans=linearSearch(arr,num,n);
			break;
			case 2: ans=binarySearch(arr,num,n);
			break;
			case 3: ans=interpolationSearch(arr,num,n);
			break;
			}
		if(ans==-1)
            cout<<"not found ";
        else
        cout<<"found at "<<ans<<"th position ";

return 0;
}
