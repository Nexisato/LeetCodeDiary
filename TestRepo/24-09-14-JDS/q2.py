# 不要想太麻烦
import sys
from typing import List, Any, Dict
from functools import cmp_to_key


if __name__ == '__main__':
    alpha_order = input().strip()
    n = int(input())
    char_rank: Dict[str, Any] = {c : i for i, c in enumerate(alpha_order)}
   
    
    def cmp(s1, s2):
        for c1, c2 in zip(s1, s2):
            if c1 != c2:
                return char_rank[c1] - char_rank[c2]
        return len(s1) - len(s2)
    
    raw_s = [input().strip() for _ in range(n)]
    raw_s.sort(key=cmp_to_key(cmp))
    for s in raw_s:
        print(s)
    

    