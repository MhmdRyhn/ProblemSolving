package main

import (
	"fmt"
	"strconv"
)


func countAndSay(n int) string {
	var say string = "1"
	for k := 1; k<n; k++ {
		var sayNew string = ""
		var count int = 1
		var sayLength = len(say)
		if k == 1 {
			say = "11"
			continue
		}
		for i:= 1; i < sayLength; i++ {
			if say[i] == say[i-1] {
				count ++
			} else {
				sayNew += strconv.Itoa(count)
				sayNew += string(say[i-1])
				count = 1
			}
		}
		sayNew += strconv.Itoa(count)
		sayNew += string(say[sayLength-1])
		say = sayNew
		sayNew = ""
	}
	return say
}


func main() {
	answer := countAndSay(10)
	fmt.Println(answer)
}
