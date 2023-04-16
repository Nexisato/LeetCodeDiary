/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var reverseStr = function(s, k) {
    const n = s.length;
    let res = Array.from(s);
    const reverse = (arr, l, r) => {
        while (l < r) {
            [arr[l], arr[r]] = [arr[r], arr[l]];
            l++;
            r--;
        }
    };
    for(let i = 0; i < n; i += 2 * k) {
        reverse(res, i, Math.min(i + k, n) - 1);
        // let l = i - 1, r = i + k > len ? len : i + k;
        // while(++l < --r) [resArr[l], resArr[r]] = [resArr[r], resArr[l]];
    }
    return res.join("");
};
