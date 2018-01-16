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
    int t,n,k;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cin>>s;
        int u=0,l=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]>='a' and s[i]<='z')
            {
                l++;
            }
            else u++;
        }
        if(l <= k && u<= k)
        {
            cout<<"both"<<endl;
        }
        else if(l<=k)
        {
            cout<<"brother"<<endl;
        }
        else if(u<=k)
        {
            cout<<"chef"<<endl;
        }
        else
        {
            cout<<"none"<<endl;
        }
    }
	return 0;
}

