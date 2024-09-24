from typing import List, Any, Dict

class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        res: List[str] = []
        path: List[str] = []
        n: int = len(s)
        
        
        def dfs(idx) -> None:
            if idx == n and len(path) == 4:
                cur: str = ".".join(path)
                res.append(cur)
                return

            for j in range(idx, n):
                t = s[idx: j + 1]
                
                # 发现 0 前缀，直接 break 返回
                if str(int(t)) != t:
                    continue
                
                if len(path) < 4 and 0 <= int(t) <= 255:
                    path.append(t)
                    dfs(j + 1)
                    path.pop()
            return
        
        dfs(0)
                
        
        return res
        
        
if __name__ == '__main__':
    
    pass