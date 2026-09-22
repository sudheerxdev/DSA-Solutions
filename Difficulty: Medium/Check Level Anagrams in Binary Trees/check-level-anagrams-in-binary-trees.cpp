/* Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void bfs(Node *node,vector<vector<int>>&a)
    {
        if(!node) return;
        queue<Node*>q;
        q.push(node);
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>t;
            while(sz--)
            {
                Node *u=q.front(); q.pop();
                int x=u->data;
                t.push_back(x);

                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);

            }
            sort(t.begin(),t.end());
            a.push_back(t);
        }
        return ;
    }
    bool areAnagrams(Node* root1, Node* root2) {

        vector<vector<int>>a,b;
        bfs(root1,a);
        bfs(root2,b);
        if(a.size()!=b.size()) return false;
        for(int i=0;i<a.size();i++)
        {
            if(a[i].size()!=b[i].size()) return false;
            for(int j=0;j<a[i].size();j++)
            {
                if(a[i][j]!=b[i][j]) return false;
            }
        }
        return true;

    }
};

//GFG POTD solution for 21 September
