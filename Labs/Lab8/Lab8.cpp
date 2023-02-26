#include "iostream"
#include <ctime>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#define Student_max 10
#define Name_max 20
#define phone_max 11

using namespace std;

void generate_name(char* name,int N){
    name[0]=(char)(65+rand()%26);
    for(int i=1;i<N;i++){
        name[i]=(char)(97+rand()%26);
    }
}

void generate_phone(char* phone){
    for(int i=0;i<phone_max;i++){
        phone[i]=(char)(48+rand()%10);
    }
}

void get_marks(short marks[4],string str)
{
    stringstream ss;
    ss << str;
    string temp;
    short found;
    int num = 0;
    while (!ss.eof()) {
        ss >> temp;
        if (stringstream(temp) >> found){
            marks[num]=found;
            num++;
        }
        temp="";
    }
}

struct Student{
    //any student assumed to have name, surname and (not always) middle name
    char name[Name_max];
    char surname[Name_max];
    char middle_name[Name_max];
    //we assume that we use phone numbers in countries with 11-digits format (country + area + code)
    char phone_number[phone_max];
    //each class of students has ¹ and letter
    int class_number;
    char class_letter;
    //we keep four student marks
    short int marks[4];
    //first mark is math,second is physics, third is russian language, fourth is literature
};

void output_stud_data(Student stud){
    int i=0;
    while(i<20){
        cout<<stud.name[i];
        i++;
    }
    cout<<endl;
    i=0;
    while(i<20){
        cout<<stud.surname[i];
        i++;
    }
    cout<<endl;
    i=0;
    while(i<20){
        cout<<stud.middle_name[i];
        i++;
    }
    cout<<endl;
    i=0;
    while(i<11){
        cout<<stud.phone_number[i];
        i++;
    }
    cout<<endl;
    cout<<stud.class_number<<stud.class_letter<<endl;
    for(short mark : stud.marks){
        cout<<mark<<" ";
    }
    cout<<endl;
}

Student generated_student_data() {
    //we assume that all students we create have maximum letters per name,surname and middle name
    //that is not always the case
    Student dude;
    generate_name(dude.name, Name_max);
    generate_name(dude.surname, Name_max);
    generate_name(dude.middle_name, Name_max);
    generate_phone(dude.phone_number);
    dude.class_number = 1 + rand() % 11;
    //we use english letters in class name and assume there are no more than 12 classes in parallel
    dude.class_letter = (char) (65 + rand() % 12);
    for (int j = 0; j < 4; j++) {
        //there are 4 marks: 2,3,4,5, we do not assume that student may get 1
        dude.marks[j] = 2 + rand() % 4;
    }
    return dude;
}

struct Students_data {
    Student *students;
    int total_number_of_students;
    void Create_students(int N) {
        students = new Student[N];
        total_number_of_students=N;
        for (int i = 0; i < N; i++) {
            students[i]=generated_student_data();
        }
    }

    void Read_students_data(int N) {
        ifstream file("Students.txt", ios::app);
        if (!file.is_open()) {
            printf("Cannot open file.\n");
            exit(1);
        } else {
            for (int i = 0; i < N; i++) {
                string buffer;
                getline(file, buffer, '\n');
                strcpy(students[i].name, buffer.c_str());
                getline(file, buffer, '\n');
                strcpy(students[i].surname, buffer.c_str());
                getline(file, buffer, '\n');
                strcpy(students[i].middle_name, buffer.c_str());
                getline(file, buffer, '\n');
                strcpy(students[i].phone_number, buffer.c_str());
                getline(file, buffer, ' ');
                students[i].class_number = stoi(buffer);
                getline(file, buffer, '\n');
                students[i].class_letter = buffer[0];
                getline(file, buffer, '\n');
                get_marks(students[i].marks, buffer);
            }
            file.close();
        }
    }

    void Print_students_data(int N) {
        ofstream file("Students.txt", ios::app);
        if (!file.is_open()) {
            printf("Cannot open file.\n");
            exit(1);
        } else {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < Name_max; j++) {
                    file << students[i].name[j];
                }
                file << " " << endl;
                for (int j = 0; j < Name_max; j++) {
                    file << students[i].surname[j];
                }
                file << " " << endl;
                for (int j = 0; j < Name_max; j++) {
                    file << students[i].middle_name[j];
                }
                file << " " << endl;
                for (int j = 0; j < phone_max; j++) {
                    file << students[i].phone_number[j];
                }
                file << " " << endl;
                file << students[i].class_number << " " << students[i].class_letter << endl;
                for (int j = 0; j < 4; j++) {
                    file << students[i].marks[j] << " ";
                }
                file << " " << endl;
            }
            file.close();
        }
    }

    void Add_student(int N) {
        Student *new_students = new Student[N + 1];
        total_number_of_students++;
        for (int i = 1; i < N + 1; i++) {
            new_students[i] = students[i - 1];
        }
        new_students[0]=generated_student_data();
        delete students;
        students = new_students;
    }

    void Delete_bad_students(int number_of_studs) {
        int count=0;
        for(int i=0;i<number_of_studs;i++){
            if((students[i].marks[0]>2) && (students[i].marks[1]>2) && (students[i].marks[2]>2) && (students[i].marks[3]>2)){
                count++;
            }
        }
        Student* another_students = new Student[count];
        total_number_of_students=count;
        int curr=0;
        for(int i=0;i<number_of_studs;i++){
            if((students[i].marks[0]>2) && (students[i].marks[1]>2) && (students[i].marks[2]>2) && (students[i].marks[3]>2)){
                another_students[curr]=students[i];
                curr++;
            }
        }
        delete students;
        students=another_students;
    }
};

int main(){
    srand(time(NULL));
    Students_data stud{};
    FILE *fp = nullptr;
    stud.Create_students(Student_max);
    stud.Print_students_data(Student_max);
    stud.Read_students_data(Student_max);
    stud.Add_student(Student_max);
    stud.Delete_bad_students(Student_max);
    return 0;
}
