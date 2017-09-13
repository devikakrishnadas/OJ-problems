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

struct lis
{
	ll l;
	char na[10];
};

bool com(lis x, lis y)
{
	return ( (x.l) < (y.l) );
}
int main()
{
	ll a,b,c;
	cin>>a>>b>>c;
	ll m;
	cin>>m;
	lis A[300023];
	for(int i=0;i<m;i++)
	{
		cin>>(A[i].l)>>(A[i].na);
	}
	sort(A,A+m,com);
	ll cnt=0,cost=0;
//	cout<<A[0].l<<"*"<<endl;
	for(int i=0;i<m;i++)
	{	
		if(A[i].na[0]=='U')
		{
			if(a)
			{
				a--;
				cnt++;
				cost=cost+ (A[i].l);
			}
			else if(c)
			{
				c--;
				cnt++;
				cost=cost+(A[i].l);
			}
		}
		else
		{
			if(b)
			{
				b--;
				cnt++;
				cost=cost+A[i].l;
			}
			else if(c)
			{
				c--;
				cnt++;
				cost=cost+A[i].l;
			}
		}
//		cout<<cost<<endl;
	}
	cout<<cnt<<" "<<cost<<endl;
	return 0;
}

