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
	vector<vector<int > >A(n);
	int x,y;
	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y;
		x--;
		y--;
		A[x].pb(y);
		A[y].pb(x);
	}
	vi color(n);
	for(int i=0;i<n;i++)
		cin>>color[i];
	vi childCol(n); /* denotes the number of different colors exist among children + the parent */
	for(int i=0;i<n;i++)
	{
		int d[100023]={0};
		int cnt=0;
		for(int j=0;j<A[i].size();j++)
		{
			if(!d[color[A[i][j]]])
			{
				d[color[A[i][j]]]=1;
				cnt++;
			}
		}
		if(!d[color[i]])
			cnt++;
		childCol[i]=cnt;
		cnt=0;
		
	}
	/*The vertices that can either be the root or the root's children*/
	int chno=0;
	vi ch;
	for(int i=0;i<n;i++)
	{
		if(childCol[i]!=1)
		{
			chno++;
			ch.pb(i);
		}
		cout<<childCol[i]<<" ";
	}
	for(int i=0;i<ch.size();i++)
	{
		cout<<ch[i]<<" ";
		int cnt=0;
		for(int j=0;j<A[ch[i]].size();j++)
		{
			if(childCol[A[ch[i]][j]]==1)
			{
				cnt++;
			}
		}
		if(cnt==A[ch[i]].size())
		{
			cout<<"YES"<<endl;
			cout<<ch[i]<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}

