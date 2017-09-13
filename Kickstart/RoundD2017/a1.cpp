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
        int n,ts,tf;
        cin>>n>>ts>>tf;
        vector<pair<pair<int,int>,int> >A(n+1);
        int t=0;
        vi isTour(n+1,0);
        vi startTime(n+1,0);
        for(int i=1;i<n;i++)
        {   
            int s,f,d;
            cin>>s>>f>>d;
            startTime[i]=t;
            A[i]=mp(mp(s,f),d);
            int tt=(f-s%f)%f;
            if(t%f!=0)
            {
                t=t+tt;
            }
            t=t+d;
        }
        if(t>tf)
        {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        int mint=2;
        startTime[n]=t;
        t=0;
        vi endTime(n+1,0);
        endTime[0]=INT_MAX;
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            
            int s,f,d;
            int mint=0;
            //cout<<i<<"i"<<endl;
            for(int j=mint+1;j<n;j++)
            {
                t=0;
                t=t+startTime[j];
                s=A[j].ff.ff;
                f=A[j].ff.ss;
                d=A[j].ss;
                t=t+ts;
                int tt=(f-s%f)%f;
                if(t%f!=0)
                    t=t+tt;
                t=t+d;
                //cout<<j<<"j"<<endl;
                for(int k=j+1;k<n;k++)
                {
                    s=A[k].ff.ff;
                    f=A[k].ff.ss;
                    d=A[k].ss;
                    int tt=(f-s%f)%f;
                    if(t%f!=0)
                        t=t+tt;
                    t=t+d;
                    //cout<<k<<"k"<<endl;
                }
                endTime[j]=t;
                if(endTime[j]<endTime[mint])
                {
                    mint=j;
                }
                //cout<<"jend"<<" "<<j<<" "<<n<<endl;
            }
            //cout<<"r3"<<endl;
            if(endTime[mint]>tf)
            {
                continue;
            }
            cout<<"mint"<<" "<<mint<<endl;
            if(isTour[mint]==0)
            {
                cnt++;
                isTour[mint]=1;
            }
            else continue;
            t=startTime[mint];
            //cout<<"r2"<<endl;
            for(int j=mint;j<n;j++)
            {
                startTime[j]=t;
                s=A[j].ff.ff;
                f=A[j].ff.ss;
                d=A[j].ss;
                if(i==mint)
                {
                    t=t+ts;
                }
                int tt=(f-s%f)%f;
                if(t%f!=0)
                    t=t+tt;
                t=t+d;
            }
            //cout<<"r1"<<endl;
        }
        cout<<cnt<<endl;
    }
	return 0;
}

