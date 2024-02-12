#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> lines;
    string userInput;
    int maxWordLength = 0;

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

    cout << border << endl; //top border

    //print each line with side borders
    for (const string& line : lines) {
        cout << "* " << line;
        //go to end of line with char if it doesn't fit
        cout << string(maxWordLength - line.length(), ' ');
        cout << " *" << endl;
    }

    cout << border << endl; //bottom border

    return 0;
}
