package main

import (
	"fmt"
)


func containsDuplicate(nums []int) bool {
    myMap := make(map[int]bool)
	for _, value := range nums {
		if _, exist := myMap[value]; exist {
			return true
		}
		myMap[value] = true
	}
	return false
}


func main() {
	answer := containsDuplicate([]int{1, 1, 3, 4, 4, 5, 5, 8, 8})
	fmt.Println(answer)
}
