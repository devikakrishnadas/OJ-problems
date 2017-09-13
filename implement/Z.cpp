#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin,V.end

using namespace std;

//PROGRAM TO IMPLEMENT THE Z-ALGORITHM TO FIND A PATTERN IN A TEXT.

void Z(vc A,int n)//Failure function
{
	vi arr(n,0);
	int l=0,r=0;
	for(int i=1;i<n;)
	{
		int k=r-i;
		if(k<0)
			k=0;
		while(A[i+k]==A[k] && i+k<n)//Runs until the first mismatch with the prefix
		{
		
			k++;
		}
		arr[i]=k;
		l=i;
		r=k+i;
		if(k)
		{
			r=r-1;
		}
		bool enter=0;
		for(int j=1;j<r-l+1;j++)
		{
			arr[i+j]=arr[j];
			if(arr[j]+i+j>=r)
			{
				i=i+j;
				enter=1;
				break;
			}
		}
		if(!enter)
		{
			i=r+1;
		}
	}
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;	
}
int main()
{
	int n,m;
	char x;
	vc A;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>x;
		A.pb(x);
	}
	A.pb('$');//inserted so as to separate the text from the pattern
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		A.pb(x);
	}	
	Z(A,n+m+1);
	return 0;
}

