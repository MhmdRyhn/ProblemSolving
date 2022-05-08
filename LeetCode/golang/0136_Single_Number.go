package main

import (
	"fmt"
)


func singleNumber(nums []int) int {
    ans := 0
	for _, value := range nums {
		ans ^= value
	}
	return ans
}


func main() {
	answer := singleNumber([]int{1, 1, 3, 4, 4, 5, 5, 8, 8})
	fmt.Println(answer)
}
