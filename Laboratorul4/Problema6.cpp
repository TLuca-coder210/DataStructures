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
 struct ComparaNoduri {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; 
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        priority_queue<ListNode*, vector<ListNode*>, ComparaNoduri> heap;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                heap.push(lists[i]);
            }
        }
        while (!heap.empty()) {
            ListNode* node = heap.top(); 
            heap.pop(); 
            if (node->next != nullptr) {
                heap.push(node->next);
            }
            if (head == nullptr) {
                head = node;
                tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        return head;
    }
};