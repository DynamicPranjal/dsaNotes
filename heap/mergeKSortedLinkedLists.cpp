class cmp{
    public:
    bool operator()(Node *a,Node *b){
          return a->data>b->data;
    }  
};

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *A[], int k)
    {
           // Your code here
           priority_queue<Node*,vector<Node*>,cmp>q;
           Node *dummy=new Node(-1);
           Node *tail=dummy;
           for(int i=0;i<k;i++){
               if(A[i]!=NULL)
                    q.push(A[i]);
           }
           while(!q.empty()){
               Node *temp=q.top();
               tail->next=temp;
               tail=temp;
               q.pop();
               if(temp->next!=NULL)
                    q.push(temp->next);
           }
           return dummy->next;
    }
};
