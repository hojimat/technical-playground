# README

Datarockets Ruby on Rails technical task. Creates a model `Post`, a model `History` (for logging purposes), creates posts controller with a Create functionality (not all of CRUD) that also logs in History and sends an email if successfully created. Also, includes unit tests.

## Quick start

1. Install the gemfile bundle
2. run `rails server` --- this opens a webapp connection at `localhost:3000`
3. run `bundle exec mailcatcher` in terminal --- this opens an smtp connection at `:1025` and the web connection at `:1080`
4. go to the homepage at `:3000` and create exactly one user for email destinations (the current version is simplified and supports exactly one user)
5. go back to the homepage and go to the posts
6. create a post
7. go to `:1080` to check the outgoing emails
`
