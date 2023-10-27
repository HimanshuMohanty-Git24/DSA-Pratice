//2631. Group By
/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    let result = {};
    this.forEach((item) => {
        let key = fn(item);
        result[key] = result[key] || [];
        result[key].push(item);
    });
    return result;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */