/*
Team: Bird

Programmers:
Isaiah Sule
Duke Ellington
Pedro Benegas


Date: 3-28-2019 --->>> 3-31-2019

Description: Have the user take a 10 question quiz, with random numbers and random operators determining
what the questions will be.

*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
using namespace std;

//Prototypes
int displayMenu();
int randomInt(int, int);
void generateOperator(char &, int);
void generateOperands(int &, int &, int);
int displayProblem(int, int, char, double &, int);
void displayMessage(double, double, int);
void displayFinalResults(int, int, int);
void displayPercentageResults(double, int);

int main()
{
    /*
    Function: main
    Programmers: Isaiah Sule
                 Pedro Benegas (rand functions)
    Date: 3-31-19
    Parameters: (unsigned) seed, (int) a, b, (double), uAnswer, answer, (char) oper,
    */
    unsigned seed = time((NULL)); //needed for rand() function
    srand(seed);
    int a,
        b,
        difficulty;

    double uAnswer;//stores user answer
    double answer;
    char oper; //for operands

    difficulty= displayMenu();//Choose difficulty
    for(int i = 0; i<10; i++)
    {
        if (i > 10)
        {
            break;
        }
        cout << "Question #" << i+1 << ":" << endl;
        generateOperator(oper, difficulty); //generates operator
        generateOperands(a,b,difficulty); //generates operands
        uAnswer = displayProblem(a,b,oper,answer,difficulty); //prompts user answer and stores referenced answer for displayMessage();
        displayMessage(uAnswer,answer,difficulty); //display the answer to the question
    }

    cout << "Thank you for answering our questions. We, Team Bird, hope you have a good day! :D" << endl;
    cout << "Goodbye" << endl;




    return 0;
}

int displayMenu() //displays difficulty settings and asks the user to choose one
{
    /*
    Function: displayMenu

    Programmers: Isaiah Sule

    Date: 3/28/19
    Parameters: none
    void generateOperator(char & oper, int diff)
    */
    int diff = 1; //default
    do
    {
        cout << "1. Easy" << endl;
        cout << "2. Moderate" << endl;
        cout << "3. Advanced" << endl;
        cout << "Choose your difficulty." << endl;
        cin >> diff;
    }while(cin.fail() || diff> 3 || diff < 1);

    return diff;
}
void generateOperator(char & oper, int diff)
{
    /*
    Function: generateOperator
    Programmer: Isaiah Sule
    Date: 3-28-19
    Parameters: (char) & oper
    Local Variables: (int) chance
    */
    int chance = rand() % 4 + 1;

    switch(chance)
    {
    case 1:
        oper = '+';
        //cout << "Operator is '+'" << endl;
        break;
    case 2:
        oper = '-';
        //cout << "Operator is '-'" << endl;
        break;
    case 3:
    oper = '/';
        //cout << "Operator is '/'" << endl;
        break;
    case 4:
        oper = '*';
        //cout << "Operator is '*'" << endl;
        break;
    default:
        //cout << "inside generateOperator." << endl; //testing
        cout << "Something went wrong. Try again." << endl;
        cout << "Exiting..." << endl;
        break;
    }
    if(oper == '/' && diff < 3) //no division for difficulty 1 and 2
    {
        oper = '*';
    }


}
int randomInt(int numMin, int numMax) //generates two random variables to use for the question
{
    /*
    Function: randomInt
    Programmer: Isaiah Sule
    Date: 3-28-19    Isaiah Sule
    Parameters: none
    Local Variables: (int) x
    */
    int x;
    x = rand() % numMax + numMin;
    return x;
}
void generateOperands(int &a, int &b, int diff)
{
    /*
    Function: generateOperands
    Programmer: Isaiah Sule
    Date: 3-30-29
    Parameters: (int) &a, (int) &b
    */
    switch(diff)
    {
    case 1:
        a = randomInt(1,10);
        b = randomInt(1,10);
        break;
    case 2:
        a = randomInt(1,40);
        b = randomInt(1,30);
        break;
    case 3:
        a = randomInt(1,100);
        b = randomInt(1,100);
        break;
    default:
        //cout << "Inside generateOperands" << endl;
        cout << "Something went wrong" << endl;
        cout << "Exiting..." << endl;
        break;
    }
}
int displayProblem(int a, int b, char oper, double & answer, int diff)
{
    /*
    Function: displayProblem
    Programmer: Isaiah Sule
    Date: 3-30-2019
    Parameters: (int) a, (int) b, (char) oper, (double) & answer
    Local Variables: (int) chance
    */
    answer = 0;//to prevent garbage
    double uAnswer;
    int chance = rand() % 3 + 1; // 1-3
    if(oper == '*' && b > 15 && diff == 2) //reduce the second number's difficulty by replacing the operator w/ an easier one
    {
        switch(chance)
        {
        case 1:
            oper = '-';
            break;
        case 2:
            oper = '+';
            break;
        }
    }
    switch(oper)
    {
    case '+':
        answer = a + b;
        break;
    case '-':
        answer = a - b;
        break;
    case '/':
        answer = a / b;
        if(b > 10)
        {
            cout << "Uh oh, here comes a challenge >:D!" << endl;
        }
        break;
    case '*':
        answer = a * b;
        break;
    default:
        cout << "inside displayProblem" << endl;
        cout << "Something went wrong. Please try again." << endl;
        cout << "Exiting..." << endl;
        break;
    }
    cout << "What is "
         << a <<  " "
         << oper << " "
         << b << "?\n"
         << "round to the nearest whole number\n";

        cin.clear();
        cin.sync();
        cin >> uAnswer;
        if (cin.fail())
        {
            cout << "Your previous answer had a non-numeric character within." << endl;
            cout << "Something went wrong." << endl;
            cout << "The test has been canceled." << endl;
            cout << "Please consult customer support." << endl;
            cout << "Exiting..." << endl;
            exit(EXIT_FAILURE);
        }

    return uAnswer;
}
void displayMessage(double userAnswer, double answer, int diff) //displays to the user if they got the answer correct
{
    /*
    Function: displayMessage
    Programmers: Isaiah Sule
    Date: 3-31-2019
    Parameters: (double) userAnswer, (double) answer
    Local Variables: (static int) questions, incorrect, correct
    */
    static int questions = 0;
    static int correct = 0;
    static int incorrect = 0;

    questions += 1;
    if (userAnswer == answer)
    {
        correct+=1;
        cout << "Correct!" << endl;
    }
    else if(userAnswer != answer)
    {
        incorrect+=1;
        cout << "Incorrect..." << endl;

    }
    cout << "The answer is " << setprecision(4) << answer << endl;
    if (questions >= 10)
    {
        displayFinalResults(correct, incorrect, diff);
    }

}
void displayFinalResults(int correct, int incorrect, int diff)
{
    /*
    Function: displayFinalResults
    Programmers: Isaiah Sule
    Date: 3-31-2019
    Local Variables: (double) percentage
    */
    //testing...
    double percentage = ((10-incorrect) / 10.0) * 100.0;

    cout << left << endl;
    cout << "There were 10 questions." << endl;

    //display header
    cout << left << endl;
    cout << "# of Correct\t"
         << "# of Incorrect\t"
         << "Percentage(%)"
         << endl;

    //display stats
    cout << left << endl;

    cout << correct
         << "\t\t"
         << incorrect
         << "\t\t"
         << percentage
         << endl;

    displayPercentageResults(percentage, diff); //extra :P


}
void displayPercentageResults(double percentage, int diff) //displays a message that is different depending on your percentage
{
    /*
    Function: displayPercentageResults
    Programmers: Isaiah Sule
    Date: 3-31-19
    Parameters: (double) percentage
    */

    if (percentage == 0 && diff  == 1) //Just Stick to Art Achievement
        {
            cout << "...you did your best?" << endl;
            cout << "You unlocked an achievement: 'Just Stick to Art'" << endl;
        }
    else if(percentage == 100 && diff == 3) //Human Calulator? Achievement
    {
            cout << "You used a calculator, didn't you? :P" << endl;
            cout << "You unlocked an achievement: Human Calculator?" << endl;
    }
    else if(percentage < 70)
    {
        cout << "You need to see a tutor..." << endl;
        cout << "You didn't pass. Sorry." << endl;
    }
    else if (percentage > 70  && percentage  < 100)
    {
        cout << "You passed. Good work." << endl;
    }

}
