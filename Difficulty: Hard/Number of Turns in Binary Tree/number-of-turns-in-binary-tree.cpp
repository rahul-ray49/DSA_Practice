/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    Node* helper(Node* root,int p,int q){
        if(root==NULL) return NULL;
        if(root->data ==p || root->data ==q){
            return root;
        }
        Node* lt=NULL;
        Node* rt=NULL;
        lt=helper(root->left,p,q);
        rt=helper(root->right,p,q);
        if(lt!=NULL && rt!=NULL) return root;
        if(lt == NULL && rt!=NULL) return rt;
        if(lt!=NULL && rt ==NULL) return lt;
        return NULL;
    }
    void counter(Node* root,int p,int direction,int turns,int& turn){
        if(root==NULL) return;
        if(root->data==p){
            turn=turns;
            return;
        }
        if(direction!=-1){
            int newDirection=-1;
            counter(root->left,p,newDirection,turns+1,turn);
        }
        else{
            if(direction==-1){
                counter(root->left,p,direction,turns,turn);
            }
        }
        if(direction!=1){
            int newDirection=1;
            counter(root->right,p,newDirection,turns+1,turn);
        }
        else{
            if(direction==1){
                counter(root->right,p,direction,turns,turn);
            }
        }
    }
    int numberOfTurns(Node* root, int p, int q) {
        // code here
        Node* LCA=helper(root,p,q);
        int turn1=0;
        int turn2=0;
        counter(LCA,p,0,0,turn1);
        counter(LCA,q,0,0,turn2);
        int ans= turn1+turn2-1;
        return ans == 0 ? -1 : ans;

        
    }
};