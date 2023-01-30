#include <iostream>
#include "ListNode.h"
#define WITHOUT_RET

   static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr || l2 == nullptr){

#ifdef WITHOUT_RET
        auto list_to_copy = l1 ? l1 : l2;
            if (list_to_copy == nullptr){
                return nullptr;
            }
            return list_to_copy;
#else
            auto list_to_copy = l1 ? l1 : l2;
            if (list_to_copy == nullptr){
                return nullptr;
            }
            auto ret = new ListNode(list_to_copy->val);
            auto new_node = ret;
            for (auto next = list_to_copy->next; next != nullptr; next = next->next){
                new_node->next = new ListNode(next->val);
                new_node = new_node->next;
            }
           return ret;
#endif
        }
        else{
            auto nextl1 = l1;
            auto nextl2 = l2;
            auto val = l1->val;
            if (l1->val <= l2->val){
                val = l1->val;
                nextl1 = l1->next;
            }
            else{
                val = l2->val;
                nextl2 = l2->next;
            }
            auto next = mergeTwoLists(nextl1, nextl2);
            auto newNode = new ListNode(val);
            newNode->next = next;
            return newNode;
        }
    }

int main() {
    ListNode n1(1);
    n1.next = new ListNode(2);
    n1.next->next = new ListNode(4);
    ListNode n2(1);
    n2.next = new ListNode(5);
    n2.next->next = new ListNode(8);
    auto res = mergeTwoLists(nullptr,&n2 );
    while ( res != nullptr){
        std::cout<< res->val << " ";
        res = res->next;

    }
    std::cout << std::endl<< "Hello, World!" ;
    return 0;
}
