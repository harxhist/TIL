package main

func majorityElement(nums []int) int {
    count := 1
    ele := nums[0]
    for i := 0; i < len(nums); i++ {
        if ele == nums[i] {
            count++
        } else {
            count--
        }
        if count == 0 {
            count = 1
            ele = nums[i]
        }
    }
    return ele
}