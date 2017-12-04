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
    ll n,k,m;
    cin>>n>>k>>m;
    vi a(n);
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    vi b(m);
    int ti=-1;
    for(int i=0;i<n;i++)
    {
        b[a[i]%m]++;
        if(b[a[i]%m]>=k)
        {
            ti=a[i]%m;
            break;
        }
    }
    sort(all(a));
    if(ti==-1)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
        int cntr=0;
        for(int i=0;(i<n && cntr<k);i++)
        {
            if(a[i]%m==ti)
            {
                cout<<a[i]<<" ";
                cntr++;
            }
        }
        cout<<endl;
    }
    
	return 0;
}

