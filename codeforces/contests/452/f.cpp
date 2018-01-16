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

set<int>chars[300];
int n,m;
string s;
const int maxn = 200023;

vi tree(5*maxn,0);
//*** Indexing begins from 1 in fenwick tree !!!***//

int query(int ind) // send 1 based index
{
    int ans=0;
    for(int i = ind ; i ; i-=(i & -i)) 
        ans+=tree[i];
    return ans;
}

void upd(int ind) // send 1 based index
{
    for(int i = ind ; i<maxn ; i += (i & -i))
        tree[i]+=1;
}

int getOrig(int i)// send 1 based index
{
    int l=1;
    int r=n;
    while(l<r)
    {
        int mid = (l+r)/2;
        int newi = mid - query(mid);
        if(newi<i)
        {
            
            l = mid+1;
        }
        else
        {
            r = mid;
        }
    }
    return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        chars[s[i]].insert(i+1);
    }
    for(int i=0;i<m;i++)
    {
        int l,r;
        char c;
        cin>>l>>r>>c;
        //cerr<<l<<" "<<r<<" ";
        l = getOrig(l);
        r = getOrig(r);
        //cerr<<l<<" "<<r<<endl;
        vi del;
        auto it = chars[c].lower_bound(l);
        for(;it != chars[c].end() and *(it) <= r; it++)
        {
            del.pb(*it);
            upd(*it);
        }
        for(int j=0;j<del.size();j++)
        {
            chars[c].erase(del[j]);
        }
    }
    vector<pair<int,char> >ans;
    for(int i=0;i<300;i++)
    {
        for(auto x:chars[i])
        {
            ans.pb(mp(x,(char)i));
        }
    }
    sort(all(ans));
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i].ss;
    }
    cout<<endl;
	return 0;
}

