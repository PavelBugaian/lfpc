package evaluate

import (
	"bufio"
	"fmt"
	"go/token"
	"io"
	"main/lexer"
)

const PROMPT = "<meow>^..^<meow>"

//helper function for  input and output values
func Start(in io.Reader, out io.Writer) {
	scanner := bufio.NewScanner(in)

	for {
		fmt.Printf(PROMPT)
		scanned := scanner.Scan()

		if !scanned {
			return
		}

		line := scanner.Text()
		lexer := lexer.New(line)

		for tok := lexer.NextToken(); tok.Type != token.EOF; tok = lexer.NextToken() {
			fmt.Printf("%+v\n", tok)
		}
	}

}