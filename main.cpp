#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

float ReadNumber(const string& promt) {
    cout << promt << endl;
    float number;
    while (!(cin >> number)) {
        cout << "Invalid value" << promt;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return number;
}
float  ReadUserNumber() {
    float number;
    while (!(cin >> number)) {
        cout << "Invalid value";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return number;
}


int ReadPositiveNumber(const string& prompt) {
    int number;
    cout << prompt;
    while (!(cin >> number) || number < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a positive number: ";
    }
    return number;
}

int ReadNumberInRange(const string& message, int from, int to) {
    int number;
    cout << message << " [" << from << " - " << to << "]: ";
    while (!(cin >> number) || number < from || number > to) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a number between " << from << " and " << to << ": ";
    }
    return number;
}
// Random‑Number & Key‑Generation Functions
int RandomNumber(int From, int To) {
    if (From > To) {
        cout << "Inavlid Range Enter a Valid Range\n";
        return -1;
    }
    int RandomNumber = rand() % (To - From + 1) + From;
    return RandomNumber;
}


///////////////////////////////////////////////////////////////////
void ResetScreen() {
    system("color 07");

}
void PrintLines(int numbers) {
    for (int i = 0; i < numbers; i++) {
        cout << "-";
    }
    cout << endl;
    
}

enum class  enQuestionLevel{Easy=1,Medium=2,Hard=3,Mix=4};
enum class enQuestionType{Add=1,Sub=2,Mul=3,Div=4,Mix=5};
struct stQuizResult {
    short NumberOfQuesion;
    enQuestionLevel QuestionLevel;
    enQuestionType QuestionType;
    short NumberOfRightAnswer;
    short NumberOfWrongAnswers;







};
struct stQuizInfo {
   short QuestionNumber;
   float   Number1;
   float  Number2;
   enQuestionLevel QuestionLevel;
   enQuestionType QuestionType;
   float  Result;
   float  UserInput;

};
enQuestionLevel ReadQuestionLevel() {
    short QuestionLevel = ReadNumberInRange("Enter Question Level [1]:Easy , [2]:Medium, [3]Hard, [4]Mix", 1, 4);
   
    return static_cast<enQuestionLevel>(QuestionLevel);

}
enQuestionType ReadQuesionType() {
    short QuestionType = ReadNumberInRange("Enter The Question Type [1]:Addition ,[2]:Subtraction ,[3]:Multiblication,[4]:Division, [5]Mix", 1, 5);
    cout << "\n";
    return static_cast<enQuestionType>(QuestionType);

}
char ReturnOperation(enQuestionType QuestionType) {
    switch (QuestionType) {
    case enQuestionType::Add:return '+'; break;
    case enQuestionType::Sub:return '-'; break;
    case enQuestionType::Mul:return '*'; break;
    case enQuestionType::Div:return '/'; break;
    case enQuestionType::Mix: {
        enQuestionType randomtype= static_cast<enQuestionType>(RandomNumber(1, 4));
        return ReturnOperation(randomtype); break;
    }
    }
}
float  GetTheResult(float  number1, float  number2, char OpType) {
    switch (OpType) {
    case '+': return number1 + number2; break;
    case '-': return number1 - number2; break;
    case '*': return number1 * number2; break;
    case '/': return number1 / number2; break;


    }
}
string GetQuestionLevel(enQuestionLevel QuestionLevel) {
    switch (QuestionLevel) {
    case enQuestionLevel::Easy: return "Easy"; break;
    case enQuestionLevel::Hard: return "Hard"; break;
    case enQuestionLevel::Mix: return "Mix"; break;
    case enQuestionLevel::Medium: return"Medium"; break;

    }
}
string GetOperationType(enQuestionType OpType) {
    switch (OpType) {
    case enQuestionType::Add: return "+"; break;
    case enQuestionType::Sub: return "-"; break;
    case enQuestionType::Mul: return "*"; break;
    case enQuestionType::Div: return "/"; break;
    case enQuestionType::Mix: return "Mix"; break;

    }
}
void PrintTheEquation(float   &number1, float   &number2, enQuestionLevel &QuestionLevel, enQuestionType &QuestionType , float &result) {
    char OpType = ReturnOperation(QuestionType);
      if (QuestionLevel == enQuestionLevel::Easy) {
        number1 = RandomNumber(1, 10);
        number2 = RandomNumber(1, 10);

    }
     else if (QuestionLevel == enQuestionLevel::Medium) {
         number1 = RandomNumber(10, 50);
         number2 = RandomNumber(10, 50);

    }
     else if (QuestionLevel == enQuestionLevel::Hard) {
        number1 = RandomNumber(50, 1000);
        number2 = RandomNumber(50, 1000);

        }
     else if (QuestionLevel == enQuestionLevel::Mix) {
         number1 = RandomNumber(1, 1000);
         number2 = RandomNumber(1, 1000);

    }
      
     cout << number1 << "\n"  << number2 <<" "<<OpType<<"\n"; PrintLines(3);
     result= GetTheResult(number1, number2, OpType);



}
void PrintTheResult(float  &UserInput, float  &Result, stQuizResult& QuizResult) {
    double tolarnc = 0.1;

    if ((fabs(UserInput - Result))<=0.1) {
        cout << "Right Answer :-)\n";
        system("color 20");
        QuizResult.NumberOfRightAnswer++;
        
    }
    else {
        cout << "Wrong  Answer :-(\n";
        cout << "The right answer is " << Result << "\n";
        system("color 4F");
        QuizResult.NumberOfWrongAnswers++;
    }
}
void PrintTheHeader(int QuestionCurrentNumber, int TotalNumberOfQuestion) {
    cout << "Question" << "[" << QuestionCurrentNumber << "/" << TotalNumberOfQuestion<<"]" << "\n" << endl;
}
void PrintTheUserResult(int  NumberOfRightAnswer, int NumberOfWrongAnswers) {
    if (NumberOfRightAnswer > NumberOfWrongAnswers) {
        system("color 20");
        cout << "Final Result is Pass  :-)";
    }
    else {
        system("color 4F");
        cout << "Final Result is Fail  :-( ";
    }
    
}
void PrintTheEndHeader(int NumberOfRightAnswer, int NumberOfWrongAnswers, enQuestionLevel &QuestionLevel, enQuestionType &QuestionType, int& NumberOFQuestions) {
    PrintLines(40);
    PrintTheUserResult(NumberOfRightAnswer, NumberOfWrongAnswers);
    cout << endl;
    PrintLines(40);
    cout << "\n";
    cout << "Number of Question is : " << NumberOFQuestions << "\n";
    cout << "Question Level \t" << GetQuestionLevel(QuestionLevel) << "\n";
    cout << "Operation Type \t" << GetOperationType(QuestionType) << "\n";
    cout << "Number Of Right Answers :" << NumberOfRightAnswer << "\n";
    cout << "Number Of Wrong Answers :" << NumberOfWrongAnswers << "\n";
    PrintLines(40);
}
void StartQuiz(int NumberOfRounds) {
    stQuizInfo QuizInfo;
    stQuizResult QuizResult = {};
    QuizInfo.QuestionLevel = ReadQuestionLevel();
    QuizInfo.QuestionType = ReadQuesionType();
    for (int i = 1; i <= NumberOfRounds; i++) {
      
     PrintTheHeader(i, NumberOfRounds);
     PrintTheEquation(QuizInfo.Number1, QuizInfo.Number2, QuizInfo.QuestionLevel, QuizInfo.QuestionType,QuizInfo.Result);
     QuizInfo.UserInput = ReadUserNumber();
     PrintTheResult(QuizInfo.UserInput, QuizInfo.Result,QuizResult);
 




    }
    PrintTheEndHeader(QuizResult.NumberOfRightAnswer, QuizResult.NumberOfWrongAnswers, QuizInfo.QuestionLevel, QuizInfo.QuestionType, NumberOfRounds);


}




void StartTheQuiz() {
    char PlayAgain = 'Y';
    do {


        ResetScreen();
        int NumberOfRounds = ReadPositiveNumber("Enter The Number of Questions   ");
        StartQuiz(NumberOfRounds);
        cout << "Do you want to play again (Y,N) :";
       
        cin >> PlayAgain;
        cout << "\n\n\n\n\n\n\n\n\n\n\n";






    } while (PlayAgain == 'Y' || PlayAgain == 'y');


}






int main()
{
    srand((unsigned)time(NULL));
    StartTheQuiz();
}
