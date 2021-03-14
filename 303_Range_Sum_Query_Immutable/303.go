package main

type NumArray struct {
	sums []int
}

func Constructor(nums []int) NumArray {
	sums := make([]int, len(nums)+1)
	for i := range nums {
		sums[i+1] = sums[i] + nums[i]
	}
	return NumArray{sums}
}

func (this *NumArray) SumRange(i int, j int) int {
	return this.sums[j+1] - this.sums[i]
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(i,j);
 */
func main() {

}
