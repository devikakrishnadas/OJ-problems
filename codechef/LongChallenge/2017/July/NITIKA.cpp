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
	/*ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);*/
    int t;
    cin>>t;
    while(t--)
    {
        
        char name[1000023];
        scanf(" %[^\t\n]s",name);
        int n=strlen(name);
        //pf("%s\n",name);
        char fin[100023];
        int cnt=1;
        for(int i=0;i<n;i++)
        {
            if(name[i]==' ')
            {
                cnt++;
            }
        }
        int j=0;
        int f=1;
        if(cnt>1)
        {
            fin[0]=toupper(name[0]);
            fin[1]='.';
            fin[2]=' ';
            j=3;
            cnt--;
            for(int i=0;i<n;i++)
            {
                if(name[i]==' ')
                {
                    f=i+1;
                    break;
                }
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                if(i==0)
                {
                    name[i]=toupper(name[i]);
                }
                else name[i]=tolower(name[i]);
            }
            cout<<name<<endl;
            continue;
        }
        int start=0;
        for(int i=f;i<n;i++)
        {
            if(name[i-1]==' ' && cnt>1)
            {
                //cout<<"enter"<<endl;
                fin[j]=toupper(name[i]);
                fin[j+1]='.';
                fin[j+2]=' ';
                j+=3;
                cnt--;
            }
            else if(cnt==1 && name[i-1]==' ')
            {
                start=i-1;
                break;
            }
        }
        for(int i=start;i<n;i++)
        {
            if(name[i]==' ') { start+=1; continue;}
            //cout<<name[i]<<" ";
            if(i==start)
            {
                fin[j]=toupper(name[i]);
                j++;
            }
            else
            {
                fin[j]=tolower(name[i]);
                j++;
            }
        }
        fin[j]='\0';
        cout<<fin<<endl;
    }
	return 0;
}

