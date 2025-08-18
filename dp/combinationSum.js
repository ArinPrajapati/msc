/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    let memo = {};

    function solver(start, target) {
        let key = `${start}-${target}`
        if (memo[key]) return memo[key];


        if (target == 0) {
            return [[]]
        }

        if (target < 0) {
            return []
        }
        const result = [];


        for (let i = start; i < candidates.length; i++) {
            let sub_result = solver(i, target - candidates[i])

            for (let sub of sub_result) {
                result.push([candidates[i], ...sub]);
            }
        }


        memo[key] = result
        return result
    }


    return solver(0, target, []);

};


console.log(combinationSum([2, 3, 6, 7], 7))
