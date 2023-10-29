//2722. Join Two Arrays by ID
/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    // Write your code here
    let result = [];
    let arr1Map = new Map();
    let arr2Map = new Map();
    arr1.forEach(element => {
        arr1Map.set(element.id, element);
    });
    arr2.forEach(element => {
        arr2Map.set(element.id, element);
    });
    arr1Map.forEach((value, key) => {
        if(arr2Map.has(key)){
            let obj = arr2Map.get(key);
            for(let prop in obj){
                value[prop] = obj[prop];
            }
        }
        result.push(value);
    });
    arr2Map.forEach((value, key) => {
        if(!arr1Map.has(key)){
            result.push(value);
        }
    });
    return result;
};