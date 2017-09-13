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
	int n;
	cin>>n;
	vector<pair<int,int> >A;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		A.pb(mp(a,i+1));
	}
	sort(all(A));
	int ma=-1;
	vi ans(200023,0);
	for(int i=0;i<n;i++)
	{
		if(A[i].ss>ma)
		{
			ma=A[i].ss;
			ans[A[i].ss]=-1;
		}
		else
		{
			ans[A[i].ss]=ma-A[i].ss-1;
		}
		//cout<<A[i].ss<<" "<<ans[A[i].ss]<<endl;
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}

