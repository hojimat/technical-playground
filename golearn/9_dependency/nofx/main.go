package main

import "fmt"

type Journal struct{}

func (j *Journal) GetStats() string {
	return "Impact factor:3.5; h-index:10"
}

type Article struct {
	journal *Journal
}

func NewArticle(j *Journal) *Article {
	return &Article{journal: j}
}

func (art *Article) GetPublisherStats() string {
	return art.journal.GetStats()
}

func main() {
	qje := &Journal{}
	mankiw98 := NewArticle(qje)
	fmt.Println(mankiw98.GetPublisherStats())
}
