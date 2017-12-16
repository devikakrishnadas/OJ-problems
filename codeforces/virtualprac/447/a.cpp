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
    string s;
    cin>>s;
    int ans=0;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='Q')
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[j]=='A')
                {
                    for(int k=j+1;k<n;k++)
                    {
                        if(s[k]=='Q')
                        {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
	return 0;
}

