//You are given two non-empty linked lists representing two non-negative integers. 
//The digits are stored in reverse order and each of their nodes contain a single digit. 
//Add the two numbers and return it as a linked list.

//You may assume the two numbers do not contain any leading zero, except the number 0 itself.

//给定两个非空链表，表示两个非负int数
//数字倒序存储，每个节点存一个数
//两数相加，将结果以以链表形式返回

//假设两个数不包含前置0，除了该数是0本身

// Example:
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output : 7 -> 0 -> 8
// Explanation : 342 + 465 = 807.

#include <vector>
#include <iostream>
#include <sstream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	int carry = 0;

	const auto head = new ListNode(0);
	auto p = head;

	//遍历两个列表
	while (l1 != nullptr || l2 != nullptr)
	{
		const int lhs = l1 != nullptr ? l1->val : 0;
		const int rhs = l2 != nullptr ? l2->val : 0;


		const int sum = lhs + rhs + carry;
		carry = sum / 10;

		p->next = new ListNode(sum % 10);
		p = p->next;

		if (l1 != nullptr)
			l1 = l1->next;

		if (l2 != nullptr)
			l2 = l2->next;
	}

	if (carry > 0)
	{
		p->next = new ListNode(carry);
		p = p->next;
	}

	return head->next;
}

ListNode* CreateListNode(std::vector<int>& array)
{
	auto head = new ListNode(0);
	auto p = head;

	for (auto value : array)
	{
		p->next = new ListNode(value);
		p = p->next;
	}

	return head->next;
}

std::string ListNodeToString(ListNode* list_node)
{
	std::ostringstream str;
	while (list_node != nullptr)
	{
		str << list_node->val << "->";

		list_node = list_node->next;
	}

	str << "null";

	return str.str();
}

int main()
{
	const auto lhs = new std::vector<int>{ 9 };
	const auto rhs = new std::vector<int>{ 1,9,9,9,9,9,9,9 };

	const auto lhs_list_node = CreateListNode(*lhs);
	const auto rhs_list_node = CreateListNode(*rhs);

	std::cout << ListNodeToString(addTwoNumbers(lhs_list_node, rhs_list_node)) << std::endl;

	return 0;
}
