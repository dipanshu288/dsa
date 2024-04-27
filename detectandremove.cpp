/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
Node* detect(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    Node* slow = head->next;
    Node* fast = head->next->next;

    while (fast != nullptr && fast->next != nullptr) {
        if (slow == fast)
            return slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    return nullptr;
}
Node* getstarting(Node* head) {
    Node* intersection = detect(head);
    if (intersection == nullptr)
        return nullptr;

    
    if(intersection==NULL){
        return NULL;
    }
    Node*slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;

    }
    return slow;
}

Node *removeLoop(Node *head) {
    if(head==NULL){
        return NULL ;
    }
    Node* startnode=getstarting(head);
    if(startnode==NULL){
        return head;
    }
    Node*temp=startnode;
    while(temp->next!=startnode){
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}
