/**=
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode*temp = head;
        vector<int> vec;
        while(temp!=NULL){
            vec.push_back(temp->val);
            temp = temp->next;
        }
        for(int i=0;i<vec.size();i++){
            int sum = 0;
            for(int j=i;j<vec.size();j++){
                sum = sum + vec[j];
                if(sum==0){
                    int k = i;
                    while(k<=j){
                        vec[k]=2000;
                        k++;
                    }
                    i=j;
                }
            }
        }
        ListNode*ans = new ListNode(2);
        ListNode*root = ans;
        for(auto i :vec){
            if(i!=2000){
                root->next = new ListNode(i);
                root = root->next;
            }
        }
        return ans->next;
    }
};
// [1,-1,1,0,-1,-3]
// [1,-1,1,-1]
// [1,2,3,-3,-2]
// [1,2,3,-3,4]
// [1,2,-3,3,1,2,4,4,565,5,5,2,-2,5,-5]