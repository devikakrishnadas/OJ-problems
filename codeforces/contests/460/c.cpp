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
    int n,m,k;
    cin>>n>>m>>k;
    char A[2002][2002];
    REP(i,n)
    {
        cin>>A[i];
    }
    if(k==1)
    {
        int ct=0;
        REP(i,n)
        {
            REP(j,m)
            {
                if(A[i][j] == '.')
                    ct++;
            }
        }
        cout<<ct<<endl;
        return 0;
    }
    vi a;
    REP(i,n)
    {
        int cnt=0;
        REP(j,m)
        {
            if(A[i][j]=='*')
            {
                if(cnt >= k)
                {
                    a.pb(cnt);
                }
                cnt = 0;
            }
            else cnt++;
        }
        if(cnt>=k)
            a.pb(cnt);
    }

    REP(j,m)
    {
        int cnt=0;
        REP(i,n)
        {
            if(A[i][j]=='*')
            {
                if(cnt>=k)
                {
                    a.pb(cnt);
                }
                cnt=0;
            }
            else cnt++;
        }
        if(cnt>=k)
            a.pb(cnt);
    }
    int ans=0;
    for(int i=0;i<a.size();i++)
    {
        ans += (a[i] - k + 1);
    }
    cout<<ans<<endl;
	return 0;
}

