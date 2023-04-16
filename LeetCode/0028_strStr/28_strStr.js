/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    const getNext = (needle) => {
        let next = Array(needle.length).fill(0);
        let j = -1;
        next[0] = j;
        for (let i = 1; i < needle.length; i++) {
            while (j >= 0 && needle[i] != needle[j + 1])
                j = next[j];
            if (needle[i] === needle[j + 1])
                j++;
            next[i] = j;
        }
        return next;
    };
    
    let next = getNext(needle);
    let j = -1;
    for (let i = 0; i < haystack.length; i++) {
        while (j >= 0 && haystack[i] != needle[j + 1])
            j = next[j];
        if (haystack[i] === needle[j + 1])
            j++;
        if (j === needle.length - 1)
            return i - j;
    }
    return -1;

};