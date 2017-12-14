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
    int l=0,r=0;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x>0)
            r++;
        else l++;
    }
    if(l<=1 || r<=1)
    {
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
	return 0;
}

