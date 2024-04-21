/****************************************************************

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
        

*****************************************************************/
void reverse(Node* &head,Node* &curr,Node* &prev){
    if(curr==NULL){
        head=prev;
        return ;
    }
    Node* forward=curr->next;
    reverse(head,forward,curr);
    curr->next=prev;
}
Node* reverseLinkedList(Node *head)
{
    if(head==NULL ||head->next==NULL){
        return head;
    }
    Node* curr=head;
    Node* prev=NULL;
    Node*forward=NULL;
    reverse(head,curr,prev);
    return head;

}
