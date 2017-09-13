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

int main()
{
	int n,m;
	cin>>n>>m;
	if(m<n || ()
	{
		cout<<-1<<endl;
	}
	else
	{
		int i;
		if(m==n+1)
		{
			cout<<1;
			i=0;
		}
		else if(n==m+1)
		{
			cout<<0;
			i=1;
		}
		if(m==n)
		{
			
			while(m+n)
			{
				cout<<i%2;
				if(i%2)
				{
					m--;
				}
				else n--;
			}
		}
		if(
	}
	return 0;
}

