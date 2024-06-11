/**
 * raw question:
 * 构造链表
 * 输入一个数 n，表示数组大小
 * 下面输入 n 行，每一行输入为两个数
 * - 第一个数为实际的数字，第二个为下一个数字在该 n
 * 行数组中的第几行，若为0，说明该数为最后一个，
 * - 根据上面的顺序，构造出数组的实际位置，最后反转这组数字，
 * - 可以用链表进行辅助
 * 
 * for example
 * 5
    4 5
    5 1
    2 4
    1 0
    3 3
 */
#include <spdlog/spdlog.h>
#include <iostream>
#include <vector>

struct ListNode {
    int value;
    int next_index;
    ListNode* next;
    ListNode* prev;
    ListNode(int v, int ni)
        : value(v), next_index(ni), next(nullptr), prev(nullptr) {}
};

std::vector<int> construct_linked_list(
    const std::vector<std::pair<int, int>>& data) {
    int n = data.size();
    std::vector<ListNode*> nodes;
    nodes.reserve(n);

    // 创建节点
    for (const auto& entry : data) {
        nodes.push_back(new ListNode(entry.first, entry.second));
    }

    // 链接节点
    for (int i = 0; i < n; ++i) {
        if (nodes[i]->next_index != 0) {
            nodes[i]->next = nodes[nodes[i]->next_index - 1];
            nodes[nodes[i]->next_index - 1]->prev = nodes[i];
        }
    }

    // 找到链表的头
    ListNode* head = nullptr;
    for (int i = 0; i < n; ++i) {
        if (nodes[i]->next_index == 0) {
            head = nodes[i];
            break;
        }
    }

    // 将反转后的链表转换为数组
    std::vector<int> result;
    ListNode *current = head;
    while (current != nullptr) {
        result.push_back(current->value);
        current = current->prev;
    }

    // 释放内存
    for (auto node : nodes) {
        delete node;
    }

    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> data(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> data[i].first >> data[i].second;
    }
    // for debug
    // for (const auto& entry : data) {
    //     spdlog::debug("value: {}, next_index: {}", entry.first, entry.second);
    // }

    std::vector<int> result = construct_linked_list(data);
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
