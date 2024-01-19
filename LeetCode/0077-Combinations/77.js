/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
var combine = function(n, k) {
    let path = [];
    let res = [];
    const backtracking = (n, k, startNum) => {
        if (path.length === k) {
            res.push([...path]); //js数组为引用类型，这样写传值副本
            return;
        }
        for (let i = startNum; i <= n - (k - path.length) + 1; i++) {
            path.push(i);
            backtracking(n, k, i + 1);
            path.pop()
        }
    };
    backtracking(n, k, 1);
    return res;
};