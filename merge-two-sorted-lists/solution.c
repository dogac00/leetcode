
/*
  LeetCode: https://leetcode.com/problems/merge-two-sorted-lists
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* create_listnode(int val) {
    struct ListNode* ln = malloc(sizeof(struct ListNode));
    if (!ln)
        return NULL;
    ln->val = val;
    ln->next = NULL;
    return ln;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* merged_list_before_head = create_listnode(0);
    struct ListNode* merged_curr = merged_list_before_head;

    struct ListNode* cur1 = list1;
    struct ListNode* cur2 = list2;
    while (cur1 != NULL || cur2 != NULL) {
        if (cur1 == NULL) {
            struct ListNode* listnode_to_append = create_listnode(cur2->val);
            merged_curr->next = listnode_to_append;
            merged_curr = merged_curr->next;
            cur2 = cur2->next;
        }
        else if (cur2 == NULL) {
            struct ListNode* listnode_to_append = create_listnode(cur1->val);
            merged_curr->next = listnode_to_append;
            merged_curr = merged_curr->next;
            cur1 = cur1->next;
        }
        else if (cur1->val < cur2->val) {
            struct ListNode* listnode_to_append = create_listnode(cur1->val);
            merged_curr->next = listnode_to_append;
            merged_curr = merged_curr->next;
            cur1 = cur1->next;
        }
        else {
            struct ListNode* listnode_to_append = create_listnode(cur2->val);
            merged_curr->next = listnode_to_append;
            merged_curr = merged_curr->next;
            cur2 = cur2->next;
        }
    }
    
    struct ListNode* merged_head = merged_list_before_head->next;
    free(merged_list_before_head);
    return merged_head;
}
