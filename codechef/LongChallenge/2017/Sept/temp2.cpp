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
    vi cntElements(100001,0);
    vi pow2(100001,0);
    ll pussy=1;
    for(int i=0;i<=100000;i++)
    {
        cntElements[i]=i+1;
        pow2[i]=pussy;
        if(i==2*pussy)
        {
            pussy=2*pussy;
        }
    }
    ll ttt=0;
    
    for(int d=1;d<=100000;d++)
    {
        ll ans=0;
        ll skip=pow2[d];
        for(int i=2;i<=100000;i++)
        {
            if(!((i-1)&(d-1)))
            {

                ans^=cntElements[i];
            }
            ttt++;
            
            if(skip)
            if(i%(2*skip)==skip)
            {
                i=i+skip;
            }
        }
        cout<<ttt<<endl;
    }

	return 0;
}

