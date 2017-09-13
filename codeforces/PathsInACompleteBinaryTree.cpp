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

ll func(vi &bit,ll a,ll n)
{
	ll i=0;
	while(a)
	{
		bit[i]=a%2;
		a=a/2;
		i++;
		if(i==n) break;
	}
	
	return i;
	
}
void right(vi &bit,ll n)
{
	if(bit[0]==1) return;
	for(int i=1;i<n;i++)
	{
		if(bit[i])
		{
			bit[i-1]=bit[i];
			break;
		}
	}
}
void left(vi &bit,ll n)
{
	if(bit[0]==1) return;
	for(int i=1;i<n;i++)
	{
		if(bit[i])
		{
			bit[i-1]=bit[i];
			bit[i]=0;
			break;
		}
	}
}
void parent(vi &bit,ll n)
{
	for(ll i=0;i<n-1;i++)
	{
		if(bit[i])
		{
			bit[i+1]=bit[i];
			bit[i]=0;
			break;
		}
	}
}
ll val(vi bit,int n)
{
	ll ans=0,a=1;
	for(int i=0;i<n;i++)
	{	
		//a=a*2;
		if(bit[i])
		ans=ans+a;
		a=a*2;
	}
	return ans;
}
int main()
{
	ll n,q;
	cin>>n;
	cin>>q;

	vi tbit(10000,0);
//	s=log2(n+1);
	ll s=func(tbit,n,n);

	while(q--)
	{
		ll u;
		cin>>u;
		char A[100023];
		cin>>A;
		ll len=strlen(A);
	
		vi bit(s+1,0);
		func(bit,u,s);
		for(ll i=0;i<len;i++)
		{
			if(A[i]=='U') parent(bit,s);
			else if(A[i]=='L') left(bit,s);
			else right(bit,s);
		}
		cout<<val(bit,s)<<endl;
	}
	return 0;
}

