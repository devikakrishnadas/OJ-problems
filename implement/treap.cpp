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


struct node
{
    int size, priority, key;
    node *left, *right;

    node(int key)
    {
        this -> key = key;
        priority = rand();
        size = 1;
        left = NULL;
        right = NULL;
    }
    
    void setLeft(node *n)
    {
        left = n;
        calcSize();
    }

    void setRight(node *n)
    {
        right = n;
        calcSize();
    }
    void calcSize()
    {
        size = 1;
        if(left != NULL) size += left -> size;
        if(right != NULL) size += right -> size;
    }
};


typedef node* nodeP ;
pair <nodeP, nodeP> split(nodeP root, int key)
{
    if(root == NULL) 
    {
        return pair<nodeP,nodeP>(NULL,NULL);
    }

    if(root -> key < key)
    {
        pair <nodeP, nodeP> p = split(root -> right, key);
        root -> setRight(p.ff);
        return mp(root, p.ss);
    }
    else
    {
        pair <nodeP, nodeP> p = split(root -> left, key);
        root -> setLeft(p.ss);
        return mp(p.ff,root);
    }
}

nodeP merge(nodeP a, nodeP b)
{
    if(a == NULL) return b;
    if(b == NULL) return a;

    if(a -> priority > b -> priority)
    {
        a->setRight(merge(a -> right, b));
        return a;
    }
    else
    {
        b->setLeft(merge(a, b -> left));
        return b;
    }
}

nodeP insert(nodeP root, nodeP n)
{
    if(root == NULL) return n;
    if( root -> key == n -> key)
    {
        return root;
    }
    if(n -> priority > root -> priority)
    {
        pair <nodeP, nodeP> p = split(root, n -> key);
        n -> setLeft(p.ff);
        n -> setRight(p.ss);
        return n;
    }

    if(root -> key < n -> key)
    {
        root -> setRight(insert(root -> right, n));
    }
    else 
    {
        root -> setLeft(insert(root -> left, n));
    }
    return root;
}

void levelwise(nodeP root)
{
    queue<nodeP>a;
    a.push(root);
    nodeP temp=NULL;
    a.push(temp);
    while(!a.empty())
    {
        nodeP p =a.front();
        if(p==NULL) 
        {
            a.pop();
            cout<<endl;
            if(a.size())
                a.push(temp);
            continue;
        }
        cout<<p -> key<<" ";
        a.pop();
        if(p->left!=NULL) a.push(p->left);
        if(p->right!=NULL) a.push(p->right);
    }
    cout<<endl;
}
nodeP erase(nodeP root, int key)
{
    if(root == NULL) return NULL;
    if(root -> key == key)
    {
        nodeP p = merge(root -> left, root -> right);
        delete root;
        return p;
    }

    if(key > root -> key)
    {
        root -> setRight(erase(root->right, key));
    }
    else
    {
        root -> setLeft(erase(root->left, key));
    }
    return root;
}
nodeP kthNode(nodeP root, int k)
{
    int lsize=0;
    if(root == NULL) return 0;
    if(root -> left != NULL)
    {
        lsize = root -> left -> size;
    }
    if(lsize + 1 == k)
    {
        return root;
    }
    else if(lsize >= k) 
    {
        return kthNode( root -> left, k);
    }
    
    else 
    {
        return kthNode(root -> right, k - lsize - 1);
    }
}

int countLessThan( nodeP root, int key)
{
    if(root == NULL) return 0;
//    cout<<"rootval "<<root->key<<endl;
//    if(root -> left != NULL) cout<<"leftsize"<<root->left->size<<endl;
//    if(root -> right != NULL) cout<<"rightsize"<<root->right->size<<endl;
    if(key <= root -> key) 
    {
//        cout<<"r1"<<endl;
        return countLessThan(root -> left, key);
    }
    int lsize = 0;
    if(root -> left != NULL)
    {
//        cout<<"r2"<<endl;
        lsize = root -> left -> size;
    }
//    cout<<"r3 lsize "<<lsize<<endl;
    return (lsize + 1 + countLessThan(root -> right, key));
}

bool find(nodeP root, int key)
{
    if(root == NULL) return 0;
    
    if(key == root -> key)
    {
        return 1;
    }

    if(key < root->key)
    {
        return find(root->left,key);
    }

    return find(root -> right,key);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    srand(time(NULL));
    int q;
    cin>>q;
    nodeP root = NULL;
    bool enter=0;
    while(q--)
    {
        char c;
        int x;
        cin>>c>>x;
        if( c == 'I')
        {
            nodeP p =new node(x);
            if(root == NULL)
            {
                root = new node(x);
                enter=1;
            }
            else
            {
                nodeP troot = root;
                if(!find(troot,x))
                {
                    troot = root;
                    root = insert(troot, p);
                }
            }
            nodeP temp=root;
//            levelwise(temp);
        }
        else if( c == 'D')
        {
            if(root == NULL) continue;
            nodeP troot = root;
            if(find(troot,x))
            {
                if(root->size == 1)
                {
                    root = NULL;
                }
                troot = root;
                root = erase(troot, x);
            }
        }
        else if(c == 'K')
        {
            if(root == NULL)
            {
                cout<<"invalid"<<endl;
            }
            else if(x > root -> size)
            {
                cout<<"invalid"<<endl;
            }
            else
            {
                nodeP troot = root;
                nodeP ans = kthNode(troot, x);
                cout<<ans -> key<<endl;
            }
        }
        else
        {
            nodeP troot = root;
            cout<<countLessThan(troot, x)<<endl;
        }
    }
	return 0;
}

