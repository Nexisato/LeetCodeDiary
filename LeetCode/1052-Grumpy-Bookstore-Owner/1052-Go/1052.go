package main

import "fmt"

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func maxSatisfied(customers []int, grumpy []int, X int) int {
	var res int
	for i := 0; i < len(customers); i++ {
		if grumpy[i] == 0 {
			res += customers[i]
		}
	}
	var left int
	var tmpSum, maxSum int
	for right := 0; right < len(customers); right++ {
		if grumpy[right] == 1 {
			tmpSum += customers[right]
		}
		if right < X - 1 {
			continue
		}
		maxSum = max(maxSum, tmpSum)
		if grumpy[left] == 1 {
			tmpSum -= customers[left]
		}
		left++
	}
	return res + maxSum
}

func main() {
	fmt.Println("hello")
}