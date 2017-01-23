#ifndef HELPER_HPP
#define HELPER_HPP

#include <iostream>

namespace helper {
	struct ListNode {
		int val;
		ListNode * next;
		ListNode(int x) : val(x), next(NULL) {}
	};
}

#endif
