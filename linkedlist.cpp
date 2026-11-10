#include<iostream>
using namespace std;
class Node {
    public:
        int data;
        Node*next;
        Node(int val){
            data=val;
            next=NULL;
        }

};
class LLADT{
    public:
        Node* head;
        LLADT(){
            head=NULL;
        }
        int addToHead(int val){
            Node* N =new node(val);
            if(head==NULL){
                head=N;
            }
            if(head!=NULL){
                N=head;
                head=N;
            }

        }
        int addToTail(int val){
            Node* N =new node(val);
            Node* temp=head;
            if(head==NULL){
                head=N;
            }
            else{

                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=N;
            }
        }

    
}
int main(){
    LLADT l1;
    //add to linked list
    int input;
    int n;//number of elements 
    int 
    void add1(int val){
        l1.addToHead(val);
    }
    void add2(int val){
        l1.addToTail(val);
    }
    while(input!=4){
        cin>>input;
        if(input==1){
            cout<<"entere number of elements you want to emter "<<endl;
            cin>>n;
            for(int i=0;i<=n;i++){
                cin>>
            }

        }
    }
}