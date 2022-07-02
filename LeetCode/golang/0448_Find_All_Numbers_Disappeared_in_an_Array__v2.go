package main

import (
	"fmt"
	// "math"
	"reflect"
)


func findDisappearedNumbers(nums []int) []int {
	numsSize := len(nums)
	swap := reflect.Swapper(nums)
	i := 0
	for i < numsSize {
		if  nums[i] != nums[nums[i]-1] {
			swap(i, nums[i]-1)
		} else {
			i++
		}
	}
	ans := []int{}
	for index, value := range nums {
		if value - 1 != index  {
			ans = append(ans, index + 1)
		}
	}
	return ans
}

func main() {
	// answer := findDisappearedNumbers([]int{1, 2, 3, 4, 5, 3, 2, 8})
	answer := findDisappearedNumbers([]int{4,3,2,7,8,2,3,1})
	fmt.Println(answer)
}
