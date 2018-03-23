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
    int n = s.length();
    vector< vi >a(n);
    stack<int>one,zero;
    REP(i,n)
    {
        zero.push(i);
    }
    REP(i,n)
    {
        if(s[i]=='0')
        {
            if(zero.empty())
            {
                cout<<-1<<endl;
                return 0;
            }
            int ind = zero.top();
            zero.pop();
            a[ind].pb(i);
            one.push(ind);
        }
        else
        {
            if(one.empty())
            {
                cout<<-1<<endl;
                return 0;
            }
            int ind = one.top();
            one.pop();
            a[ind].pb(i);
            zero.push(ind);
        }
    }
    int cnt=0;
    REP(i,n)
    {
        if(a[i].size()%2 == 0 and a[i].size())
        {
            cout<<-1<<endl;
            return 0;
        }
        else if(a[i].size()) cnt++;
    }
    cout<<cnt<<endl;
    REP(i,n)
    {
        if(!a[i].size()) continue;
        cout<<a[i].size()<<" ";
        for(int x : a[i])
        {
            cout<<x+1<<" ";
        }
        cout<<endl;
    }
	return 0;
}

