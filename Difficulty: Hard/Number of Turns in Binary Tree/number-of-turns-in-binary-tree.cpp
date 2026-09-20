class Solution {
  public:
    bool nodePathConstruction(Node* node, string path, string& rpath, int val) {
        if(!node)
            return false; 

        if(node->data == val) {
            rpath = path;
            return true;
        }


        if (nodePathConstruction(node->left, path + "L", rpath, val)) {
            return true;
        }

        if (nodePathConstruction(node->right, path + "R", rpath, val)) {
            return true;
        }

        return false;
    }
    int numberOfTurns(Node* root, int p, int q) {
        string ppath = "", qpath = "";

        nodePathConstruction(root, "", ppath, p);
        nodePathConstruction(root, "", qpath, q);

        int i = 0, j = 0, turns = 0;
        while(i < ppath.size() && j < qpath.size() && ppath[i] == qpath[j]) {
            i++, j++;
        }

        if(i != ppath.size() && j != qpath.size())
            turns++;

        for(int in = i; in + 1 < ppath.size(); in++) {
            if(ppath[in] != ppath[in+1])
                turns++;
        }

        for(int in = j; in + 1 < qpath.size(); in++) {
            if(qpath[in] != qpath[in+1])
                turns++;
        }

        return turns ? turns : -1;
    }
};
//GFG POTD solution for 22 August
