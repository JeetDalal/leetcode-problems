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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool isCarry=false;
        vector<int> v;
        while(l1!=NULL && l2!=NULL){
            if(l1->next==NULL && l2->next == NULL){
                if(l1->val + l2->val + (isCarry?1:0)>=10){
                    v.push_back(l1->val + l2->val + (isCarry?1:0)-10);
                    v.push_back(1);
                }else{
                    v.push_back(l1->val + l2->val + (isCarry?1:0));
                }
            }
           else if(l1->val + l2->val + (isCarry?1:0)>=10){
                v.push_back(l1->val + l2->val + (isCarry?1:0) - 10);
                isCarry = true;
            }else{
                v.push_back(l1->val + l2->val + (isCarry?1:0));
               isCarry=false;
            }
            l1=l1->next;
            l2=l2->next;
        }
        if(l1==NULL){
            while(l2!=NULL){
                if(isCarry){
                    if(l2->val + 1 >=10){
                       v.push_back(l2->val +1-10);
                        if(l2->next == NULL){
                            v.push_back(1);
                        }
                        isCarry=true;
                    }else{
                        v.push_back(l2->val+1);
                        isCarry=false;
                    }
                }else{
                    v.push_back(l2->val);
                }
                l2=l2->next;
            }
        }
        if(l2==NULL){
            while(l1!=NULL){
                if(isCarry){
                    if(l1->val + 1 >=10){
                       v.push_back(l1->val +1-10);
                        if(l1->next == NULL){
                            v.push_back(1);
                        }
                        isCarry=true;
                    }else{
                        v.push_back(l1->val+1);
                        isCarry=false;
                    }
                }else{
                    v.push_back(l1->val);
                }
                l1=l1->next;
            }
        }
        ListNode* temp = new ListNode(v[0]);
        ListNode* head = new ListNode();
        head = temp;
        for(int i=1;i<v.size();i++){
            
            ListNode* nn = new ListNode(v[i]);
            head->next = nn;
            head = nn;
        }
        return temp;
    }
};