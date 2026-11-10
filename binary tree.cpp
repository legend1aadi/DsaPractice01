class Node {
    int data;
    Node*left;
    Node*right;
    Node(int val){
        data=val;
        left=right=NULL;

    }
};
static int idx=-1;
Node* buildTree(int preOrder[]){
    idx++;
    if(preOrder[idx]==-1){
        return NULL;
    }
    Node*root=new Node(preOrder[idx]);
    Node*left=buildTree(preOrder);
    Node*right=buildTree(preOrder);
    return root;
};