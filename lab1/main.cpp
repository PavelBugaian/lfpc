#include<iostream>
#include<string>

using namespace std;

int main(int argc, char const *argv[]) {

    char cur_state, letter;

    string sentence;
    while (true) {
        HERE:
        cur_state = 'S';
        cout << "\n\nInitial point: " << cur_state << "\n\nEnter expression: ";
        cin >> sentence;

        cout << "\nPath:\n";

        for (char i : sentence) {
            letter = i;

            switch (cur_state) {

                case 'S':
                    if(letter == 'c') {

                        cur_state = 'D';
                        break;

                    } else if(letter == 'a') {

                        cur_state = 'S';
                        break;

                    } else {

                        cout << "\nInvalid expression!";
                        goto HERE;

                    }

                case 'D':
                    if (letter == 'b') {

                        cur_state = 'R';
                        break;

                    } else {

                        cout << "\nInvalid expression!";
                        goto HERE;

                    }

                case 'R':
                    switch (letter) {
                        case 'a':
                            break;

                        case 'b':
                            cur_state = 'F';
                            break;

                        case 'c':
                            cur_state = 'S';
                            break;

                        default:
                            cout << "\nInvalid expression!";
                            goto HERE;

                    }
                    break;

                case 'F':
                    if (letter == 'b') {

                        cout << "terminal point reached" << "\nValid expression";
                        goto HERE;

                    } else {

                        cout << "\nInvalid expression!";
                        goto HERE;

                    }
            }
            printf("%c\n", cur_state);
        }
        cout << "\nFinal destination - " << cur_state << "\nSentence is valid!";

    }
}