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
    string s;
    cin>>s;
    vi a(200,0);
    for(int i=0;i<s.length();i++)
    {
        a[s[i]]++;
    }
    int oc=0;//odd chars
    int totchar=0;
    for(int i='a';i<='z';i++)
    {
        if(a[i]%2)
        {
            oc++;
            totchar+=(a[i]-1);
        }
        else totchar+=a[i];
    }
    int l=0;
    int mal=0;
    for(l=3;l<=400000;l+=2)
    {
        if((totchar-((l-1)*oc))%l==0 && (totchar-((l-1)*oc)) > 0)
        {
            mal=max(l,mal);
        }
    }
    int ptr=0;
    vector<vc>B(100000,0);
    for(int i='a';i<='z';i++)
    {
        int t=0;
        int cnt=0;
        while(cnt<a[i]/2)
        {
            t++;
            cnt++;
            B[ptr].pb((char)i);
            if(t==l/2)
            {
                t=0;
                ptr++;
            }
        }
    }
    
	return 0;
}

