#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define M 1000000007
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

int bs(vector<pair<int,int> >coins,int val,vi maxB)
{
	int ans=0;
	int s=0;
	int e=coins.size()-1;
	while(s<=e)
	{
		int mid=(s+e)/2;
		if(mid<=val)
		{
			ans=maxB[mid];
			s=mid+1;
		}
		else if(mid>val)
		{
			e=mid-1;
		}
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<pair<int,int> >diamond,coin;
	int n,c,d;
	cin>>n>>c>>d;
	for(int i=0;i<n;i++)
	{
		int a,b;
		char x;
		cin>>a>>b>>x;
		if(x=='C')
		{
			coin.pb(mp(b,a));
		}
		else
		{
			diamond.pb(mp(b,a));
		}
	}
	int ans1=0,ans2=0,ans3=0;
	sort(all(coin));
	sort(all(diamond));
	if(coin[0].ff>c || diamond[0].ff>d)
	{
		ans1=-1;
	}
	else
	{
		int val1=0,val2=0;
		for(int i=0;i<coin.size();i++)
		{
			if(coin[i].ff<=c)
			{
				val1=max(val1,coin[i].ss);
			}
			else break;
		}
		for(int i=0;i<diamond.size();i++)
		{
			if(diamond[i].ff<=d)
			{
				val2=max(val2,diamond[i].ss);
			}
			else break;
		}
		ans1=val1+val2;
	}
	if(coin[0].ff + coin[1].ff > c)
	{
		ans2=-1;
	}
	else
	{
		int val=0;
		vi maxB;
		vector<vi>fountains(300023);
		for(int i=0;i<coin.size();i++)
		{
			val=max(val,coin[i].ss);
			maxB.pb(val);
			fountains[coin[i].ff].pb(coin[i].ss);
		}
		for(int i=0;i<=100000;i++)
		{
			if(fountains[i].size()<2) continue;
			if(2*i<=c)
			{
				sort(all(fountains[i]));
				ans2=max(ans2,fountains[i][fountains.size()-1]+fountains[i][fountains.size()-2]);
			}
		}
		for(int i=coin.size()-1;i>=0;i--)
		{
			if(coin[i].ff>c)
				continue;
			else ans2=max(ans2,bs(coin,c-coin[i].ff,maxB));
		}
	}
	if(diamond[0].ff + diamond[1].ff > d)
        {
                ans3=-1;
        }
        else
        {
                int val=0;
                vi maxB;
                vector<vi>fountains(300023);
                for(int i=0;i<diamond.size();i++)
                {
                        val=max(val,diamond[i].ss);
                        maxB.pb(val);
                        fountains[diamond[i].ff].pb(diamond[i].ss);
                }
                for(int i=0;i<=100000;i++)
                {
                        if(fountains[i].size()<2) continue;
                        if(2*i<=d)
                        {
                                sort(all(fountains[i]));
                                ans3=max(ans2,fountains[i][fountains.size()-1]+fountains[i][fountains.size()-2]);
                        }
                }
                for(int i=diamond.size()-1;i>=0;i--)
                {
                        if(diamond[i].ff>d)
                                continue;
                        else ans3=max(ans2,bs(diamond,d-diamond[i].ff,maxB));
                }
        }
	cout<<max(ans1,max(ans2,ans3))<<endl;
	return 0;
}

