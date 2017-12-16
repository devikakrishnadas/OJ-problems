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

bool issuf(string a,string b)
{
    if(b.size() < a.size()) return 0;
    //cout<<a<<" "<<b<<endl;
    for(int i=0;i<a.size();i++)
    {
        int j=b.size()-a.size()+i;
        //cout<<a[i]<<" "<<b[j]<<endl;
        if(a[i] != b[j])
            return 0;
    }
    return 1;
}
vector<string> minimize(vector<string>&a)
{
    sort(all(a));
    auto it = unique(all(a));
    a.resize(distance(a.begin(),it));
    if(a.size()==1)
    {
        return a;
    }
    vector<string> ans;
    for(int i=0;i<a.size();i++)
    {
        bool no=0;
        for(int j=0;j<a.size();j++)
        {
            if(i==j)
                continue;
            if(issuf(a[i],a[j]))
            {
                no=1;
                break;
            }
        }
        if(!no)
        {
            ans.pb(a[i]);
        }
    }
    return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    map<string,vector<string> >a,ans;
    vector<string>b;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            string x;
            cin>>x;
            a[s].pb(x);
        }
    }
    cout<<a.size()<<endl;   
    for(auto x : a)
    {
        vector<string> v = minimize(x.ss);
        cout<<x.ff<<" "<<v.size()<<" ";
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

	return 0;
}

