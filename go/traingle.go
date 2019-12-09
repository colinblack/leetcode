package  main
import "fmt"

//贪心法，得不到正确结果
/* func minimumTotal(triangle [][]int) int {
	l := len(triangle)
	if l == 0{
		return 0
	}

	sum := triangle[0][0]
	idxs := make([]int, len(triangle[l-1]))
	idxs[0] = 0
	var idx int
	for i := 1; i < l; i++{
		idx = idxs[i-1]
		if triangle[i][idx] > triangle[i][idx+1]{
			sum += triangle[i][idx]
			idxs[i] = idx
		}else{
			sum += triangle[i][idx+1]
			idxs[i] = idx + 1
		}t

	}
	
	return sum
} */
func min(a int, b int) int{
	if a < b{
		return a
	}

	return b
}

func total(triangle [][]int, i int, j int) int {
	if i == 0{
		return triangle[0][0]	
	}

	if j == 0{
		//triangle[i][j] += triangle[i-1][0]
		return total(triangle, i-1, 0) + triangle[i][j]
		//return triangle[i-1][0]
	}else if j == i{
		//triangle[i][j] += triangle[i-1][i]
		return total(triangle, i-1, i) + triangle[i][j]
//		return triangle[i-1][i]
	}else{
		//triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j])
		return (min(total(triangle, i-1, j-1), total(triangle, i-1, j)) + triangle[i][j])
	}
} 

func minimumTotal(triangle [][]int) int {
	i := len(triangle)-1
   return total(triangle, i - 1, len(triangle[i]) -1)
}

func main(){
	triangle := make([][]int, 4)
	for i := 0; i < len(triangle); i++{
		triangle[i] = make([]int, i+1)
	} 
	triangle[0][0] = 2
	triangle[1][0] = 3
	triangle[1][1] = 4 
	triangle[2][0] = 6 
	triangle[2][1] = 5 
	triangle[2][2] = 7 
	triangle[3][0] = 4 
	triangle[3][1] = 1 
	triangle[3][2] = 8 
	triangle[3][3] = 3 

	ret :=	minimumTotal(triangle)
 	fmt.Println(ret)
}