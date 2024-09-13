import heapq
from typing import List, Any, Dict, Set


# 保证 digits 有序，获取小于 target 的最大下标
def get_max_digit_lower(digits: List[int], target: int) -> int:
    l , r = 0, len(digits)
    res = -1
    while l < r:
        mid = int(l + (r - l) / 2)
        if digits[mid] < target:
            res = digits[mid]
            l = mid + 1
        else:
            r = mid
    return res

# 基本思想：n 的每个数位，从高位开始，尝试先使用相同的数字
# 到最后一位 或者 没有相同的数字时，尝试寻找比当前位更小的数字
#   - 若找到，则该位置使用这个数字，后面的全部用 a 中最大值
#   - 没找到，继续往高位回溯，每一位都尝试寻找小于 n 对应数位的最大值，直到第一位没找到，则目标数位总数比 n 小，全部用 a 中最大值
# 
def find_max_number_less_than_n(n: int, a: List[int]):
    a.sort()
    n_digits: List[int] = list(map(int, str(n)))
    a_digits: Set[int] = set(a)
    
    t_digits: List[int] = [0] * len(n_digits)

    
    for idx, num in enumerate(n_digits):
        if idx < len(n_digits) - 1 and num in a_digits:
            t_digits[idx] = num
            continue
        # 小于 num 的最大值
        d = get_max_digit_lower(a, num)
        if d > 0:
            t_digits[idx] = d
            break
        
        cur_idx = idx
        while cur_idx >= 0:
            t_digits[cur_idx] = 0
            
            d = get_max_digit_lower(a, n_digits[cur_idx])
            if d > 0:
                t_digits[cur_idx] = d
                break
            cur_idx -= 1
            if cur_idx < 0:
                t_digits = t_digits[:-1]
        break
        
    target = 0
    for t in t_digits:
        target *= 10
        if t > 0:
            target += t
            continue
        target += a[-1]
    
    return target


if __name__ == '__main__':
    n = 5555
    a = [5, 9]
    target = 3
    
    print(find_max_number_less_than_n(n, a))