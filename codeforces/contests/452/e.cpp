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

set<pair<int,int> >a,b;

void input(int cnt,int ind)
{
    a.insert(mp(-1*cnt,ind));
    b.insert(mp(ind,cnt));
}

void remove(int cnt,int ind)
{
    a.erase({-1*cnt,ind});
    b.erase({ind,cnt});
}
bool check(pair<int,int>x,pair<int,int>y)
{
    if(a.size()<=1)
        return 1;
    if(b.size()<=1)
        return 1;
    if(y == *b.begin())
        return 1;
    auto t = b.end();
    t--;
    if(*t==x)
        return 1;
    return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    int cnt=1;
    vi A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        if(i)
        {
            if(A[i]==A[i-1]) cnt++;
            else
            {
                input(cnt,i-cnt);
                cnt=1;
            }
        }
    }
    input(cnt,n-cnt);
    int ans = 0;
    while(a.size() > 0)
    {
        auto temp1 = *a.begin();
        temp1.ff = temp1.ff * (-1) ;
        remove(temp1.ff,temp1.ss); //reference it and make temp1 similar to instance of b
        swap(temp1.ff,temp1.ss);
        //cerr<<"Removed {cnt,ind} = {"<<temp1.ff<<","<<temp1.ss<<"}"<<endl;
        ans++;
        if(a.size() == 0)
            break;
        auto temp2 = b.lower_bound(temp1);
        auto temp3 = temp2;
        temp2--;
        //cerr<<"temp2 is {cnt,ind} = {"<< (temp2->ss) <<","<< (temp2->ff) <<"}"<<endl;
        //cerr<<"temp3 is {cnt,ind} = {"<< (temp3->ss) <<","<< (temp3->ff) <<"}"<<endl;
        //cerr<<"Values in them : "<<A[temp2->ff]<<" "<<A[temp3->ff]<<endl;
        if(check(*temp2,*temp3))
        {
            //cerr<<"I continue ***"<<endl;
            continue;
        }
        //cerr<<"I reach here"<<endl;
        if(A[temp2->ff] == A[temp3->ff])
        {
            //cerr<<"I enter the if condition"<<endl;
            remove(temp2->ss,temp2->ff);
            remove(temp3->ss,temp3->ff);
            input(temp2->ss + temp3->ss,temp2->ff);
        }
    }
    //cerr<<"exit"<<endl;
    cout<<ans<<endl;
	return 0;
}

