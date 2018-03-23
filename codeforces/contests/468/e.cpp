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
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    string s;
    cin>>s;
    int n=s.length();
    vector<vi>listalloccur(26);
    REP(i,n)
    {
        listalloccur[s[i]-'a'].pb(i);
    }
    vector<set<char> >is_u(26);
    int win=0;
    int tot=0;
    REP(i,26)
    {
        int sz=listalloccur[i].size();
        if(sz==0)
            continue;
        for(int l=1;l<n;l++)
        {
            is_u[i].clear();
            for(int x:listalloccur[i])
            {
                is_u[i].insert(s[(l+x)%n]);
            }
            if(is_u[i].size()==sz)
            {
                win++;
                cout<<(char)('a'+i)<<" "<<l<<endl;
            }
            tot++;
        }
    }
    double ans = (win*1.0)/(n*1.0);
    cout<<fixed<<setprecision(10)<<ans<<endl;
	return 0;
}

