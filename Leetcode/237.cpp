#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *node->next;
    }
};

int main(){
    ListNode l1 = ListNode(1);
    ListNode l2 = ListNode(2);
    ListNode l3 = ListNode(3);
    ListNode l4 = ListNode(4);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;

    Solution s;
    s.deleteNode(&l3);
    ListNode* temp = &l1;
    while(temp!=NULL){
        cout << temp->val << endl;
        temp = temp->next;
    }
    return 0;
}
