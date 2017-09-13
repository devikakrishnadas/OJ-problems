#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin,V.end

using namespace std;


struct TrieNode
{
     struct TrieNode *children[200];
     bool isLeaf;
     char l;
};

TrieNode *root=new TrieNode;
TrieNode *t=NULL;
vector<TrieNode*>AP;
void insert(char c)
{
	
        t=root; 
	bool in=0;
//	TrieNode *t=NULL;
        for(int i=0;i<AP.size();i++)
        {
                TrieNode *P=new TrieNode;
                for(int j='a';j<'a'+26;j++)
                {
                        P->children[j]=NULL;
                }
                P->l=c;
		if(AP[i]->children[c]==NULL)
                {
			AP[i]->children[c]=P;
			AP[i]=P;
		}
		else AP[i]=AP[i]->children[c];
                
        }

	if(t->children[c]!=NULL)
	{
		AP.pb(t->children[c]);
		in=1;
	}
	else
	{
		TrieNode *P=new TrieNode;
                for(int i='a';i<'a'+26;i++)
                {
                        P->children[i]=NULL;
                }
		P->l=c;
		t->children[c]=P;
		AP.pb(P);
		
	}

/////////////////////////////////////////////
       /* for(int i=0;i<strlen(S);i++)
        {
                TrieNode *P=new TrieNode;
                t->isLeaf=0;
                for(int j='a';j<'a'+26;j++)
                        P->children[j]=NULL;
                if(t->children[S[i]]!=NULL)
                {
                        t=t->children[S[i]];
//                      cout<<S[i]<<" ";
                }
                else if(i==strlen(S)-1)
                {
                        t->children[S[i]]=P;
//                      cout<<S[i]<<" ";
                        t=P;
                        t->isLeaf=1;
                }

                 else
                 {
                        t->children[S[i]]=P;
                        t=t->children[S[i]];
                 }
//               cout<<S[i]-'a'<<" ";
        }*/

}
char c;
int main()
{
	clock_t begin = clock();
	
	for(int i='a';i<'a'+26;i++)
	{
		root->children[i]=NULL;
	}
	char S[100001];
	int T;
	cin>>T;
	cin>>S;
	for(int i=0;i<strlen(S);i++)
	{
		insert(S[i]);
	}
	//int T;
	//cin>>T;
	while(T--)
	{
		cin>>S;
		int kk=0;
		bool enter =1;
		t=root;
      	   	while(kk<strlen(S))
        	{
        	        enter=0;
	             /*   for(int i=0;i<26;i++)
                	{
        	                if(t->children[i+'a']!=NULL)
	                        {
                                	enter=1;
                        	        cout<<(char)(i+'a')<<" ";
                	        }
        	        }
	                cout<<endl;
	                if(!enter) break;*/
                	c=S[kk];
			if(t->children[c]==NULL)
			{
				cout<<"INVALID"<<endl;
				goto kkkk;
			}
	                t=t->children[c];
			kk++;
        	}
		cout<<"VALID"<<endl;
		kkkk:continue;
	}
	clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout<<"time = "<<elapsed_secs<<endl;

	return 0;
}
