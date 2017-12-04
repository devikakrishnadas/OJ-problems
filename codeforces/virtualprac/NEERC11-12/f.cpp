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

ll getLastBit(ll x) {
    ll ans = 1;
    while (x > 0) {
        ans <<= 1ll;
        x >>= 1;
    }
    return ans/2;
}
void func1(ll num,ll n)
{
    if(n<=1)
    {
        return;
    }
    ll x=getLastBit(n);
    if(num>x)
    {
        n-=x;
        num-=x;
        cout<<'R';
        func1(num,n);
    }
    else
    {
        if (n != x) cout<<"L";
        bitset<40>b=(num-1);
        int i =0;
         while ((1 << i) < x) i += 1;
         i -= 1;
        while (i >= 0) {cout << (b[i] == 0 ? 'L' : 'R'); --i;}
    }
}

ll func2(ll n, string &s, int ind)
{
    if(ind == s.length())
    {
        return 0;
    }
    ll x=getLastBit(n);
    if(x==n)
    {
        ll ans=0;
        for(int i=ind;i<s.length();i++)
        {
            if(s[i] == 'R')
                ans |= (1 << ((int)s.length() - i - 1));
        }
        return ans;
    }
    else
    {
        if(s[ind]=='L')
        {
            return func2(x,s,ind+1);
        }
        else
        {
            return x+func2(n-x,s,ind+1);
        }
    }
}
int main()
{
/*	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);*/
    freopen("cbt.in","r",stdin);
    freopen("cbt.out","w",stdout);
    ll n,q;
    cin>>n>>q;
    while(q--)
    {
        string a;
        cin>>a;
        if(a=="A")
        {
            ll num;
            cin>>num;
            num += 1;
            func1(num,n);
            cout<<endl;
        }
        else
        {
            string s;
            cin>>s;
            ll ans=func2(n,s,0);
            cout<<ans<<endl;
        }
        
    }
	return 0;
}

