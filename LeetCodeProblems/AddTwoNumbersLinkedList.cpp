#include <vector>
#include <iostream>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};
class AddTwoNumbersLinkedList
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	/* LeetCode Problem 2: Add Two Numbers
	* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
	* Input : [2,4,3][5,6,4]
	* Output : [7,0,8]
	*/

            string s1 = "", s2 = "", sum = "";
            ListNode* result = NULL;
            while (l1 != NULL)
            {
                s1 += to_string(l1->val);
                l1 = l1->next;
            }
            //reverse(s1.begin(), s1.end());
            while (l2 != NULL)
            {
                s2 += to_string(l2->val);
                l2 = l2->next;
            }
            //reverse(s2.begin(), s2.end()); 
            int c = 0;
            int len1 = s1.length();
            int len2 = s2.length();
            int it = len1 > len2 ? len1 : len2;
            for (int i = 0;i < it;i++)
            {
                int rem = 0;
                if (i < len1 && i < len2)
                {
                    int va = s1[i] + s2[i] + c - 48 - 48;
                    //cout<<va<<" "<<s1[i]<<" "<<s2[i]<<" ";
                    c = 0;
                    if (va > 9)
                    {
                        c = 1;
                        va = va % 10;
                    }
                    sum += to_string(va);
                }
                if (i < len1 && i >= len2)
                {
                    int va = s1[i] + c - 48;
                    c = 0;
                    if (va > 9)
                    {
                        c = 1;
                        va = va % 10;
                    }
                    sum += to_string(va);
                }
                if (i >= len1 && i < len2)
                {
                    int va = s2[i] + c - 48;
                    c = 0;
                    if (va > 9)
                    {
                        c = 1;
                        va = va % 10;
                    }
                    sum += to_string(va);
                }
                // cout<<sum<<" ";
            }
            if (c == 1)
                sum += '1';
            for (int i = sum.length() - 1;i >= 0;i--)
            {
                ListNode* res = new ListNode();
                res->val = sum[i] - 48;
                res->next = result;
                result = res;
            }
            return result;
	}
    public:
    // Pushing item into Linked List
    void push(ListNode** head_ref, int new_data)
    {
        /* 1. allocate node */
        ListNode* new_node = new ListNode();

        /* 2. put in the data */
        new_node->val = new_data;

        /* 3. Make next of new node as head */
        new_node->next = (*head_ref);

        /* 4. move the head to point to the new node */
        (*head_ref) = new_node;
    }
public :
    //Iterating Through Linked List to Display
    void Display(ListNode* item)
    {
        while (item != NULL)
        {
            cout<< item->val;
            item = item->next;
        }
    }
};
