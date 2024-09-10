# 快速检测是否存在环，如果有的话就输出环，没有就输出 false
import queue
import sys
from typing import Any, Dict, List


def main():
    edges: Dict[int, List[int]] = {}
    visited: Dict[int, bool] = {}
    stacks: List[int] = []
    res: List[int] = []

    num = int(sys.stdin.readline())
    for i in range(num):
        n1, n2 = map(int, sys.stdin.readline().strip().split(" "))
        if n1 not in edges:
            edges[n1] = []
        if n2 not in edges[n1]:
            edges[n1].append(n2)
        if n1 not in visited.keys():
            visited[n1] = False
        if n2 not in visited.keys():
            visited[n2] = False

    def dfs(
        node: int,
        edges: Dict[int, List[int]],
        visited: Dict[int, Any],
        stacks: List[Any],
    ):
        visited[node] = True
        stacks.append(node)
        if node in edges:
            for neighbor in edges[node]:
                if neighbor not in stacks:
                    if not visited[neighbor]:
                        dfs(neighbor, edges, visited, stacks)
                else:
                    index = stacks.index(neighbor)
                    tmp_res = stacks[index:] + [neighbor]
                    res.append(tmp_res)
        stacks.pop()

    for node in visited.keys():
        if not visited[node]:
            dfs(node, edges, visited, stacks)

    print(f"Circles count: {len(res)}")
    for i, circle_list in enumerate(res):
        print(f"{i}: {circle_list}")


if __name__ == "__main__":
    main()
