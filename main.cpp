#include <iostream>
#include <vector>

using namespace std;

//Modify the above question to left-align or right-align the text in the box.
//How could you centre align the text?

int main() {
    vector<string> lines;
    string userInput;
    int maxWordLength = 0;
    string alignOption = "0";

    cout << "Enter your text (use '\\' on a line by itself to end):\n";

    do {
        getline(cin, userInput);

        if (userInput != "\\") { //see if user is ending input
            lines.push_back(userInput); //store this line

            //find max word length for formatting later
            if (userInput.length() > maxWordLength) {
                maxWordLength = userInput.length();
            }
        }
    } while (userInput != "\\");

    //change border length
    string border = string(maxWordLength + 4, '*');

    cout << "Choose text align:\n[0] - Left\n[1] - Right\n[2] - Centre\nEnter:" << endl;
    getline(cin, alignOption);

    cout << border << endl; //top border

    //middle parts of message
    switch (stoi(alignOption)) {
        case 0:
            //left align (normal logic)

            //print each line with side borders
            for (const string& line : lines) {
                cout << "* " << line;
                //go to end of line with char if it doesn't fit
                cout << string(maxWordLength - line.length(), ' ');
                cout << " *" << endl;
            }

            break;

        case 1:
            //right align (normal logic but from right)
            for (const string& line : lines) {
                //start line with all the spaces
                cout << "* " << string(maxWordLength - line.length(), ' ');
                cout << line << " *" << endl;
            }

            break;

        case 2:
            //centre align (add equal to both sides / +1 to right)
            for (const string& line : lines) {
                //if equal to maxWordLength, don't change these!
                int leftPad = 0;
                int rightPad = 0;

                if (line.length() != maxWordLength) {
                    leftPad = (maxWordLength - line.length()) / 2;
                    rightPad = (maxWordLength - line.length()) - leftPad;
                }

                cout << "* " << string(leftPad, ' ') << line;
                //go to end of line with char if it doesn't fit
                cout << string(rightPad, ' ');
                cout << " *" << endl;
            }

            break;
    }

    cout << border << endl; //bottom border

    return 0;
}
