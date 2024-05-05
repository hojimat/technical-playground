package main

import (
	"context"
	"fmt"

	"go.uber.org/fx"
)

type Journal struct{}

func NewJournal() *Journal {
	return &Journal{}
}

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

type Book struct{}

func NewBook() *Book {
	return &Book{}
}

func main() {
	app := fx.New(
		fx.Provide(
			NewJournal,
			//NewArticle,
			NewBook,
		),
		fx.Invoke(announceOnTwitter),
	)

	app.Start(context.Background())
	defer app.Stop(context.Background())
}

func announceOnTwitter() {
	//fmt.Println(art.GetPublisherStats())
	fmt.Println("with great power.")
}
