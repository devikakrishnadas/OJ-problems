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
	int n,m;
	cin>>n>>m;
	int a,b,mi=INT_MAX;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		mi=min(mi,b-a+1);
	}
	cout<<mi<<endl;
	for(int i=0;i<n;i++)
	{
		if(mi==1)
			cout<<0<<" ";
		else
			cout<<i%mi<<" ";
	}
	cout<<endl;
	return 0;
}

