package main

func search(nums []int, target int) bool {
	low, high := 0, len(nums)-1
	if high == -1 {
		return false
	}
	if high == 0 {
		return nums[high] == target
	}
	for low <= high {
		mid := (low + (high - low)) >> 1
		if nums[mid] == target {
			return true
		}
		if nums[mid] == nums[low] {
			low++
			continue
		}
		//分区间讨论是否有序
		if nums[low] <= nums[mid] {
			if nums[low] <= target && target < nums[mid] {
				high = mid - 1
			} else {
				low = mid + 1
			}
		} else {
			if nums[high] >= target && target > nums[mid] {
				low = mid + 1
			} else {
				high = mid - 1
			}
		}

	}
	return false
}

func main() {

}
