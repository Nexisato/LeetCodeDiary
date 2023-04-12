//Definition for a binary tree node.
function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} root
 * @return {number[]}
 */

var findMode = function (root) {
    let count = 0, maxCount = 0;
    let pre = null, res = [];

    const traversal = (node) => {
        if (node === null) return;
        traversal(node.left);

        if (pre === null) {
            count = 1;
        } else if (pre.val === node.val) {
            count++;
        } else {
            count = 1;
        }
        pre = node;

        if (count === maxCount) res.push(node.val);
        if (count > maxCount) {
            maxCount = count;
            res = [];
            res.push(node.val);
        }
        traversal(node.right);
    };

    traversal(root);
    return res;

};
