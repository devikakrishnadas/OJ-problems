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
    while(cin>>s)
    {
        int teama=0;
        int teamb=0;
        int cnta=5;
        int cntb=5;
        bool enter=0;
        for(int i=0;i<10;i++)
        {
            if(s[i]=='1')
            {
                if(i%2) teamb++;
                else teama++;
            }
            if(i%2) cntb--;
            else cnta--;
            if(teama > teamb + cntb)
            {
                enter=1;
                cout<<"TEAM-A"<<" "<<i+1<<endl;
                break;
            }
            else if( teamb > teama + cnta)
            {
                enter=1;
                cout<<"TEAM-B"<<" "<<i+1<<endl;
                break;
            }
        }
        if(teama == teamb)
        {
            for(int i=10;i<20;i+=2)
            {
                if(s[i]=='1') teama++;
                if(s[i+1]=='1') teamb++;
                if(teama > teamb)
                {
                    enter=1;
                    cout<<"TEAM-A"<<" "<<i+2<<endl;
                    break;
                }
                if(teamb > teama)
                {
                    enter=1;
                    cout<<"TEAM-B"<<" "<<i+2<<endl;
                    break;
                }
            }
        }
        
        if(!enter)
        {
            cout<<"TIE"<<endl;
        }
        
        
    }
	return 0;
}

