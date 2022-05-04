#include <iostream>
#include <fstream>

using namespace std;

class Question{
    private:
        string content, answerA, answerB, answerC, answerD, correct_answer;
    public:
        void setValues(string loadedContent, string loadedAnswerA, string loadedAnswerB, string loadedAnswerC, string loadedAnswerD, string loadedCorrect_answer)
        {
            content=loadedContent;
            answerA=loadedAnswerA;
            answerB=loadedAnswerB;
            answerC=loadedAnswerC;
            answerD=loadedAnswerD;
            correct_answer=loadedCorrect_answer;
        }
        void showQuestion()
        {
            cout<<content<<endl;
            cout<<answerA<<endl;
            cout<<answerB<<endl;
            cout<<answerC<<endl;
            cout<<answerD<<endl;
        }
};

int main()
{
    
    return 0;
}