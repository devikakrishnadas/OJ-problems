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
    ll a,b;
    cin>>a>>b;
    if(a==b)
    {
        cout<<1<<endl;
        return 0;
    }
    if(a<b) swap(a,b);
    //ll g=__gcd(a,b);
    /*if(a==g || b==g)
    {
        cout<<g<<endl;
        return 0;
    }*/
    //cout<<'g'<<g<<endl;
    ll ta=a;
    ll tb=b;
    //a=a/g;
    //b=b/g;
    ll diff=a-b;
    ll minlc=LLONG_MAX;
    ll x=0;
    for(int i=1;i<=sqrt(diff);i++)
    {
        if(diff%i==0)
        {
            ll g1=i;
            ll g2=diff/i;
            ll a1=a+(g1-a%g1);
            ll b1=b+(g1-b%g1);
            ll a2=a+(g2-a%g2);
            ll b2=b+(g2-b%g2);
            ll lc1=(a1*b1)/g1;
            ll lc2=(a2*b2)/g2;
            if(lc1<minlc)
            {
                minlc=lc1;
                x=(g1-a%g1);
            }
            if(lc2<minlc)
            {
                minlc=lc2;
                x=(g2-a%g2);
            }
        }
    }
    cout<<x<<endl;
	return 0;
}

