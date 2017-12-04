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
    int ma=0;
    vector<pair<int,int> >A;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        A.pb(mp(x,y));
        ma=max(ma,x);
    }
    int ans=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i].ff<=ma && ma<= A[i].ss)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
	return 0;
}

