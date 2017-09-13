#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()
#define ff first
#define ss second

using namespace std;


int lis(vector<pair<int,int> >a)
{
	sort(all(a));
	int n=a.size();
	vi parent(n+1,0);
	vi li(n,1);
	parent[0]=-1;
	int p=0;
	for(int i=1;i<n;i++)
	{
		if(a[p].ss<a[i].ss && a[p].ff<a[i].ff)
		{
			parent[i]=p;
			li[i]=li[p]+1;
			p=i;
		}
		else
		{
			int t=p;
			while(p!=-1 && (a[p].ss>=a[i].ss || a[p].ff>=a[i].ff))
			{		
				p=p-1;
			}
			parent[i]=p;
			if(p!=-1)
				li[i]=li[p]+1;
			p=t;
			if(li[i]==li[t])
			{
				if(a[i].ss<=a[t].ss && a[i].ff<=a[t].ff)
				{
					p=i;
				}
			}
		}
	}
	int cnt[20001]={0};
	int minus=0;
	int tot=0;
	for(int i=0;i<n;i++)
	{
		
		if(parent[i]!=-1)
		{
			cnt[parent[i]]++;
			tot=max(tot,cnt[parent[i]]);
			//cout<<cnt[parent[i]]<<" p"<<endl;
		}
		else 
		{	
			//cout<<minus<<" m"<<endl;
			minus++;
			tot=max(tot,minus);
		}
//		cout<<parent[i]<<" ";	
	}
//	cout<<endl;
	return tot;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<pair<int,int> >A,B;
		for(int i=0;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			A.pb(mp(x,y));
			B.pb(mp(y,x));
		}
		int a=lis(A),b=lis(B);
//		cout<<a<<" "<<b<<endl;
		int ans=min(a,b);
		cout<<ans<<endl;
	}
	return 0;
}

