const hasSum = (target, number, memo = {}) => {

    if (target in memo) return memo[target];
    if (target == 0) return [];
    if (target < 0) return null;

    for (let i = 0; i < number.length; i++) {
        const cSum = target - number[i];
        const result = hasSum(cSum, number);
        if (result != null) {
            memo[target] = [...result, number[i]];
            return memo[target];
        }
    }

    memo[target] = null;
    return null;
}


