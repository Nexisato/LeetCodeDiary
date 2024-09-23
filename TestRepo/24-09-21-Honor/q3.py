from typing import List, Any
import sys


class Item:
    def __init__(self, id: str, t: int, limit: int, cost: int) -> None:
        self.id = id  # 编号
        self.t = t  # 接收时间
        self.limit = limit  # 人力限制
        self.cost = cost  # 开发时间

    def total_cost(self) -> int:
        return self.cost * self.limit

    # 投入 num 人花费的时间
    def get_real_time(self, num: int):
        return self.total_cost() / num


class Group:
    def __init__(self, id: int, num: int, start: int) -> None:
        self.id = id
        self.num = num  # 总人数
        self.start = start  # 开始时间


if __name__ == "__main__":
    # 各开发小组需求人数
    group_ns: List[Any] = list(map(int, sys.stdin.readline().strip().split("|")))
    groups: List[Group] = []
    for idx, num in enumerate(group_ns):
        cur_group = Group(id=idx + 1, num=num, start=0)
        groups.append(cur_group)
    n: int = len(groups)

    used = set()

    demands: List[Item] = []
    # 编号，接受时间，人力限制，开发时间
    for line in sys.stdin:
        cur_demand = line.strip().split("|")
        id, t, limit, cost = (
            cur_demand[0],
            int(cur_demand[1]),
            int(cur_demand[2]),
            int(cur_demand[3]),
        )
        cur_elem = Item(id, t, limit, cost)
        demands.append(cur_elem)

    # 输出为
    res = []
    # 编号，开发小组，需求开发时间，实际耗时
    for demand_item in demands:
        # 对每个需求
        cur_group = None
        min_real_cost = 9999
        for group in groups:
            if group not in used:
                cur_real_cost = demand_item.get_real_time(group.num)
                if min_real_cost > cur_real_cost:
                    min_real_cost = cur_real_cost
                    cur_group = group

        if cur_group is not None:
            used.add(cur_group)
            real_cost = demand_item.get_real_time(cur_group.num)
            cur_str = (
                f"{demand_item.id}|{cur_group.id}|{cur_group.start}|{int(real_cost)}"
            )
            res.append(cur_str)
            cur_group.start += real_cost
        else:
            for group in groups:
                cur_real_cost = demand_item.get_real_time(group.num)
                if min_real_cost > cur_real_cost:
                    min_real_cost = cur_real_cost
                    cur_group = group
            real_cost = demand_item.get_real_time(cur_group.num)
            cur_str = (
                f"{demand_item.id}|{cur_group.id}|{cur_group.start}|{int(real_cost)}"
            )
            res.append(cur_str)
            cur_group.start += real_cost

    for res_str in res:
        print(res_str)
