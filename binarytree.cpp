#include<iostream>
using namespace std;
template<typename T>
class node{
    public:
        T data;
        node* left;
        node* right;
        node( T val){
            data=val;
            left=right=nullptr;
        }
};
template<typename T>
class binT{
    private:
        node<T>* root;
        void preorder(node<T>*root){
            if(root==nullptr){
                return;
            }
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }
        void postorder(node<T>*root){
            if(root==nullptr){
                return;
            }
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
        }
        void inorder(node<T>*root){
            if(root==nullptr){
                return;
            }
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);

        }
        node<T>* insertElements(T val, node<T>*root){
            if(root==nullptr){
                return new node<T>(val);
            }
            else if(val>root->data){
                root->right=insertElements(val,root->right);
            }
            else if(val<root->data){
                root->left=insertElements(val,root->left);
            }
            else{
                cout<<"elements cant be inserted";
            }
            return root;
        }
        T minfinder(node<T>*root){
            if(root->left==nullptr){
                return root->data;
            }
            return minfinder(root->left);
        }
        T maxfinder(node<T>*root){
            if(root->right==nullptr){
                return root->data;
            }
            return maxfinder(root->right);
        }
    public:
        
        binT(){
            root=nullptr;
        }

        ~binT(){
            delete root;
        }
        void display(){
            int n;
            cout<<"1.inorder"<<"\n2.preorder"<<"\n3.postorder"<<"\n4.all"<<endl;
            cin>>n;
            if(n==1){
                cout<<"inorder:";
                inorder(this->root);
            }else if(n==2){
                cout<<"preorder:";
                preorder(this->root);
            }else if(n==3){
                cout<<"postorder:";
                postorder(this->root);
            }else if(n==4){
                cout<<"inorder:";
                inorder(this->root);
                cout<<"preorder:";
                preorder(this->root);
                cout<<"postorder:";
                postorder(this->root);
            }else{
                cout<<"invalid request";
            }
            cout<<endl;
        }
        void insert(T val){
           this->root=insertElements(val,this->root);
        }
        void findmin(){
            cout<<"miniimum elements:"<<minfinder(this->root);
            
        }
        void findmax(){
            cout<<"maximum elements:"<<maxfinder(this->root);
        }

};

int main(){
    cout<<"helo";
    binT<int> bin1;
    int choice;
    int n;
    while(true){
        cout<<"\n what do you want?"<<endl;
        cout<<"1.insert element."<<"\n2.display elements"<<"\n3.find minimum"<<"\n4.find maximum11"<<endl;
        cin>>choice;
        if(choice==1){
            cout<<"enter your element:";
            cin>>n;
            bin1.insert(n);
        }
        else if(choice==2){
            bin1.display();
        }
        else if(choice==3){
            bin1.findmin();
        }
        else if(choice==4){
            bin1.findmax();
        }
        else if(choice==5){ 
            break;
        }
    }
}