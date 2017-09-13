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

using namespace std;
ll n,m,k;
ll C[5000][5000]={0};

vll B;
ll func(vll &B, ll val, ll mk,ll s)
{
	if(mk==k )
	{
		return val;
	}
	if(s+m>B.size())
               return -1;
	bool enter=0;
        if(C[mk][s]>-1)
        {
		enter=1;
		cout<<mk<<" "<<s<<" "<<C[mk][s];
//                return C[mk][s];
        }
	for(int i=s;i<B.size();i++)
	{
		C[mk][s]=max(C[mk][s],func(B,val+B[i],mk+1,i+m));
	}	
	if(enter)
	{
		cout<<"----"<<mk<<" "<<C[mk][s]<<endl;
	}
	return C[mk][s];
}

int main()
{
	sf("%lld%lld%lld",&n,&m,&k);
	vll A(n+1,0);
	for(int i=0;i<5000;i++)
	{
		for(int j=0;j<5000;j++)
		{
			C[i][j]=-1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		sf("%lld",&A[i]);
		A[i]=A[i-1]+A[i];
	}
	ll s=0,e=m;
//	vll B;
	for(;e<=n;e++,s++)
	{
		B.pb(A[e]-A[s]);
	}
	cout<<func(B,0,0,0)<<endl;
	return 0;
}
