package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"os"
	"regexp"
	"strings"
)

type Code struct {
	Number string
	Title  string
	Time   string
	Code   string
}

func main() {
	arr := []Code{}
	buf, err := ioutil.ReadFile("parsed.txt")
	if err != nil {
		panic(err)
	}

	specialPat := regexp.MustCompile(`[^0-9ㄱ-ㅎ가-힣a-zA-Z\s.]+`)
	json.Unmarshal(buf, &arr)
	for _, a := range arr {
		t := strings.Replace(a.Time, "/", ".", -1)
		filename := t + " " + a.Title + ".cpp"
		filename = specialPat.ReplaceAllString(filename, "")
		fmt.Println(filename)
		file, err := os.Create(filename)
		if err != nil {
			panic(err)
		}

		_, err = file.Write([]byte(a.Code))
		if err != nil {
			panic(err)
		}
		file.Close()
	}
}
