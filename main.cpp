/******************************************************************************
Name: Priyanjali Rudra
Program 2: TwentyFour
09/21/23

program that: (a) finds and prints a range, specified by the user, of the 3,185 solutions to the game TwentyFour and (b) randomly picks one of the solutions to play with the user.  
*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

float compute(int op, float a, float b) {
  float result;
  if (op == 0) {
    // carry out the operation
    result = a + b;
  }
  else if (op == 1) {
    result = a - b;
  }
  else if (op == 2) {
    result = a / b;
  }
  else if (op == 3) {
    result = a * b;
  }
  return result;
}

char symbol(int op) {
  float opChar;
  if (op == 0) {
    // save the correct operator symbol
    opChar = '+';
  }
  else if (op == 1) {
    opChar = '-';
  }
  else if (op == 2) {
    opChar = '/';
  }
  else if (op == 3) {
    opChar = '*';
  }
  return opChar;
}

float userInput(float a,float b,char op) {
  float userAnswer = a;
  if (op == '+') {
    userAnswer += b;
  }
  else if (op == '-') {
    userAnswer -= b;
  }
  else if (op == '/') {
    userAnswer /= b;
  }
  else if (op == '*') {
    userAnswer *= b;
  }
  return userAnswer;
}

int main()
{
    cout << "Welcome to the game of Twenty Four." << endl;
    cout << "Combine the four numbers shown below," << endl;
    cout << "in the order shown below, using the operators" << endl;
    cout << "(+, -, *, / ) to yield the value 24." << endl;
    cout << "**** Begin Debug Display ****" << endl;

    int startSolution,endSolution;
    string userInputOperators;
    int i = 1;
    float result;
  
    // 4 digits for puzzle
    float a,b,c,d;
    float puzzleA,puzzleB,puzzleC,puzzleD;

    // 0 -> x+y, 1 -> x-y, 2 -> x/y, 3 -> x*y
    char op1Char,op2Char,op3Char;
    char puzzleOp1,puzzleOp2,puzzleOp3;
  
    // puzzle no.
    srand(time(0));
    int puzzle = rand() % 3185 + 1;
  
    cout << "Enter the beginning solution to be printed: " << endl;
    cin >> startSolution;
    cout << "Enter the end solution to be printed: " << endl;
    cin >> endSolution;
  
    if (endSolution < startSolution) {
        cout << "error" << endl;
    }

 // a op1 b op2 c op3 d = 24

 // Main Loop Starts Here:
    for (a = 1; a <= 9; a++){ //digit1
        for (b = 1; b <= 9; b++){ //digit2
            for (c = 1; c <= 9; c++){ //digit3
                for (d = 1; d <= 9; d++){ //digit4
//-------*operators (+,-,*,/) defined + iterating*----------------------
// a op1 b         
                    for (int op1 = 0; op1 <= 3; ++op1) {
                        op1Char = symbol(op1);
// result op2 c
                        for (int op2 = 0; op2 <= 3; ++op2) {
                            op2Char = symbol(op2);
// result op3 d
                            for (int op3 = 0; op3 <= 3; ++op3) {
                                op3Char = symbol(op3);
                                result = compute(op1, a, b);
                                result = compute(op2, result, c);
                                result = compute(op3, result, d);
//operator loop ends here
//------------------------check and print-------------------------
                                if (result == 24) {
                                    if(i == puzzle) {
                                        puzzleA = a;
                                        puzzleB = b;
                                        puzzleC = c;
                                        puzzleD = d;
                                        puzzleOp1 = op1Char;
                                        puzzleOp2 = op2Char;
                                        puzzleOp3 = op3Char;
                                    }  
                                        if((i <= endSolution) && (i >= startSolution)) {
                                            cout << i << ":" << a << op1Char << b << op2Char << c << op3Char << d;
                                            cout << "=24" << endl;
                                        }
                                    i++;
                                }
//---------------------check and print ends here-----------------
                            }//op3
                        }//op2
                    }//op1
                }//d
            }//c
        }//b
    }//a
    cout << "Puzzle chosen is #" << puzzle << endl;
    cout << "**** End of the Debug Display ****" << endl;
  
    cout << "The numbers to use are " << puzzleA << " " << puzzleB << " "; 
    cout << puzzleC << " " << puzzleD << endl;

    cout << "Enter the three operators to be used (+, -, * or / ):" << endl;
  
    string answerOperators;
    cin >> answerOperators;
  
//check
    while(answerOperators.length() != 3){
      cout << "invalid number of characters entered, please try again" << endl;
      cin >> answerOperators;
    }
  
    for(char op : answerOperators){
      while((op != '+') && (op != '-') && (op != '*') && (op != '/')){
        cout << "invalid characters entered, please try again" << endl;
        cin >> answerOperators;
      }
    }
  
    float userResult = puzzleA;
    for(char op : answerOperators){
      if (op == '+') {
        userResult = userInput(userResult,puzzleB,'+');
      }
      else if (op == '-') {
        userResult = userInput(userResult,puzzleB,'-');
      }
      else if (op == '/') {
        userResult = userInput(userResult,puzzleB,'/');
      }
      else if (op == '*') {
        userResult = userInput(userResult,puzzleB,'*');
      }
    }

  // User Result Breakdown:
    float temp1 = userInput(puzzleA,puzzleB,answerOperators.at(0));
    cout << puzzleA << answerOperators.at(0) << puzzleB << "=" << temp1 << endl;

    float temp2 = userInput(temp1,puzzleC,answerOperators.at(1));
    cout << temp1 << answerOperators.at(1) << puzzleC << "=" << temp2 << endl;

    float temp3 = userInput(temp2,puzzleD,answerOperators.at(2));
    cout << temp2 << answerOperators.at(2) << puzzleD << "=" << temp3 << endl;

    if(temp3 == 24.0) {
      cout << "Well done!" << endl;
    }
    else {
      cout << "incorrect: The correct answer was: " ;
      cout << puzzleA << puzzleOp1 << puzzleB << puzzleOp2 << puzzleC << puzzleOp3 << puzzleD;
    }
  return 0;
}//main
