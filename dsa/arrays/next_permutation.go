package main

func reverse(nums []int, start, end int){
    for ; start < end; {
        nums[start], nums[end] = nums[end], nums[start]
        start++
        end-- 
    }
    
}

func nextPermutation(nums []int)  {
    idx := -1
    for i := len(nums) - 2 ; i>=0; i--{
        if nums[i] < nums[i+1] {
            idx = i
            break
        }
    }
    if idx == -1 {
        reverse(nums, 0, len(nums) - 1)
        return 
    }
    for i := len(nums) - 1 ; i>=0; i--{
        if nums[i] > nums[idx] {
            nums[i], nums[idx] = nums[idx], nums[i]
            break
        }
    }
    reverse(nums, idx + 1, len(nums) - 1)
}   