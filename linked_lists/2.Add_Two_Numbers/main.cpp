#include <iostream>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
  ListNode *dummy = new ListNode();
  ListNode *current = dummy;

  int carry = 0;
  while (l1 != NULL || l2 != NULL)
  {
    int val = carry;
    if (l1)
    {
      val += l1->val;
      l1 = l1->next;
    }

    if (l2)
    {
      val += l2->val;
      l2 = l2->next;
    }

    carry = val / 10;
    val %= 10;

    current->next = new ListNode(val);

    current = current->next;
  }

  if (carry != 0)
  {
    ListNode *remain_node = new ListNode(carry);

    current->next = remain_node;
  }

  return dummy->next;
}

int main()
{
}

using namespace std;