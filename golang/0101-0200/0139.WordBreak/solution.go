package leetcode

func wordBreak(s string, wordDict []string) bool {
	length := len(s)
	dp := make([]bool, length+1)
	dp[0] = true
	maxLen := 0
	for _, word := range wordDict {
		maxLen = max(maxLen, len(word))
	}

	for i := 1; i <= length; i++ {
		for j := i - 1; j >= max(i-maxLen-1, 0); j-- {
			if dp[j] && contains(wordDict, s[j:i]) {
				dp[i] = true
				break
			}
		}
	}

	return dp[length]
}

func contains(words []string, target string) bool {
	for _, word := range words {
		if word == target {
			return true
		}
	}

	return false
}
