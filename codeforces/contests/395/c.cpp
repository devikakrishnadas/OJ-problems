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
	vi diffColors(n,0);//stores the number of unique colored children of i
	for(int i=0;i<n;i++)
	{
		int d[100023]={0};
		for(int j=0;j<A[i].size();j++)
		{
			if(!d[color[A[i][j]]])
			{
				diffColors[i]++;
				d[color[A[i][j]]]=1;
			}
			if(!d[color[i]])
				diffColors[i]++;
		}
		cout<<diffColors[i]<<endl;
	}
	cout<<endl;
	vi par;//Probable Parents
	int cnt2=0,cnt2i=0;
	for(int i=0;i<n;i++)
	{
		if(diffColors[i]>1)
		{
			par.pb(i);
		}
		if(diffColors[i]>2)
		{
			cnt2++;
			cnt2i=i+1;
		}
	}
	if(cnt2==1)
	{
		cout<<"YES"<<endl;
		cout<<cnt2i<<endl;
		return 0;
	}
	if(par.size()==0)
	{
		cout<<"YES"<<endl;
		cout<<1<<endl;
		return 0;
	}
	cout<<par.size()<<endl;
	for(int i=0;i<par.size();i++)
	{
		int cc=0;
		for(int j=0;j<A[par[i]].size();j++)
		{
			if(diffColors[A[par[i]][j]]!=1)
			{
				break;
			}
			else
				cc++;
		}
		if(cc==A[par[i]].size())
		{
			cout<<"YES"<<endl;
			cout<<par[i]<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
