#include <iostream>
#include "test_runner.h"

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

inline bool operator ==(ListNode l1, ListNode l2) {
    return l1.val == l2.val;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode();
        
        ListNode* iterateMine = dummyHead;
        
        int buffer = 0;
        
        while (l1 && l2) {
            ListNode* temp = new ListNode((l1->val + l2->val + buffer) % 10);
            iterateMine->next = temp;
            buffer = (l1->val + l2->val + buffer) / 10;
            iterateMine = iterateMine->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1) {
          ListNode* temp = new ListNode((l1->val + buffer) % 10);
            iterateMine->next = temp;
            buffer = (l1->val + buffer) / 10;
            iterateMine = iterateMine->next;
            l1 = l1->next;
        }
        
        while (l2) {
          ListNode* temp = new ListNode((l2->val + buffer) % 10);
            iterateMine->next = temp;
            buffer = (l2->val + buffer) / 10;
            iterateMine = iterateMine->next;
            l2 = l2->next;
        }
        
        if (buffer != 0) {
            ListNode* temp = new ListNode(buffer);
            iterateMine->next = temp;
        }
        
        return dummyHead->next;
    }

void Test() {
    ListNode* l1Head = new ListNode(9);
    ListNode* l1One = new ListNode(9);
    ListNode* l1Two = new ListNode(9);
    ListNode* l1Three = new ListNode(9);
    ListNode* l1Four = new ListNode(9);
    ListNode* l1Five = new ListNode(9);
    ListNode* l1Six = new ListNode(9);
    
    l1Head->next = l1One;
    l1One->next = l1Two;
    l1Two->next = l1Three;
    l1Three->next = l1Four;
    l1Four->next = l1Five;
    l1Five->next = l1Six;
    
    ListNode* l2Head = new ListNode(9);
    ListNode* l2One = new ListNode(9);
    ListNode* l2Two = new ListNode(9);
    ListNode* l2Three = new ListNode(9);
    
    l2Head->next = l2One;
    l2One->next = l2Two;
    l2Two->next = l2Three;
    
    ListNode* l3Head = new ListNode(8);
    ListNode* l3One = new ListNode(9);
    ListNode* l3Two = new ListNode(9);
    ListNode* l3Three = new ListNode(9);
    ListNode* l3Four = new ListNode(0);
    ListNode* l3Five = new ListNode(0);
    ListNode* l3Six = new ListNode(0);
    ListNode* l3Seven = new ListNode(1);
    
    l3Head->next = l3One;
    l3One->next = l3Two;
    l3Two->next = l3Three;
    l3Three->next = l3Four;
    l3Four->next = l3Five;
    l3Five->next = l3Six;
    l3Six->next = l3Seven;
    
    ASSERT_EQUAL(addTwoNumbers(l1Head, l2Head), l3Head);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, Test);
    return 0;
}
