import heapq

def find_max_number_less_than_n(n, a):
    a.sort(reverse=True)
    num_str = str(n)
    max_heap = []

    def dfs(digit_index, current_value):
        if current_value > n:
            return
        if digit_index == len(num_str):
            heapq.heappush(max_heap, (-current_value, current_value))  # 使用负数来实现最大堆
            return

        current_digit = int(num_str[digit_index])
        found_smaller = False

        for num in a:
            if num < current_digit:
                dfs(digit_index + 1, current_value * 10 + num)
                found_smaller = True

            elif num == current_digit:
                dfs(digit_index + 1, current_value * 10 + num)

        if not found_smaller:
            for num in a[::-1]:
                dfs(digit_index + 1, current_value * 10 + num)

    dfs(0, 0)

    if max_heap:
        return max_heap[0][1]
    else:
        return -1


if __name__ == '__main__':
    n = 23121
    a = [2, 4, 9]
    print(find_max_number_less_than_n(n, a))

