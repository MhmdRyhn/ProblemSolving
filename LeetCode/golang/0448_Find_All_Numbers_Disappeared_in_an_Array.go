package main

import (
	"fmt"
	"math"
)


func findDisappearedNumbers(nums []int) []int {
    for _, value := range nums {
		a := int(math.Abs(float64(value))) - 1
		if nums[a] > 0 {
			nums[a] = - nums[a]
		}
	}
	ans := []int{}
	for index, value := range nums {
		if value > 0 {
			ans = append(ans, index + 1)
		}
	}
	return ans
}

func main() {
	answer := findDisappearedNumbers([]int{1, 2, 3, 4, 5, 3, 2, 8})
	fmt.Println(answer)
}
