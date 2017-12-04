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
    int n;
    cin>>n;
    int spec=3;
    bool no=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x==spec)
        {
            no=1;
        }
        if(spec==1)
        {
            if(x==2) spec=3;
            else if(x==3) spec=2;
        }
        else if(spec==2)
        {
            if(x==1) spec=3;
            else if(x==3) spec=1;
        }
        else if(spec==3)
        {
            if(x==1) spec=2;
            else if(x==2) spec=1;
        }
    }
    if(no)
        cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
	return 0;
}

