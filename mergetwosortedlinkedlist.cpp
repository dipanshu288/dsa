/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
void populate(Node*&tail,Node* curr){
    tail->next=curr;
    tail=curr;
}

Node* sortList(Node *head){
    Node* zerohead=new Node(-1);
    Node* zerotail=zerohead;
    Node* onehead=new Node(-1);
    Node* onetail=onehead;
    Node*twohead=new Node(-1);
    Node* twotail=twohead;
    Node* curr=head;
    // Create seprate list 0s,1s and 2s
    while(curr!=NULL){
        int value=curr->data;
        if(value==0){
            populate(zerotail,curr);
        }
        else if(value==1){
            populate(onetail,curr);
        }
        else if(value==2){
            populate(twotail,curr);
        }
        curr=curr->next;
    }
    //Merge the seprate list
    if(onehead->next!=NULL){
        zerotail->next=onehead->next;
    }
    else{
        zerotail=twohead->next;
    }
    onetail->next=twohead->next;
    twotail->next=NULL;
    //setup head
    head=zerohead->next;
    delete zerohead;
    delete onehead;
    delete twohead;

    return head;
}
