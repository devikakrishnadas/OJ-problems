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
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int ans=0;
    int cur=0;
    //rabbit=0 owl=1 eeyore=2;
    for(int i=1;i<n;i++)
    {
        if(cur==0)
        {
            ans=ans+min(a,b);
            if(a<b)
                cur=1;
            else cur=2;
        }
        else if(cur==1)
        {
            ans=ans+min(a,c);
            if(a<c)
                cur=0;
            else cur=2;
        }
        else if(cur==2)
        {
            ans=ans+min(b,c);
            if(b<c)
                cur=0;
            else cur=1;
        }
    }
    cout<<ans<<endl;
	return 0;
}

