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
    ll n,k;
    cin>>n>>k;
    vi a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int loc=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[loc]) loc=i;
    }
    
        int kcnt=0;
        int ma=0;
        for(int i=1;i<loc;i++)
        {
            if(a[i]>a[ma])
            {
                ma=i;
                kcnt=1;
            }
            else kcnt++;
            if(kcnt==k)
            {
                cout<<a[ma]<<endl;
                return 0;
            }
        }
    
    cout<<*max_element(all(a))<<endl;
    
	return 0;
}

