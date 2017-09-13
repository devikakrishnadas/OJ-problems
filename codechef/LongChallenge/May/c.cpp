#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define M 1000000007
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vi a(2*n);
		for(int i=0;i<2*n;i++)
		{
			cin>>a[i];
		}
		sort(all(a));
		cout<<a[2*n-(n/2 +1)]<<endl;
		for(int i=0,j=2*n-1;i<j;i++,j--)
		{
			cout<<a[i]<<" "<<a[j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

