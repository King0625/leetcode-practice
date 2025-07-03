package leetcode

type Trie struct {
	Val       int
	EndOfWord bool
	Children  [26]*Trie
}

func Constructor() Trie {
	return Trie{-1, false, [26]*Trie{}}
}

func (this *Trie) Insert(word string) {
	dummy := this
	for i := 0; i < len(word); i++ {
		val := int(rune(word[i]) - 'a')
		if dummy.Children[val] == nil {
			trie := Trie{val, false, [26]*Trie{}}
			dummy.Children[val] = &trie
		}

		if i == len(word)-1 {
			dummy.Children[val].EndOfWord = true
		}

		dummy = dummy.Children[val]
	}
}

func (this *Trie) Search(word string) bool {
	dummy := this
	for i := 0; i < len(word); i++ {
		val := int(rune(word[i]) - 'a')
		if dummy.Children[val] == nil {
			return false
		}

		if i == len(word)-1 && !dummy.Children[val].EndOfWord {
			return false
		}

		dummy = dummy.Children[val]
	}

	return true
}

func (this *Trie) StartsWith(prefix string) bool {
	dummy := this
	for i := 0; i < len(prefix); i++ {
		val := int(rune(prefix[i]) - 'a')
		if dummy.Children[val] == nil {
			return false
		}

		dummy = dummy.Children[val]
	}

	return true
}
