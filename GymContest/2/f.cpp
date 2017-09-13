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
bool isRational(int n,int d)
{
    ll g=__gcd(n,d);
    n=n/g;
    d=d/g;
    while(d%2==0)
        d=d/2;
    while(d%5==0)
        d=d/5;
    if(d!=1)
        return 0;
    return 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    vi f1,fn;
    for(int i=1;i<=sqrt(a[0]);i++)
    {
        if(a[0]%i==0)
        {
            cout<<i<<" ";
            f1.pb(i);
            if(i!=(a[0]/i))
            {
                cout<<a[0]/i<<" ";
                f1.pb(a[0]/i);
            }
        }
    }
    cout<<endl;
    for(int i=1;i<=sqrt(a[n-1]);i++)
    {
        if(a[n-1]%i==0)
        {
            fn.pb(i);
            cout<<i<<" ";
            if(i!=(a[n-1]/i))
            {
                cout<<a[n-1]/i<<" ";
                fn.pb(a[n-1]/i);
            }
        }
    }
    int cnt=0;
    for(int i=0;i<f1.size();i++)    
    {
        for(int j=0;j<fn.size();j++)
        {
            if(!isRational(fn[j],f1[i]))
            {
                cout<<"i"<<f1[i]<<endl;
                cnt++;
                break;
            }
        }
    }
    cout<<endl;
    cout<<cnt<<endl;
	return 0;
}

