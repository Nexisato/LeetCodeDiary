/**
 * @param {number} n
 * @param {number[][]} paths
 * @return {number[]}
 */
var gardenNoAdj = function(n, paths) {
    let flower = new Array(n).fill(0);
    let gardens = new Array(n).fill(null).map(() => []);
    for (let path of paths) {
        let x = path[0] - 1, y = path[1] - 1;
        gardens[x].push(y);
        gardens[y].push(x);
    }
    for (let i = 0; i < n; i++) {
        let colored = new Array(5).fill(false);
        for (let vertex of gardens[i]) {
            colored[flower[vertex]] = true;
        }
        for (let j = 1; j <= 4; j++) {
            if (!colored[j]) {
                flower[i] = j;
                break;
            }
        }
    }
    return flower;
};