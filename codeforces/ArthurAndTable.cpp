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
    vector<pair<int,int> >len(n,mp(0,0));
    vi l(100023,0);
    
    for(int i=0;i<n;i++)
    {
        cin>>len[i].ff;
    }
    for(int i=0;i<n;i++)
    {
        cin>>len[i].ss;
        l[len[i].ff]+=len[i].ss;
    }
    sort(all(len));
    for(int i=1;i<n;i++)
    {
        len[i].ss+=len[i-1].ss;
    }
    
	return 0;
}

