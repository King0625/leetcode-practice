package leetcode

func candy(ratings []int) int {
	children := len(ratings)

	candies := make([]int, children)

	candies[0] = 1

	for i := 1; i < children; i++ {
		if ratings[i] > ratings[i-1] {
			candies[i] = candies[i-1] + 1
		} else if ratings[i] == ratings[i-1] {
			candies[i] = 1
		} else {
			candies[i] = 1
			counter := i
			for counter > 0 && ratings[counter] < ratings[counter-1] && candies[counter] == candies[counter-1]{
				
				candies[counter-1] = candies[counter] + 1
				counter--
			}
		}
	}

	var result int

	for _, candy := range candies {
		result += candy
	}

	return result
}

