#include<iostream>
#include<fstream>
using namespace std;

class toDo{
    string task;
    toDo *next;
 public:
    void createTask(); // creating class
    void displayTask(); // traversing
    void currentTask(); // getFront
    void finishTask(); // dequeue
    void readBegin(); // read txt and begin the program
    void saveExit(); // write and leave
    bool emptyYToDo(); // stack underflow
    void fourTab();
    string getter();
};
toDo *front, *rear = NULL;
// toDo *rear = NULL;

void toDo::createTask(){
    toDo *newToDo = new toDo;
    string task;
    cout<<"\n\n\n";

    fourTab();cout<<"Enter a new Task: ";
    cin.ignore();
    string tempText;
    getline(cin, tempText);
    char y;
    cout<<"\n";
    fourTab();cout<<"Enter (y) to add "<<tempText<<" to your ToDo List: ";
    cin>>y;
    if(y == 'y'){
        newToDo->task = tempText;
    }else{
        cout<<"\n";
        fourTab();cout<<tempText<<" is not added to ToDo List! ";
        delete newToDo;
        return;
    }

    cout<<"\n";

    if(front == NULL){
        front = newToDo;
        rear = newToDo;
        rear->next = NULL;
        fourTab();cout<<"Task Created Successfully!";
        return;
    }
    rear->next = newToDo;
    rear = newToDo;
    rear->next = NULL;
    fourTab();cout<<"Task Created Successfully!";
}

void toDo::displayTask(){
    cout<<"\n\n\n";
    toDo *current = front;
    if(emptyYToDo()){
        fourTab();cout<<"Empty TODO List!\n\n\t\t\t\t Tab on enter to Create ToDo List!";
    }else{
        fourTab();cout<<"========*********=======\n";
        fourTab();cout<<"\tTODO List\n";
        fourTab();cout<<"========*********=======\n\n";
        int i = 1;
        while(current != NULL){
            if(current == front){
                fourTab();cout<<i++<<". << "<<current->task<<" >>\n";
                current = current->next;
                continue;
            }
            fourTab();cout<<i++<<". "<<current->task<<"\n";
            current = current->next;
        }
    }
}

void toDo::currentTask(){
    if(emptyYToDo()){
        cout<<"\n\n\n";
        fourTab();cout<<"ToDo List Not found!"<<endl;;
    }else{
        cout<<"\n\n\n";
        fourTab();cout<<"The current Task is: << "<<front->task<<" >>\n";
    }
}

void toDo::finishTask(){
    toDo *temp = front;
    if(emptyYToDo()){
        cout<<"\n\n\n";
        fourTab();cout<<"ToDo List Not Found!"<<endl;;
    }else{
        cout<<"\n\n\n";
        string tempText = front -> task;
        fourTab();cout<<"Successfully Finished << "<<tempText<<" >>\n\n\t\t\t\tNext Task: "<<front->next->task<<"\n";
        front = front->next;
        delete temp;
    }
}

void toDo::readBegin(){

    ifstream fin;
    fin.open("task.txt");

    if(fin.is_open()){
        cout<<"\n\n\n\t\t\t\tTap on any Key to continue Using ToDo app! ";
        cout<<"above while";
        while(!fin.eof()){

            toDo *newToDo = new toDo;

            cin.get();
            string temp;
            getline(fin, temp);
            cout<<temp;

            if(temp==""){
                break;
            }else{
                newToDo->task = temp;
                if(front == NULL){
                    newToDo -> next = NULL;
                    front = newToDo;
                    rear = newToDo;
                }
                else{
                    rear->next = newToDo;
                    rear = newToDo;
                    rear->next = NULL;
                }
            }
        }
        fin.close();
        cout<<"below while";
    }else{
        cout<<"\n\n\n\t\t\t\tTap on any Key to Start Create your Todo List... ";
    }
}

void toDo::saveExit(){
    toDo *current = front;
    ofstream fout;
    fout.open("task.txt");
    while(current != NULL){
        fout<<current->task<<endl;
        current = current->next;
    }
    fout.close();
}

bool toDo::emptyYToDo(){
    if(front == NULL){
        return true;
    }else{
        return false;
    }
}

void toDo::fourTab(){
    for(int i = 0; i<4; i++){
        cout<<"\t";
    }
}


void displayMenu(){
    toDo ToDo;
    system("CLS");
    cout<<"\n\n";
    ToDo.fourTab();cout<<"========================\n";
	ToDo.fourTab();cout<<"\tMY TODO APP\n";
	ToDo.fourTab();cout<<"========================\n";
	ToDo.fourTab();cout<<"    ::MAIN MENU::\n";
    ToDo.fourTab();cout<<"1. NEW TASK\n";
    ToDo.fourTab();cout<<"2. DISPLAY TASK\n";
    ToDo.fourTab();cout<<"3. CURRENT TASK\n";
    ToDo.fourTab();cout<<"4. FINISHED CURRENT TASK\n";
    ToDo.fourTab();cout<<"5. SAVE AND EXIT\n\n";
    ToDo.fourTab();cout<<"Select Your Option (1-5): ";
}

int main(){

toDo ToDo;
ToDo.readBegin();
cin.get();
char a;

while(true){
    void writeToFile();
    displayMenu();
    cin>>a;
    cout<<"\n";
    switch(a){
    case '1':
        system("CLS");
        ToDo.createTask();
        break;
    case '2':
        system("CLS");
        ToDo.displayTask();
        break;
    case '3':
        system("CLS");
        ToDo.currentTask();
        break;
    case '4':
        system("CLS");
        ToDo.finishTask();
        break;
    case '5':
        system("CLS");
        ToDo.saveExit();
        exit(0);
    default:
        ToDo.fourTab();cout<<"Wrong input"<<endl;
    }

    cin.ignore();
    cin.get();
    void writeToFile();
}
}




