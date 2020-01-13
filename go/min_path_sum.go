package main

import (
	"fmt"
	"math"
)

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

func minPathSum(grid [][]int) int {
	l := len(grid)
	c := len(grid[0])
	copy := make([][]int, l+1)
	for i := 0; i <= l; i++ {
		copy[i] = make([]int, c+1)
	}

	for i := 0; i < c+1; i++ {
		copy[0][i] = math.MaxInt64
	}
	for i := 0; i < l+1; i++ {
		copy[i][0] = math.MaxInt64
	}
	copy[1][1] = grid[0][0]
	for i := 1; i < l+1; i++ {
		for j := 1; j < c+1; j++ {
			if i == 1 && j == 1 {
				continue
			}
			copy[i][j] = grid[i-1][j-1] + min(copy[i-1][j], copy[i][j-1])
		}
	}

	return copy[l][c]
}

func main() {
	triangle := make([][]int, 3)
	for i := 0; i < len(triangle); i++ {
		triangle[i] = make([]int, 3)
	}
	triangle[0][0] = 1
	triangle[0][1] = 3
	triangle[0][2] = 1
	triangle[1][0] = 1
	triangle[1][1] = 5
	triangle[1][2] = 1
	triangle[2][0] = 4
	triangle[2][1] = 2
	triangle[2][2] = 1

	ret := minPathSum(triangle)
	fmt.Println(ret)
}
