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
        int cnt=1;
        int fin=0;
        vi a;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='<') a.pb(1);
            else if(s[i]=='>') a.pb(-1);
        }
        int mi=INT_MAX;
        int ma=INT_MIN;
        int fin1=0;
        vi d;
        for(int i=0;i<a.size();i++)
        {
            //cout<<a[i]<<" ";
            fin+=a[i];
            fin1+=a[i];
            if(a[i]>fin1)
            {
                fin1=a[i];
            }
            if(a[i]<fin)
            {
                fin=a[i];
            }
            ma=max(ma,max(abs(fin),abs(fin1)));
            //cout<<fin<<" "<<endl;
            d.pb(ma);
        }
        ma=max(ma,0);
        cout<< -- <<endl;
    }
	return 0;
}

