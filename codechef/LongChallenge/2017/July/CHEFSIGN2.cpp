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
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n1=0,n2=0;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='<')
            {
                n2=0;
                n1++;
            }
            else if(s[i]=='>')
            {
                n1=0;
                n2++;
            }
            ans=max(ans,max(n1,n2));
        }
        cout<<ans+1<<endl;
    }
	return 0;
}

