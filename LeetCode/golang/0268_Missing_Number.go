package main

import (
	"fmt"
)


func missingNumber(nums []int) int {
	numsLength := len(nums)
    total := 0
	for _, value := range nums {
		total += value
	}
	answer := (numsLength * (numsLength +1))/2
	return answer - total
}


func main() {
	answer := missingNumber([]int{0, 2, 3, 4, 5})
	fmt.Println(answer)
}
