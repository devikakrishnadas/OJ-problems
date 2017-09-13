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

struct node
{
	int it;
	int s,e;
};
int main()
{
	int n,m;
	node A[100023];
	int pos=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>A[i].it;
		if(i)
		{
			if(A[i].it==A[pos].it)
			{
				A[i].s=pos;
			}
			else 
			{
				pos=i;
				A[i].s=i;
			}
		}
		else A[i].s=0;
	}
	pos=n-1;
	A[n-1].e=n-1;
	for(int i=n-2;i>=0;i--)
	{
		if(A[i].it==A[pos].it)
		{
			A[i].e=pos;
		}
		else 
		{	
			pos=i;
			A[i].e=pos;
		}
	}
	while(m--)
	{
		int l,r,k;
		cin>>l>>r>>k;
		l--;
		r--;
		int m=(l+r)/2;
		int ss=max(A[m].s,l);
		int ee=min(A[m].e,r);
		int val=(ee-ss+1);
		if(val>=k)
		{
			cout<<A[m].it<<endl;
		}
		else cout<<-1<<endl;
	}
	return 0;
}

