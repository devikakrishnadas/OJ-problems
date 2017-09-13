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
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vi a(n);
		vi b(n);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
		}
		int c=0,d=0;
		for(int i=0;i<n;i++)
		{
			if(i%2)
			{
				c+=a[i];
				d+=b[i];
			}
			else
			{
				c+=b[i];
				d+=a[i];
			}
		}
		cout<<min(c,d)<<endl;
	}
	return 0;
}

