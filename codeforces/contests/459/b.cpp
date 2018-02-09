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
    map<string,string> names;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        string a,b;
        cin>>a>>b;
        names[b] = a;
    }
    vector<pair<pair<string,string>,string> >ans;
    for(int i=0;i<m;i++)
    {
        string a,b;
        cin>>a>>b;
        ans.pb(mp(mp(a,b),names[b.substr(0,b.size()-1)]));
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i].ff.ff<<" "<<ans[i].ff.ss<<" #"<<ans[i].ss<<endl;
    }
	return 0;
}

