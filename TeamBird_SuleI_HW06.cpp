/*
Programmer:
Isaiah Sule
Duke Ellington
Pedro Benegas


Date: 3-28-2019 --->>> 3-31-2019

*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

//GLOBAL VARIABLES
int DIFFICULTY;
int MAX_QUESTIONS;


//Prototypes
int displayMenu();
int randomInt();
void generateOperator(char &);
void generateOperands(int &, int &);
int displayProblem(int, int, char, double &);
void displayMessage(double, double);

int main()
{
    unsigned seed = time((NULL)); //needed for rand() function
    srand(seed);
    int a,b; //sum
    double uAnswer;//stores user answer
    double answer;
    char oper; //for operands

    //Choose difficulty
    DIFFICULTY= displayMenu();

    int i = 0;
    do
    {
        generateOperator(oper); //generates operator
        generateOperands(a,b); //generates operands
        uAnswer = displayProblem(a,b,oper,answer); //prompts user answer and stores referenced answer for displayMessage();
        displayMessage(uAnswer,answer); //display the answer to the question
        i++;
    }while(i < MAX_QUESTIONS);

    return 0;
}

int displayMenu() //displays difficulty settings and asks the user to choose one
{
    do
    {
        cout << "1. Easy" << endl;
        cout << "2. Moderate" << endl;
        cout << "3. Advanced" << endl;
        cout << "Choose your difficulty." << endl;
        cin >> DIFFICULTY;
    }while(cin.fail() || DIFFICULTY > 3);

    return DIFFICULTY;
}
void generateOperator(char & oper)
{
    int chance = rand() % 4 + 1;

    switch(chance)
    {
    case 1:
        oper = '+';
        cout << "Operator is '+'" << endl;
        break;
    case 2:
        oper = '-';
        cout << "Operator is '-'" << endl;
        break;
    case 3:
        oper = '/';
        cout << "Operator is '/'" << endl;
        break;
    case 4:
        oper = '*';
        cout << "Operator is '*'" << endl;
        break;
    default:
        cout << "inside generateOperator." << endl; //testing
        cout << "Something went wrong. Try again." << endl;
        cout << "Exiting..." << endl;
        break;
    }
}
int randomInt() //generates two random variables to use for the question
{
    int x;
    switch(DIFFICULTY)
    {
    case 1:
        x = rand() % 9 + 1; //1-9
        break;
    case 2:
        x = rand() % 30 + 1; //1-100
        break;
    case 3:
        x = rand() % 100+ 1; //1- 100
        break;
    default:
        cout << "inside randomInt" << endl;
        cout << "Something went wrong. Run the program again." << endl;
        cout << "Exiting..." << endl;
        break;
    }
    cout << "Inside randomInt(int x), x is " << x << endl; //testing
    return x;
}
void generateOperands(int &a, int &b)
{
    a = randomInt();
    b = randomInt();

    cout << "Testing. Inside generateOperands, a is " << a << endl;
    cout << "Testing. Inside generateOperands, b is " << b << endl;
}
int displayProblem(int a, int b, char oper, double & answer)
{
    answer = 0;//to prevent garbage
    double uAnswer;
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
         << b << "?";

    cin >> uAnswer;
    return uAnswer;
}
void displayMessage(double userAnswer, double answer) //displays to the user if they got the answer correct
{
    static int correct = 0;
    static int incorrect = 0;
    if (userAnswer == answer)
    {
        correct+=1;
        cout << "Correct!" << endl;
    }
    else if (userAnswer != answer)
        incorrect+=1;
        cout << "Incorrect..." << endl;


    cout << "The answer is " << answer << endl;
    cout << "Inside displayMessage. Amount of correct answers: " << correct << endl;
    cout << "Inside displayMessage. Amount of incorrect asnwers: " << incorrect << endl;
}
/*void displayFinalResults(int correct, int incorrect)
{
    int percentage = ((MAX_QUESTIONS-incorrect) / MAX_QUESTIONS) * 100;

    cout << left << endl;
    cout << "# of Correct\t"
         << "# of Incorrect\t"
         << "%"
         << endl;

    cout << MAX_QUESTIONS << endl;
}
*/
