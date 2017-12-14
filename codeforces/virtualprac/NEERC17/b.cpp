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
    ll a,b,c,w,h;
    cin>>a>>b>>c>>w>>h;
    vi f;
    f.pb(a);
    f.pb(b);
    f.pb(c);
    vi s;
    s.pb(w);
    s.pb(h);
    sort(all(s));
    sort(all(f));
    do
    {
        w=s[0];
        h=s[1];
        sort(all(f));
        do
        {
            a=f[0];
            b=f[1];
            c=f[2];
//            cout<<a<<" "<<b<<" "<<c<<" "<<w<<" "<<h<<endl;
            if(a + c <=h and a + 3*b + c <=w)
            {
                cout<<"Yes"<<endl;
                return 0;
            }
            else if(2*a + 2*b <=h and c + 2*a <=w)
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }while(next_permutation(all(f)));
    }while(next_permutation(all(s)));
    cout<<"No"<<endl;
	return 0;
}

