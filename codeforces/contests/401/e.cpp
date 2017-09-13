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

struct ring
{
	int a,b,c;
};

bool rb(ring x, ring y)
{
	return x.b<y.b;
}

bool ra(ring x,ring y)
{
	return x.a<y.a;
}

int main()
{
	int n;
	cin>>n;
	ring A[100023];
	for(int i=0;i<n;i++)
	{
		cin>>A[i].a>>A[i].b>>A[i].c;
	}
	sort(A,A+n,ra);
	stable_sort(A,A+n,rb);
	int ans=0;
	int sum=0;
	int k=1;
	sum=A[n-1].c;
	for(int i=n-2;i>=0;i--)
	{
		if(A[i].b>A[i+1].a)
		{
			sum=sum+A[i].c;
		}
		else
		{
			ans=max(ans,sum);
			sum=A[i].c;
		}
	}
	ans=max(ans,sum);
	cout<<ans<<endl;
	return 0;
}

