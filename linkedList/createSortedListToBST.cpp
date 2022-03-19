
class Solution {
public:
    
    ListNode *m(ListNode *head){
        ListNode *fast=head;
        ListNode *slow=head;
        ListNode *prev=head;
        while(fast!=NULL and fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(prev!=NULL)
            prev->next=NULL;
        return slow;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode *mid=m(head);
        TreeNode *root=new TreeNode(mid->val);
        
        if(head==mid)
            return root;
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(mid->next);
        return root;
    }
};
