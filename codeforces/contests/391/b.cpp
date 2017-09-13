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

int A[100023]={0};
void factor(ll a)
{
//	cout<<sqrt(a)<<endl;
	for(int i=2;i<=sqrt(a);i++)
	{
		if(a%i==0)
		{
			if(i*i!=a)
			A[i]++;
			
			A[a/i]++;
		}
	}
	A[a]++;
}

int main()
{
	int n;
	cin>>n;
	int x;
	int ma=0;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(x==0 || x==1) continue;
		ma=max(ma,x);
		factor(x);
		//cout<<A[2]<<endl;
	}
	int m=0;
	for(int i=2;i<=ma;i++)
	{
		
		//cout<<A[i]<<endl;
		m=max(m,A[i]);
	}
	if(m==0)
		cout<<1<<endl;
	else
	cout<<m<<endl;
	return 0;
}

