//ref: https://leetcode.com/problems/add-two-numbers/
/**
gcc addTwoNumbers.c -o t1
./t1
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.
 */
#include <gtest/gtest.h>

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode*p1 = l1;
    struct ListNode*p2 = l2;
    struct ListNode* q=(struct ListNode*)malloc(sizeof(struct ListNode));
    q->next = NULL;
    struct ListNode* c= q;
    struct ListNode* q2;
    int flag = 0;
    while(p1 || p2 || flag){
        if( q == NULL){
            q = (struct ListNode*)malloc(sizeof(struct ListNode));
            q2->next = q;
            q->next = NULL;
        }
        int v = 0;
        if(p1 && p2){
            v = p1->val + p2->val + flag;
        } else if(p1){
            v = p1->val + flag;
        } else if(p2){
            v = p2->val + flag;
        } else {
            v = flag;
        }
        if( v >= 10 ) {
            flag = v / 10;
            q->val = v % 10;
        } else {
            q->val = v;
            flag = 0;
        }
        q2 = q;
        q = q->next;
        if( p1) p1 = p1->next;
        if( p2) p2 = p2->next;
    }
    return c;
}

void printNodes(struct ListNode* l1){
    struct ListNode* p = l1;
    while(p !=  NULL){
        printf("%d", p->val);
        p = p->next;
    }
    printf("\n");
}

struct ListNode* initWithNumber(int val){
    int n = val;
    struct ListNode *a = NULL;
    struct ListNode *p1 = a;
    do{
        struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next = NULL;
        p->val = n % 10;
        if( p1 == NULL ){
            a = p;
            p1 = p;
        } else {
            p1->next = p;
            p1 = p;
        }
        n = n / 10;
    }while(n>0);
    return a;
}
TEST(addTwoNumbers, digit_1) {
    struct ListNode *a = initWithNumber(5);
    struct ListNode *b = initWithNumber(5);
    struct ListNode* c = addTwoNumbers(a,b);
    EXPECT_EQ(c->val, 0);
    EXPECT_EQ(c->next->val, 1);
}

TEST(addTwoNumbers, digit_2) {
    struct ListNode *a = initWithNumber(99);
    struct ListNode *b = initWithNumber(1);
    struct ListNode* c = addTwoNumbers(a,b);
    EXPECT_EQ(c->val, 0);
    EXPECT_EQ(c->next->val, 0);
    EXPECT_EQ(c->next->next->val, 1);
}

TEST(addTwoNumbers, digit_3) {
    struct ListNode *a = initWithNumber(342);
    struct ListNode *b = initWithNumber(465);
    struct ListNode* c = addTwoNumbers(a,b);
    EXPECT_EQ(c->val, 7);
    EXPECT_EQ(c->next->val, 0);
    EXPECT_EQ(c->next->next->val, 8);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
