#include <iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
using namespace std;
const int MAX=20;
class Student
{
 int rollno;
 char name[20],city[20];
 char div[MAX];
 int year;
public:
 Student()
{
  strcpy(name,"");
  strcpy(city,"");
  rollno=year=0;
  // div='';
  strcpy(div,"");
}
 Student(int rollno,char name[MAX],int year,char div[MAX],char city[MAX])
 {
  strcpy(this->name,name);
  strcpy(this->city,city);
  this->rollno=rollno;
  this->year=year;
  // this->div=div;
  strcpy(this->div,div);
 }
 int getRollNo()
 {
  return rollno;
 }
 void displayRecord()
 {

  cout<<endl<<setw(5)<<rollno<<setw(20)<<name<<setw(5)<<year<<setw(5)<<div<<setw(10)<<city;
 }
};

class FileOperations
{
 fstream file;
public:
 FileOperations(char* filename)
{
file.open(filename,ios::in|ios::out|ios::ate|ios::binary);
}
 void insertRecord(int rollno, char name[MAX],int year, char div[MAX],char city[MAX])
 {
  Student s1(rollno,name,year,div,city);
  file.seekp(0,ios::end);
  file.write((char *)&s1,sizeof(Student));
  file.clear();
 }
 void displayAll()
 {
  Student s1;
  file.seekg(0,ios::beg);
  while(file.read((char *)&s1, sizeof(Student)))
  {
   s1.displayRecord();
  }
  file.clear();
 }
 void displayRecord(int rollNo)
 {
  Student s1;
  file.seekg(0,ios::beg);
  bool flag=false;
  while(file.read((char*)&s1,sizeof(Student)))
  {
   if(s1.getRollNo()==rollNo)
   {
    s1.displayRecord();
    flag=true;
    break;
   }
  }
  if(flag==false)
  {
   cout<<"\nRecord of "<<rollNo<<"is not present.";
  }
  file.clear();
 }
 void deleteRecord(int rollno)
 {
  ofstream outFile("new.txt",ios::binary);
  file.seekg(0,ios::beg);
  bool flag=false;
  Student s1;

  while(file.read((char *)&s1, sizeof(Student)))
  {
   if(s1.getRollNo()==rollno)
   {
    flag=true;
    continue;
   }
   outFile.write((char *)&s1, sizeof(Student));
  }
  if(!flag)
  {
   cout<<"\nRecord of "<<rollno<<" is not present.";
  }
  file.close();
  outFile.close();
  remove("student.txt");
  rename("new.txt","student.txt");
  file.open("student.txt",ios::in|ios::out|ios::ate|ios::binary);
 }
 ~FileOperations()
 {
  file.close();
  cout<<"\nFile Closed.";
 }
};
int main() {
 ofstream newFile("student.txt",ios::app|ios::binary);
  newFile.close();
  FileOperations file((char*)"student.txt");
     int rollNo,year,choice=0;
     char div[MAX];
     char name[MAX],address[MAX];
     while(choice!=5)
     {
         
         
         cout<<"\nEnter 1 to add record\n";
         cout<<"Enter 2 to display records\n";
         cout<<"Enter 3 to display by roll no\n";
         cout<<"Enter 4 to delete record\n";
         cout<<"Enter 5 to exit\n";
         cout<<"Choose your choice : ";
         cin>>choice;
         switch(choice)
         {
             case 1 : //New Record
               cout<<endl<<"Enter RollNo and name : \n";
               cin>>rollNo>>name;
               cout<<"Enter Year and Division : \n";
               cin>>year>>div;
               cout<<"Enter City : \n";
               cin.ignore();
               cin.getline(address,20);
               file.insertRecord(rollNo,name,year,div,address);
               cout<<"\nRecord Inserted.";
               break;
             case 2 :
              cout<<endl<<setw(5)<<"ROLL"<<setw(20)<<"NAME"<<setw(5)<<"YEAR"<<setw(5)<<"DIV"<<setw(10)<<"CITY";
               file.displayAll();
               break;
             case 3 :
               cout<<"Enter Roll Number";
               cin>>rollNo;
                file.displayRecord(rollNo);

               break;
             case 4:
               cout<<"Enter roll No to delete :";
               cin>>rollNo;
               file.deleteRecord(rollNo);
               break;
            case 5 :break;
         }

     }



 return 0;
}