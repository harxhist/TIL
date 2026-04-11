package main

func twoSum(nums []int, target int) []int {
    mp := make(map[int]int)
    for i, v := range nums {
        toFind := target - v
        val, ok := mp[toFind]
        if ok {
            return []int{i, val}
        }
        mp[v] = i
    }
    return []int{}
}
