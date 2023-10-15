//2723. Add Two Promises
/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    let [a, b] = await Promise.all([promise1, promise2]);
    return a + b;
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */

//Explanation: 
//The async function declaration defines an asynchronous function, which returns an AsyncFunction object.
//An asynchronous function is a function which operates asynchronously via the event loop, using an implicit Promise to return its result.
//But the syntax and structure of your code using async functions is much more like using standard synchronous functions.
//Async functions always return a promise. If the return value of an async function is not explicitly a promise, it will be implicitly wrapped in a promise.