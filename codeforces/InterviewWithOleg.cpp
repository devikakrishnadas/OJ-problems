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

int main()
{
	int n;
	cin>>n;
	char A[2000];
	cin>>A;
	int fstart=0;
	for(int i=0;i<n;i++)
	{
		if(A[i]=='o' && A[i+1]=='g' && A[i+2]=='o'&& i<n-2)
		{
			fstart=1;
			A[i]='*';
			A[i+1]='*';
			A[i+2]='*';
			i=i+2;	
		}
		else if(fstart==1 &&i<n-1 && (A[i-1]=='*'||A[i-1]=='&') && A[i]=='g'&& A[i+1]=='o')
		{
			A[i]='&';
			A[i+1]='&';
			i=i+1;
			
		}
		else fstart=0;
	}
	for(int i=0;i<n;i++)
	{
		if(A[i]=='&') continue;
		else cout<<A[i];
	}
	cout<<endl;
	return 0;
}

