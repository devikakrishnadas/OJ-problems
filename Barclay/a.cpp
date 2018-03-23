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
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)

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
        string a,b;
        cin>>a>>b;
        int k;
        cin>>k;
        int n = a.length();
        vi cnta(30,0),cntb(30,0);
        vi cntva(30,0),cntvb(30,0);
        REP(i,n)
        {
            cnta[a[i]-'a']++;
            cntb[b[i]-'a']++;
        }
        REP(i,30)
        {
            REP(j,k)
            {
                cntva[i]+=cnta[(i+j)%26];
                cntvb[i]+=cntb[(i+j)%26];
            }
        }
        int ind1 = distance(cntva.begin(),max_element(all(cntva)));
        int ind2 = distance(cntvb.begin(),max_element(all(cntvb)));
        int ans = abs(ind1-ind2);
        char bega,enda,begb,endb;
        bega = 'a' + ind1;
        enda = (ind1 + k)%26 + 'a';
        begb = 'a' + ind2;
        endb = (ind2 + k)%26 + 'a';
//        cout<<ans<<endl;
        REP(i,n)
        {
            if(!(a[i] >= bega or a[i] <= enda))
            {
                ans += min(abs(a[i] - bega), abs(a[i] - enda));
            }
            if(!(b[i] >= begb or b[i] <= endb))
            {
                ans += min(abs(b[i] - begb), abs(b[i] - endb));
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}

