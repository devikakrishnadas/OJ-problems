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

int ans=0;
int lps[1000][1000]={0};

int LPS(int s,int e,char A[100023])
{
	if(e==s)
	{
		return 1;
	}
	if(e<s)
	{
		return 0;
	}
	if(lps[s][e])
	{
		return lps[s][e];
	}
	if(A[s]==A[e])
	{
		lps[s][e]=2+LPS(s+1 , e-1 , A);
	}
	else
	{
		lps[s][e]=max(LPS( s+1 , e , A) , LPS( s , e-1 , A));
	}
	return lps[s][e];
}
int main()
{
	char A[100023];
	cin>>A;
	int n=strlen(A);
	cout<<LPS(0,n-1,A)<<endl;
	return 0;
}

