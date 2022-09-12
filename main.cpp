/*Header file*/
#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include<windows.h>
using namespace std;

/*Function for setting cursor position in the console window*/
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/* Class Definition*/
class applicant
{
    /*Defining data member for applicant details*/
    string name;
    int age;
    string address;
    int monthly_salary;
    int house_loan;
    int personal_loan;
    int number_chq_bounce;
    char own_house;
    char spouse_working;
    char dependent_parent;
    int company_tier;
public:
    void get_data();
    void display_score();
    int calculate_liability();
};
/* Function for receiving and store applicant details*/
void applicant :: get_data()
{
    system("cls");
    cout<<"name of applicant : ";
    getline(cin, name);
    cout<<"Age : ";
    cin>>age;

    cin.clear();
    cin.ignore(1000, '\n');

    cout<<"Address : ";
    getline(cin, address);

    cin.clear();
    cin.ignore(1000, '\n');

    cout<<"Monthly salary : ";
    cin>>monthly_salary;
    cout<<"Total home loan EMI : ";
    cin>>house_loan;
    cout<<"Total personal loan : ";
    cin>>personal_loan;
    cout<<"Number of cheque bounce : ";
    cin>>number_chq_bounce;
    cout<<"Own a house? (y or n) : ";
    cin>>own_house;
    cout<<"Spouse Working? (y or n) : ";
    cin>>spouse_working;
    cout<<"Dependent on parents? (y or n) : ";
    cin>>dependent_parent;
    cout<<"Company Tier (1, 2 or 3) : ";
    cin>>company_tier;
}
/* calculating Credit score */
int applicant :: calculate_liability()
{
    int score = 0;  /* initializing the score 0 */
    int liability;

    /* Count score according to age*/
    if(age>22 && age <= 30)
        score = score + 2;
    if(age>30 && age <= 35)
        score = score + 1;
    else
        score = score - 1;

    /* Count score according to monthly salary*/
    liability = house_loan + personal_loan;
    if(liability <= monthly_salary / 4)
        score = score + 5;
    if(liability > monthly_salary / 4 && liability <= monthly_salary / 3)
        score = score + 3;
    if(liability > monthly_salary / 3 && liability <= monthly_salary / 2)
        score = score + 1;
    if(liability > monthly_salary / 2)
        score = score - 1;

    /* Count score according to number of cheque bounce*/
    if(number_chq_bounce > 1)
        score = score - 2;
    if(number_chq_bounce == 1)
        score = score - 1;
    if(number_chq_bounce == 0)
        score = score + 1;

    /* Count score according to loan*/
    if(personal_loan > house_loan)
        score = score - 1;
    else
        score = score +1;

    /* Count score according to house,working and parent dependency */
    if(own_house == 'y' || own_house == 'Y')
        score = score + 1;
    if(spouse_working == 'y' || spouse_working == 'Y')
        score = score + 1;
    if(dependent_parent == 'n' || dependent_parent == 'N')

        /* Count score according to company tier */
        if(company_tier == 1)
            score = score + 3;
    if(company_tier == 2)
        score = score + 2;
    else
        score = score + 1;
    return (score);
}
/* Function for displaying credit */
void applicant :: display_score()
{
    int credit_score = calculate_liability();
    system("cls");

    if(credit_score > 9)
        cout<<"The applicant "<<name<<" is at low risk.\nCredit score = "<<credit_score<<"\nCredit can be given."<<endl;
    else
    {
        if(credit_score > 5 && credit_score <= 9)
            cout<<"The applicant "<<name<<" is at avarage risk.\nCredit score = "<<credit_score<<"\nCredit can be given due to precaution."<<endl;
        else
            cout<<"The applicant "<<name<<" is at high risk.\nCredit score = "<<credit_score<<"\nCredit can not be given."<<endl;
    }
    getch();
}
/* Main Function */
int main()
{
    char flag = 'f';
    applicant a;
    char ch;
    while(1)
    {
        system("cls");
        gotoxy(40, 8);
        cout<<"Credit Calculating";
        gotoxy(31, 9);
        cout<<"***********************************";
        gotoxy(22, 12);
        cout<<"1 - Enter loan applicant's details.";
        gotoxy(22, 13);
        cout<<"2 - Display Credit Score.";
        gotoxy(22, 14);
        cout<<"3 - Exit.";
        gotoxy(22, 16);
        cout<<"Select your option : ";
        ch = getch();
        switch(ch)
        {
            case('1') :
            {
                a.get_data();
                flag = 't';
                break;
            }
            case('2') :
            {
                if(flag == 'f')
                {
                    gotoxy(22,18);
                    cout<<"Applicant details not entered.press any key to continue...";
                    getch();
                }
                else
                {
                    a.display_score();
                }
                break;
            }
            case('3') :
            {
                exit(1);
                break;
            }
            default :
            {
                gotoxy(22, 18);
                cout<<"Invalid choice. Press any key ...";
                getch();
            }
        }
    }
}


