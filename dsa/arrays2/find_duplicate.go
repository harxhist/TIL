func findDuplicate(nums []int) int {
    //brute force: TLE :(
    // for i := 0; i < len(nums) - 1; i++{
    //     for j := i+1 ; j < len(nums); j++{
    //         if nums[i] == nums[j] {
    //             return nums[i];
    //         }
    //     }
    // } 
    // return 0;

    //floyd cycle
    slow := 0
    fast := 0
    for {
        slow = nums[slow]
        fast = nums[nums[fast]]
        if slow == fast {
            break;
        }
    }
    fast = 0
    for {
        fast = nums[fast]
        slow = nums[slow]
        if slow == fast {
            break;
        }
    }
    return slow;
}