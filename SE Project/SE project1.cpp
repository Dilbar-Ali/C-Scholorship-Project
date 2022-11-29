#include <iostream>
#include <fstream>
#include<string>
using namespace std;
int ID;
struct Student {
    int id;
    string name;
    int age;
    string degree;
    int semesterNo;
    int salary;
};
void addStudent() {
    Student student;
    cout << "\n\tEnter The ID  ";
    cin >> student.id;
    cout << "\n\tEnter student name : ";
    cin.get();
    getline(cin, student.name); 
    cout << "\n\tEnter student age : ";
    cin >> student.age;
    cout << "\n\tEnter student degree : ";
    cin >> student.degree;
    cout << "\n\tEnter student semester number : ";
    cin >> student.semesterNo;
    cout << "\n\tEnter Total salary ";
    cin >> student.salary;
    ID++;
    ofstream write;
    write.open("student.txt");
    write << "\n" << ID;
    write << "\n" << student.name ;
    write << "\n" << student.age ;
    write << "\n" << student.degree ;
    write << "\n" << student.semesterNo;
    write << "\n" << student.salary;
    write.close();
    write.open("id.txt");
    write << ID;
    write.close();
    cout << "\n\tData save to file";
}
void print(Student s) {
	 if (s.salary>=45000){
	 	cout << "\n\t---Student Data---";
    	cout << "\n\tName is : " <<s.name<<endl;
    	cout<<"\n\tNot eligible !";
	}
   else{
   	cout << "\n\tName is : " <<s.name<<endl;
   	cout<<"\n\t Eligible student !";
   }
    cout << "\n\t---Student Data---";
    cout << "\n\tID is : " << s.id;
    cout << "\n\tName is : " << s.name;
    cout << "\n\tAge is : " << s.age;
    cout << "\n\tDegree is : " << s.degree;
    cout << "\n\tSmester Number is : " << s.semesterNo;
    cout << "\n\tmonthly salary is : " << s.salary<<endl;  
}
void readData() {
    Student student;
    ifstream read;
    read.open("student.txt");
    while (!read.eof()) {
        read >> student.id;
        read.ignore();
        getline(read, student.name);
        read >> student.age;
        read >> student.degree;
        read >> student.semesterNo;
        read >> student.salary;
        print(student);
    }
    read.close();
}

int searchData() {
    int id;
    cout << "\n\tEnter student id want to search : ";
    cin >> id;
    Student student;
    ifstream read;
    read.open("student.txt");
    while (!read.eof()) {
        read >> student.id;
        read.ignore();
        getline(read, student.name);
        read >> student.age;
        read >> student.degree;
        read >> student.semesterNo;
        read >> student.salary;
        if (student.id == id) {
            print(student);
            return id;
        }
    }
}
void deleteData() {
    int id = searchData();
    cout << "\n\tYou want to delete record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        Student student;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("student.txt");
        while (!read.eof()) {
            read >> student.id;
            read.ignore();
            getline(read, student.name);
            read >> student.age;
            read >> student.degree;
            read >> student.semesterNo;
            read >> student.salary;
            if (student.id != id) {
                tempFile << "\n" << student.id;
                tempFile << "\n" << student.name;
                tempFile << "\n" << student.age;
                tempFile << "\n" << student.degree;
                tempFile << "\n" << student.semesterNo;
                tempFile << "\n" << student.salary;
            }
        }
        read.close();
        tempFile.close();
        remove("student.txt");
        rename("temp.txt", "student.txt");
        cout << "\n\tData deleted successfuly ";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}
void updateData() {
    int id = searchData();
    cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        Student newData;
        cout << "\n\tEnter student name : ";
        cin.get();
        getline(cin, newData.name);
        cout << "\n\tEnter student age : ";
        cin >> newData.age;
        cout << "\n\tEnter student degree : ";
        cin >> newData.degree;
        cout << "\n\tEnter student semester number : ";
        cin >> newData.semesterNo;
        cout << "\n\tEnter Monthly Salary : ";
        cin >> newData.salary;
        Student student;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("student.txt");
        while (!read.eof()) {
            read >> student.id;
            read.ignore();
            getline(read, student.name);
            read >> student.age;
            read >> student.degree;
            read >> student.semesterNo;
            read >> student.salary;
            if (student.id != id) {
                tempFile << "\n" << student.id;
                tempFile << "\n" << student.name;
                tempFile << "\n" << student.age;
                tempFile << "\n" << student.degree;
                tempFile << "\n" << student.semesterNo;
                tempFile << "\n" << student.salary;
            }
            else {
                tempFile << "\n"<< student.id;
                tempFile << "\n"<< newData.name;
                tempFile << "\n"<< newData.age;
                tempFile << "\n" << newData.degree;
                tempFile << "\n"<< newData.semesterNo;
                tempFile << "\n"<< newData.salary;
            }
        }
        read.close();
        tempFile.close();
        remove("student.txt");
        rename("temp.txt", "student.txt");
        cout << "\n\tData updated successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}


 	int main()
       {
	  cout<<"                                                    \n"<<endl;
	  cout<<"                                                    \n"<<endl;
	  cout<<"                                                    \n"<<endl;
	  cout<<"\t\t\t-----------<<(      SCHOLARSHIP MANAGEMENT SYSTEM     )>>--------------\n";
	  
	  cout<<"                                                    \n"<<endl;
	  cout<<"                                                    \n"<<endl;
	  cout<<"                                                    \n"<<endl;
	  
    ifstream read;
    read.open("id.txt");
    if (!read.fail()) {
        read >> ID;
    }
    else {
        ID = 0;
    }
    read.close();
    
     while(true) {
     	system("color 4F");
        cout << "\n\t1.Add student data";
        cout << "\n\t2.See student data";
        cout << "\n\t3.Search student data";
        cout << "\n\t4.Delete student data";
        cout << "\n\t5.Update student data\n";
        cout << "\t6.Exit Program\n";
        cout<<"       =========================\n";
        int choice;
        cout << "\n\tEnter choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            readData();
            break;
        case 3:
            searchData();
            break;
        case 4:
            deleteData();
            break;
        case 5:
            updateData();
            break;
         case 6:
         	cout<<"\n\n\tYou Exit The program...";
         	
            exit(1);
          
         default:
		 cout<<"\n\n........Invalid Input  Kindly Enter Valid Number ........\n\n\n";  
		 break; 
}}
	return 0;
}
