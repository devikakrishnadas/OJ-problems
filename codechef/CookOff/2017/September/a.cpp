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
        bool enter=0;
        string s;
        cin>>s;
        vi a(300,0);
        for(int i=0;i<s.length();i++)
        {
            if(a[s[i]])
            {
                enter=1;
                cout<<"yes"<<endl;
                break;
            }
            a[s[i]]=1;
        }
        if(!enter)
        {
            cout<<"no"<<endl;
        }
    }
	return 0;
}

