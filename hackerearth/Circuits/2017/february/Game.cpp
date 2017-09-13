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
//bool A[4][1000000023]={0};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		int x,y;
		map<int,int> A[4];
		int minx=INT_MAX;
		while(q--)
		{
			cin>>x>>y;
			A[y][x]=1;
		}
		map<int,int>::iterator it;	
		x=n;
		for(it=A[1].begin();it!=A[1].end();it++)
		{
			x=it->first;
			if(A[2].find(x)!=A[2].end() && A[3].find(x)!=A[3].end())
			{
				minx=x-1;
				goto pk;
			}
			bool e=0;
			while(A[2].find(x)!=A[2].end() && x>0)
			{	
				e=1;
				x--;
			}
			if(A[3].find(x+1)!=A[3].end() && e)
			{
				minx=x-1;
				goto pk;
			}
		}
		if(minx==INT_MAX)
			minx=n;
		pk:cout<<minx<<endl;
	}
	return 0;
}

