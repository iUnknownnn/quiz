#include <iostream>
#include <fstream>
#include <conio.h>

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
        bool compareAnswers(string userAnswer)
        {
            if(userAnswer==correct_answer)
                return true;
            else
                return false;
        }
};

void showMenu()
{
    cout<<"**************************************************"<<endl;
    cout<<"*                                                *"<<endl;
    cout<<"*                SIMPLE C++ QUIZ                 *"<<endl;
    cout<<"*                made by UnknowN                 *"<<endl;
    cout<<"*                                                *"<<endl;
    cout<<"**************************************************"<<endl;
    cout<<"1. Start quiz"<<endl;
    cout<<"2. Add question"<<endl;
    cout<<"3. Show number of questions"<<endl;
    cout<<"0. Quit"<<endl;
    cout<<endl<<"Your choice: ";
}

int countQuestions(string path)
{
    fstream file;
    string line;
    int lines=0;
    file.open(path, ios::in);
    while(!file.eof())
    {
        getline(file,line);
        lines++;
    }
    file.close();
    return lines/6;
}

void playQuiz(Question question[], int number_of_questions)
{
    cout<<endl;
    int points=0;
    string inputAnswer;
    for(int i=0; i<number_of_questions; i++)
    {
        question[i].showQuestion();
        cout<<endl<<"Your answer: ";
        cin>>inputAnswer;
        if(question[i].compareAnswers(inputAnswer))
        {
            cout<<endl<<"Correct answer! ;)"<<endl<<endl;
            points++;
        }
        else
        {
            cout<<endl<<"Wrong answer! :("<<endl<<endl;
        }
    }
    cout<<"You ended up with "<<points<<"/"<<number_of_questions<<" points"<<endl<<"Press any key to continue... ";
    getch();
    cout<<endl<<endl;
}

int main()
{
    int user_choice;
    string path="txts\\quiz.txt";
    fstream file;
    string line, content, a, b, c, d, correct;
    int questions=countQuestions(path);
    Question *question=new Question[questions];
    file.open(path, ios::in);
    while(!file.eof())
    {
        for(int i=0; i<questions; i++)
        {
            getline(file,line);
            content=line;
            getline(file,line);
            a=line;
            getline(file,line);
            b=line;
            getline(file,line);
            c=line;
            getline(file,line);
            d=line;
            getline(file,line);
            correct=line;
            question[i].setValues(content,a,b,c,d,correct);
        }
    }
    file.close();
    while(true)
    {
        showMenu();
        cin>>user_choice;
        switch(user_choice)
        {
            case 1:
                playQuiz(question, questions);
            break;
            case 3:
                cout<<"Number of questions: "<<countQuestions(path)<<endl;
            break;
            case 0:
                cout<<endl<<"Bye bye!"<<endl;
                exit(0);
            break;
            default:
                cout<<endl<<"Wrong input... Try again"<<endl<<endl;
            break;
        }
    }
    return 0;
}