/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode *reversel(ListNode *temp){
        if(!temp or !temp->next){
            return temp;
        }
        ListNode *revhead=reversel(temp->next);
        temp->next->next=temp;
        temp->next=NULL;
        return revhead;
    }
    
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        ListNode *temp=head;
        ListNode *p=reversel(temp);
        stack<int>st;
        while(p){
            if(st.empty()){
                st.push(p->val);
                ans.push_back(0);
                p=p->next;
            }
            else if(p->val<st.top()){
                ans.push_back(st.top());
                st.push(p->val);
                p=p->next;
            }
            else{
                st.pop();
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
