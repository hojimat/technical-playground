docker build -t auth0-golang-web-app .
docker run --env-file .env -p 8080:8080 -it auth0-golang-web-app
