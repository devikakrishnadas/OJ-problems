#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define MOD 1000000007
#define mp make_pair
#define all(V) V.begin,V.end

using namespace std;
vi A[1000023];
//vi B;
int cnt[1000023]={0};
int  cnter[1000023]={0};

int main()
{
	ll n,m;
//	vi A[100023];
	cin>>n>>m;
	ll k;
	int B[1000023];
//	int cnt[1000023]={0};
	map<pair<int,int> ,int>P;
	set<pair<int,int> >val;
	map<pair<int,int> , int>valu;
	int x;
	for(int i=0;i<n;i++)
	{
		cin>>k;
	//	vi B;
		//bool p[1000023]={0};
		int p[100023]={0};
		for(int j=0;j<k;j++)
		{
			cin>>x;
			B[j]=x;
			cnt[x]++;//finds the no. of times the node B[i] comes
			p[x]++;
			//p[x]=1;
		}
		for(int j=0;j<k;j++)
		{
			for(int l=0;l<k;l++)
			{
				P[mp(B[j],B[l])]++;
				val.insert(mp(B[i],B[j]));
			}
		}
		set<pair<int,int> >::iterator ii=val.begin();
		for(ii=val.begin();ii!=val.end();ii++)
		{
			(valu[mp(ii->first,ii->second)])+=(p[(ii->first)]*p[(ii->first)]);
		}
	}
//	int  cnter[1000023]={0};
	map<pair<int,int> ,int>::iterator it=P.begin();
//	map<pair<int,int> ,int> keep;//keeps arecord of all the edges that are already added
	for(it=P.begin();it!=P.end();it++)
	{
		cout<<(it->first).first<<" "<<(it->first).second<<"-----";
		if((cnt[(it->first).first]==cnt[(it->first).second] && valu[mp((it->first).first,(it->first).second)]==it->second) )
		{
			cout<<(it->first).first<<" "<<(it->first).second;
			A[(it->first).first].pb((it->first).second);
			cnter[(it->first).first]++;
		}
		else
		{
		cout<<"cnt- "<<cnt[(it->first).first]<<" "<<cnt[(it->first).second]<<"-"<<it->second<<" "<<valu[mp((it->first).first,(it->first).second)]<<endl;
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<i<<"- ";
		for(int j=0;j<A[i].size();j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}	
	ll ans=1;
	ll aa=0;
	for(int i=1;i<=m;i++)
	{
		if(cnt[i]==0)
			aa++;
	}
//	aa++;
//	aa-=2;
//	cout<<aa<<endl;
	int tm=m;
	for(int i=1;i<=aa;i++)
	{
		ans=(ans*(i))%MOD;
		tm-=1;
	}
//	cout<<ans<<endl;
	for(int i=1;i<=m;i++)
	{
		if(cnter[i]!=0)
		{
			ans=(ans*cnter[i])%MOD;
			for(int j=0;j<A[i].size();j++)
			{
				if(cnter[A[i][j]])
					cnter[A[i][j]]--;
			}
			cnter[i]=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}

