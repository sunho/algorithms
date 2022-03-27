package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"net/http"
	"net/http/cookiejar"
	"os"
	"strings"
	"time"

	"github.com/PuerkitoBio/goquery"
)

const (
	baseURL  = "http://codeup.kr/JudgeOnline/"
	loginURL = baseURL + "login.php"
	frontURL = baseURL + "status.php?user_id=%s&jresult=4"
)

var cli *http.Client
var n int

func init() {
	cli = &http.Client{}
	cookieJar, _ := cookiejar.New(nil)
	cli.Jar = cookieJar
}

func FakeReq(req *http.Request) {
	req.Header.Set("Origin", "http://codeup.kr")
	req.Header.Set("Host", "codeup.kr")
	req.Header.Set("User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/67.0.3396.99 Safari/537.36")
	req.Header.Set("Content-Type", "application/x-www-form-urlencoded")
}

func Login(id string, pw string) error {
	front := "user_id=%s&password=%s&submit="
	front = fmt.Sprintf(front, id, pw)
	tail := `%EB%A1%9C%EA%B7%B8%EC%9D%B8`
	data := front + tail
	req, err := http.NewRequest("POST", loginURL, strings.NewReader(data))
	if err != nil {
		return err
	}

	FakeReq(req)

	resp, err := cli.Do(req)
	if err != nil {
		return err
	}

	buf, _ := ioutil.ReadAll(resp.Body)
	if !strings.Contains(string(buf), "history") {
		panic("login failed")
	}

	return nil
}

func NewDoc(url string) (*goquery.Document, error) {
	req, err := http.NewRequest("GET", url, nil)
	if err != nil {
		return nil, err
	}

	FakeReq(req)

	resp, err := cli.Do(req)
	if err != nil {
		return nil, err
	}

	doc, err := goquery.NewDocumentFromReader(resp.Body)
	if err != nil {
		return nil, err
	}

	return doc, nil
}

func ParseProblem(url string) (title string, body string, err error) {
	doc, err := NewDoc(url)
	if err != nil {
		return
	}

	title = doc.Find("title").First().Text()
	fmt.Println("Pasing", title)

	doc.Find(".panel").Each(func(i int, s *goquery.Selection) {
		title := s.Find(".panel-heading strong").First().Text()
		if title == "묻고 답하기" || title == "이 문제와 관련있는 개인 강의" {
			return
		}

		b := s.Find(".panel-body").First().Text()
		body += fmt.Sprintf("# %s \n %s \n", title, b)
	})

	return
}

func ParseCode(url string) (string, error) {
	doc, err := NewDoc(url)
	if err != nil {
		return "", err
	}

	code := doc.Find("pre").First().Text()
	return code, nil
}

type Code struct {
	Number string
	Time   string
	Title  string
	Code   string
}

func Format(problem, code string) string {
	return fmt.Sprintf("/**************************************************************\n%s\n*************************************************************/\n%s", problem, code)
}

func Parse(url string) []Code {
	fmt.Println("Parsing ", url)
	doc, err := NewDoc(url)
	if err != nil {
		panic(err)
	}

	nexthref, _ := doc.Find(".pager li a").Last().Attr("href")
	nexturl := baseURL + nexthref
	if nexturl == url {
		return []Code{}
	}

	out := []Code{}
	doc.Find("#result-tab tbody tr").Each(func(i int, s *goquery.Selection) {
		title := ""
		problem := ""
		code := ""
		number := ""
		t := ""
		s.Find("a").Each(func(i int, s *goquery.Selection) {
			href, _ := s.Attr("href")
			if strings.HasPrefix(href, "problem") {
				if problem != "" {
					return
				}
				title_, body, err := ParseProblem(baseURL + href)
				if err != nil {
					panic(err)
				}

				number = s.Text()
				problem = body
				title = title_
			}

			if strings.HasPrefix(href, "showsource") {
				if code != "" {
					return
				}
				code_, err := ParseCode(baseURL + href)
				if err != nil {
					panic(err)
				}
				code = code_
			}

			if _, err := time.Parse(s.Text(), "2006/01/02"); err != nil {
				t = s.Text()
			}
		})

		out = append(out, Code{
			Number: number,
			Time:   t,
			Title:  title,
			Code:   Format(problem, code),
		})
		n++
	})

	return append(out, Parse(nexturl)...)
}

func main() {
	id := os.Args[1]
	pw := os.Args[2]
	Login(id, pw)

	arr := Parse(fmt.Sprintf(frontURL, id))
	buf, err := json.Marshal(arr)
	if err != nil {
		panic(err)
	}

	ioutil.WriteFile("parsed.txt", buf, 0644)
	fmt.Println("total", n)
}
