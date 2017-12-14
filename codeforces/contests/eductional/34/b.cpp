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
    int h1,a1,c1,h2,a2;
    cin>>h1>>a1>>c1>>h2>>a2;
    vector<string>ans;

    while(h2>0)
    {
        if(h1 > a2 || h2 <= a1)
        {
            ans.pb("STRIKE");
            //cout<<"STRIKE"<<endl;
            h2-=a1;
        }
        else
        {
            ans.pb("HEAL");
            h1+=c1;
        }
        h1-=a2;
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
	return 0;
}

