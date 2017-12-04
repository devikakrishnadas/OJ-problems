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
    vll A;
    for(ll a=0;a<=9;a++)
    {
        for(ll b=0;b<=9;b++)
        {
            for(ll c=0;c<=9;c++)
            {
                for(ll d=0;d<=9;d++)
                {
                    for(ll e=0;e<=9;e++)
                    {
                        for(int f=0;f<=9;f++)
                        {
                            ll val=a;
                            val=(val*((ll)10) + b);
                            val=val*((ll)10) + c;
                            val=val * ((ll)10) + d;
                            val = val * ((ll)10) + e;
                            val = val * ((ll)10) + f;
                            ll t=val;
                            while(t)
                            {
                                val=val*((ll)10) + t%((ll)10);
                                t=t/((ll)10);
                            }
                            if(val)
                            A.pb(val);
                        }
                    }
                }
            }
        }
    }
    sort(all(A));
//    cout<<A.size()<<endl;
    ll ans=0;
    ll k,p;
    cin>>k>>p;
    for(int i=0;i<k;i++)
    {
        ans=ans+A[i];
        ans%=p;
    }
    cout<<ans<<endl;
	return 0;
}

