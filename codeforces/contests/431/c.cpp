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
    vi ans;
    if(n==0)
    {
        cout<<"ab"<<endl;
        return 0;
    }
    while(n)
    {
        int r=(-1+sqrt(1+8*n))/2;
        n=n-(r*(r+1))/2;
        ans.pb(r+1);
    }
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i];j++)
        {
            cout<<(char)('a'+i);
        }
    }
    cout<<endl;
	return 0;
}

