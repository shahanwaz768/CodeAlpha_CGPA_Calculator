// TASK 1: CGPA CACULATOR
#include<iostream>
#include<iomanip>
using namespace std;
class CGPA
{
    string name;
    string sub[50][50];
    int sem;
    int marks;
    int credit[50][50];
    int n;
    int i;
    int j;
    float grade[50][50];
    int total_credit=0;
    float total_grade_points=0;
    float total_gpa=0;
    float gpa[10];
    float cgpa;
    public:
    void getinfo()
   {
        cout<<"enter student name:"<<endl;
        getline(cin,name);
        cout<<"enter current semester:"<<endl;
        cin>>sem;
        for(i=1;i<sem;i++) 
        {
        cout<<"enter number of courses(subject) in semester "<<i<<":"<<endl;
        cin>>n;
        for(j=1;j<=n;j++)
        {
            cout<<"enter name of course "<<j<<":"<<endl ;
            cin.ignore();
            getline(cin,sub[i][j]);
            cout<<"enter credit hour(from 1-4) of course "<<j<<":"<<endl; 
            cin>>credit[i][j];
            cout<<"enter grade(from 0-10) of course "<<j<<":"<<endl;
            cin>>grade[i][j];
            total_credit=total_credit+credit[i][j];
            total_grade_points=total_grade_points+grade[i][j]*credit[i][j];
        }
        gpa[i]=total_grade_points/total_credit;
        total_gpa=total_gpa+gpa[i];
        }
    }
    void show()
    {
        cout<<endl;
        cout<<"   .....RESULT....."<<endl;
        cout<<"student name: "<<name<<endl;
        for(i=1;i<sem;i++)
        {
            cout<<"   semester "<<i<<" details:"<<endl;
            for(j=1;j<=n;j++)
            { 
                cout<<"course name: "<<sub[i][j]<<" | "<<"grade: "<<grade[i][j]<<" | "<<"credits: "<<credit[i][j]<<endl;
        } 
        cout<<"GPA of semester "<<i<<": ";
        cout<<fixed<<setprecision(2);
        cout<<gpa[i]<<endl;
    }
        if(sem>1)
        {
            cout<<endl;
        cout<<"   CGPA: ";
        cgpa=total_gpa/(sem-1);
        cout<<cgpa;
        }
        else
        {
            cout<<"..CGPA can't be calculated..";
        }
    } 
};
int main()
{
    CGPA C;
    C.getinfo();
C.show();
}
