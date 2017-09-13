#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define v_vll vector<vector<ll> >
#define all(V) V.begin,V.end
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

ll n,m;

int ans_exist(v_vll a1,v_vll a2)
{
	ll a=0,b=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a1[i][j]>a2[i][j])
			{
				a++;
			}
			else if(a1[i][j]<a2[i][j])
			{
				b++;
			}
			if(a and b)
			{
				return 0;
			}
		}
	}
	return 1;
}

void diff(v_vll a,v_vll b,v_vll &c)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			c[i].pb(abs(a[i][j]-b[i][j]));
		}
	}
}


void inp(v_vll &a)
{
	ll x;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>x;
			a[i].pb(x);
		}
	}
}

int main()
{
	ll t;
//	cin>>t;
	fast_io
	sf("%lld",&t);
	while(t--)
	{
		//cin>>n>>m;
		sf("%lld%lld",&n,&m);
		v_vll a(n),b(n);
		inp(a);
		inp(b);
		if(n==1 || m==1)
		{
			v_vll c(n);
			diff(a,b,c);
			ll mi=INT_MAX;
			ll aa=0,bb=0;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					if(a[i][j]>b[i][j]) aa++;
					else if(b[i][j]>a[i][j]) bb++;
					mi=min(mi,c[i][j]);
				}
			}
			ll ans=abs(mi);
			//cout<<aa<<" "<<bb<<" "<<ans<<endl;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					if(aa>bb)
					{
						if(a[i][j]-b[i][j]!=mi)
						{
							if(a[i][j]<b[i][j])
							{
								ans+=(b[i][j]+mi-a[i][j]);
							}
							else
							{
								ans+=(a[i][j]-b[i][j]-mi);
							}
						}
					}
					else
					{
						if(b[i][j]-a[i][j]!=mi)
						{
							if(b[i][j]>a[i][j])
							{
								ans+=(b[i][j]-a[i][j]-mi);
							}
							else
							{
								ans+=(a[i][j]+mi-b[i][j]);
							}
						}
					}
				}
			}
			//cout<<ans<<endl;
			pf("%lld\n",ans);
			continue;
		}
		int temp=ans_exist(a,b);
		if(!temp)
		{
			//cout<<-1<<endl;
			pf("-1\n");
			continue;
		}
		v_vll d(n);
		diff(a,b,d);
		ll mini[100024]={0};
		ll ans=0;
		/////////////////////Subtracted Row wise
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(j==0)
				{
					mini[i]=d[i][j];
				}
				else
				{
					mini[i]=min(mini[i],d[i][j]);
				}
			}
			for(int j=0;j<m;j++)
			{
				d[i][j]-=mini[i];
			}
			ans+=mini[i];
		}
		
		///////////////////Subtracted column wise
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(i==0)
				{
					mini[j]=d[i][j];
				}
				else
				{
					mini[j]=min(mini[j],d[i][j]);
				}
			}
		}
		for(int i=0;i<m;i++)
		{
			ans+=mini[i];
		}
		//cout<<ans<<endl;
		pf("%lld\n",ans);
	}
	return 0;
}
