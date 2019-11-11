#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#define credits 20
using namespace std;
int CREDITS[8]={4,3,3,3,2,1,1,3};
class Student
{
 int rno;
 char name[20];
 char gender;
 int std;
 char grade[8];
 float cgpa;
 
 public:
  void getData();
  void showData();
  void Grade(int y,int x);
  void grade_assign(float marks,int pos);
  int getRno(){return rno;}
}s;
void Student::grade_assign(float marks,int pos){
		if(marks>89&&marks<101){
			grade[pos]='O';
			cgpa=cgpa+(CREDITS[pos]*10);
		}
		else if(marks>=80&&marks<90){
			grade[pos]='E';
			cgpa=cgpa+(CREDITS[pos]*9);
		}
		else if(marks>=70&&marks<80){
		 	grade[pos]='A';
		 	cgpa=cgpa+(CREDITS[pos]*8);
		 }
		else if(marks>=60&&marks<70){
		 	grade[pos]='B';
			cgpa=cgpa+(CREDITS[pos]*7);
		 }
		else if(marks>=50&&marks<60){
		 	grade[pos]='C';
		 	cgpa=cgpa+(CREDITS[pos]*6);
		 }
		else if(marks>=40&&marks<50){
		 	grade[pos]='D';
		 	cgpa=cgpa+(CREDITS[pos]*5);
		 }
		else if(marks<40){
		 	grade[pos]='F';
		 	cgpa=cgpa+(CREDITS[pos]*2);
		 }
}
void Student::Grade(int y,int x){
	if(x==1){
		float internal_marks,midsem_marks,endsem_marks;
		f:
		cout<<"\nENTER INTERNAL MARKS(0-30):";
		cin>>internal_marks;
		if(internal_marks>30||internal_marks<0){
				cout<<"\tINVALID ENTRY\n";
				goto f;
		}
		l:
		cout<<"ENTER THE MIDSEM MARKS(0-20):";
		cin>>midsem_marks;
		if(midsem_marks>20||midsem_marks<0){
			cout<<"\tINVALID ENTRY\n";
			goto l;
		}
		k:
		cout<<"ENTER THE ENDSEM MARKS(0-50):";
		cin>>endsem_marks;
		if(endsem_marks<0||endsem_marks>50){
			cout<<"\tINVALID ENTRY\n";
			goto k;	
		}
		grade_assign(internal_marks+midsem_marks+endsem_marks,y);
	}
	else if(x==2){
		float lab_record,quiz,test;
		u:
		cout<<"\nENTER THE MARKS FOR LAB RECORD(0-10):";
		cin>>lab_record;
		if(lab_record>10||lab_record<0){
			cout<<"\tINVALID ENTRY\n";
			goto u;
		}
		i:	
		cout<<"ENTER THE MARKS FOR QUIZ AND INTERNAL(0-50):";
		cin>>quiz;
		if(quiz>50||quiz<0){
			cout<<"\tINVALID ENTRY\n";
			goto i;
		}
		t:
		cout<<"ENTER THE MARKS OF LAB TEST(0-40):";
		cin>>test;
		if(test>40||test<0){
			cout<<"\tINVALID ENTRY\n";
			goto t;
		}
		grade_assign(lab_record+quiz+test,y);		
	}
}

void Student::getData()
{
cgpa=0.0;

 cout<<"\n\nEnter Student Details......\n";
 cout<<"Enter ROLL No.          : "; cin>>rno;
 cout<<"Enter Full Name         : "; cin.ignore(); cin.getline(name,20);
 cout<<"Enter Gender (M/F)      : "; cin>>gender;
 cout<<"\t\t:Marks: "<<endl;
cout<<"__________________________________________________________"<<endl;
 cout<<"\tDISCRETE MATHEMATICS:\n";
 cout<<"__________________________________________________________"<<endl;
 Grade(0,1);
 cout<<"__________________________________________________________"<<endl<<endl;
 cout<<"\tDATA STRUCTURE AND ALGORITHM:\n";
 cout<<"__________________________________________________________"<<endl;
 Grade(1,1);
 cout<<"__________________________________________________________"<<endl<<endl;
 cout<<"\tPRINCIPLE OF DIGITAL COMMMUNICATION:\n";
 cout<<"__________________________________________________________"<<endl;
 Grade(2,1);
 cout<<"__________________________________________________________"<<endl<<endl;
 cout<<"\tOBJECT ORIENTED PROGRAMMING:\n";
 cout<<"__________________________________________________________"<<endl;
 Grade(3,1);
 cout<<"__________________________________________________________"<<endl<<endl;
 cout<<"\tPROBABILITY & STATISTICS:\n";
 cout<<"__________________________________________________________"<<endl;
 Grade(4,1);
 cout<<"__________________________________________________________"<<endl<<endl;
 cout<<"\tDATA STRUCTURE LABORATORY:\n";
 cout<<"__________________________________________________________"<<endl;
 Grade(5,2);
 cout<<"__________________________________________________________"<<endl<<endl;
 cout<<"\tOBJECT ORIENTED PROGRAMMING LABORATORY:\n";
 cout<<"__________________________________________________________"<<endl;
 Grade(6,2);
 cout<<"__________________________________________________________"<<endl<<endl;
 cout<<"\tENGINEERING ECONOMICS:\n";
 cout<<"__________________________________________________________"<<endl;
 Grade(7,1);
 cout<<"__________________________________________________________"<<endl;
 cout<<endl;
 cgpa=cgpa/credits;
}

void Student::showData()
{
 cout<<"\n\n.......Student Details......\n";
 cout<<"ROLL No.          : "<<rno<<endl;
 cout<<"Full Name         : "<<name<<endl;
 cout<<"Gender            : "<<gender<<endl;
 cout<<"===========================================================\n";
 cout<<"...................SEMESTER GRADE REPORT...................\n";
 cout<<"===========================================================\n";
 cout<<"DISCRETE MATHEMATICS:                        |"<<grade[0]<<endl;
 cout<<"DATA STRUCTURE AND ALGORITHM:                |"<<grade[1]<<endl;
 cout<<"PRINCIPLE OF DIGITAL COMMMUNICATION:         |"<<grade[2]<<endl;
 cout<<"OBJECT ORIENTED PROGRAMMING:                 |"<<grade[3]<<endl;
 cout<<"PROBABILITY & STATISTICS:                    |"<<grade[4]<<endl;
 cout<<"DATA STRUCTURE LABORATORY:                   |"<<grade[5]<<endl;
 cout<<"OBJECT ORIENTED PROGRAMMING LABORATORY:      |"<<grade[6]<<endl;
  cout<<"ENGINEERING ECONOMICS:                       |"<<grade[7]<<endl;
 cout<<"===========================================================\n";
 cout<<"\tCGPA        : "<<cgpa<<endl;
 cout<<"===========================================================\n";
 cout<<endl;
}

void addData()
{
 ofstream fout;
 fout.open("Students.dat",ios::binary|ios::out|ios::app);
 s.getData();
 fout.write((char*)&s,sizeof(s));
 fout.close();
 cout<<"\n\nData Successfully Saved to File....\n";
}

void displayData()
{
 ifstream fin;
 fin.open("Students.dat",ios::in|ios::binary);
 while(fin.read((char*)&s,sizeof(s)))
 {
  s.showData();
 }
 fin.close();
 cout<<"\n\nData Reading from File Successfully Done....\n";
}

void searchData()
{
 int n, flag=0;
 ifstream fin;
 fin.open("Students.dat",ios::in|ios::binary);
 cout<<"Enter ROLL Number you want to search : ";
 cin>>n;
 
 while(fin.read((char*)&s,sizeof(s)))
 {
  if(n==s.getRno())
  {
   cout<<"The Details of ROLL No. "<<n<<" shown herewith:\n";
   s.showData();
   flag++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"The ROLL No. "<<n<<" not found....\n\n";
 cout<<"\n\nData Reading from File Successfully Done....\n";
}

void deleteData()
{
 int n, flag=0;
 ifstream fin;
 ofstream fout,tout;

 fin.open("Students.dat",ios::in|ios::binary);
 fout.open("TempStud.dat",ios::out|ios::app|ios::binary);
 tout.open("TrashStud.dat",ios::out|ios::app|ios::binary);

 cout<<"Enter ROLL Number you want to move to Trash : ";
 cin>>n;
 
 while(fin.read((char*)&s,sizeof(s)))
 {
  if(n==s.getRno())
  {
   cout<<"The Following ROLL No. "<<n<<" has been moved to Trash:\n";
   s.showData();
   tout.write((char*)&s,sizeof(s));
   flag++;
  }
  else
  {
   fout.write((char*)&s,sizeof(s));
  }
 }
 fout.close();
 tout.close();
 fin.close();
 if(flag==0)
  cout<<"The ROLL No. "<<n<<" not found....\n\n";
 remove("Students.dat");
 rename("tempStud.dat","Students.dat");
}

void getTrash()
{
 ifstream fin;
 fin.open("TrashStud.dat",ios::in|ios::binary);
 while(fin.read((char*)&s,sizeof(s)))
 {
  s.showData();
 }
 fin.close();
 cout<<"\n\nData Reading from Trash File Successfully Done....\n";
}

void modifyData()
{
 int n, flag=0, pos;
 fstream fio;

 fio.open("Students.dat",ios::in|ios::out|ios::binary);
 
 cout<<"Enter ROLL Number you want to Modify : ";
 cin>>n;
 
 while(fio.read((char*)&s,sizeof(s)))
 {
  pos=fio.tellg();
  if(n==s.getRno())
  {
   cout<<"The Following ROLL No. "<<n<<" will be modified with new data:\n";
   s.showData();
   cout<<"\n\nNow Enter the New Details....\n";
   s.getData();
   fio.seekg(pos-sizeof(s));
   fio.write((char*)&s,sizeof(s));
   flag++;
  }
 }
 fio.close();
 
 if(flag==0)
  cout<<"The ROLL No. "<<n<<" not found....\n\n";
}

void project()
{
 int ch;
 do
 {
  system("cls");
  cout<<"============================================================================================================\n";
  cout<<".....................................STUDENT DATA MANAGEMENT SYSTEM.....................................\n";
  cout<<"============================================================================================================\n";
  cout<<"0. Exit from Program\n";
  cout<<"1. Write Data to File\n";
  cout<<"2. Read Data From File\n";
  cout<<"3. Search Data From File\n";
  cout<<"4. Delete Data From File\n";
  cout<<"5. Get Deleted Records from Trash file\n";
  cout<<"6. Modify Data in File\n";
  cout<<"Enter your choice  : ";
  cin>>ch;
  system("cls");
  switch(ch)
  {
   case 1: addData(); break;
   case 2: displayData(); break;
   case 3: searchData(); break;
   case 4: deleteData(); break;
   case 5: getTrash(); break;
   case 6: modifyData(); break;
  }
  system("pause");
 }while(ch);
}

int main()
{
 project();
}

