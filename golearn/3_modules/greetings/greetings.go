package greetings

import (
    "fmt"
    "errors"
    "math/rand"
)

func Hello(name string) (string, error) {
        // If no name was given, return error:
        if name=="" {
                return name, errors.New("Empty name")
        }

        // Return a greeting
        message := fmt.Sprintf(randomFormat(), name)

        return message, nil
}

func Hellos(names []string) (map[string]string, error) {
        messages := make(map[string]string)

        for _, name := range names {
                message, err := Hello(name)
                if err != nil {
                        return nil, err
                }

                messages[name] = message
        }
        return messages, nil
}


// PascalCase for public and camelCase for private names
func init() {
        //rand.Seed(time.Now().UnixNano())
}

func randomFormat() string {
        formats := []string {
                "Hi, %v, welcome!",
                "Great to see you, %v!",
                "As-salamu alayka, ya %v!",
        }

        return formats[rand.Intn(len(formats))]
}
