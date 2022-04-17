package main

import (
	"fmt"
	"strings"
)


func customSortString(order string, s string) string {
	charCounter := make(map[rune]int)
	for _, char := range s {
		if _, found := charCounter[char]; found {
			charCounter[char] ++
		} else {
			charCounter[char] = 1
		}
	}
	var ansAsOrder string = ""
	for _, char := range order {
		if count, found := charCounter[char]; found {
			ansAsOrder += strings.Repeat(string(char), count)
			charCounter[char] = 0
		}
	}
	var ansExceptOrder string = ""
	for char, count := range charCounter {
		if count != 0 {
			ansExceptOrder += strings.Repeat(string(char), count)
		}
	}
	return ansAsOrder + ansExceptOrder
}


func main() {
	answer := customSortString("cbafg", "ggfabcd")
	fmt.Println(answer)
}
