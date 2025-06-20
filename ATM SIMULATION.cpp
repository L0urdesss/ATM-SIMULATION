//Mark Toni Ramsol Tagalogon  
//Maria Lourdes T. Villaruz 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define MAX 100

using namespace std;
void gotoxy(int x,int y){
    COORD coord = {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
typedef struct record{
string setpin ;
string name;
int accNum;//account id
int mm,dd,yy; //birthdate
int balance; //money
string cpnum;//Contact number

}REC;
typedef struct student{
int marker;
REC atmacc[MAX];
} LIST;
class MyList{
private:
    LIST L;
    string pin;
    string currPin;
    string currName;
    int currID;
    int currBal;
    int locate(int n);

    bool isEmpty();
    int AccountBalance = 0;
    int UserInputOption = -1;
    int valueToWithdraw = 0;
    long CustomerRequest = 0;
    bool isNotFinished = true;
    long depositAmount = 0;
public:
    string encrypt(string pin);
    string decrypt(string pin);
    void pincode();
    void menubar();
    int menu();
    int checker();
    void login();
    void balIn();
    void withDraw();
    void deposit();
    void fundTrans();
    void changePins();
    void insertcard();
    void accCreate(REC acc);
    void cardChecker();
    void saveCard();
    void save();
    void retrieve();
    void retrieveCard();
    void add(REC x);
    void makenull();
    void tester();
    void balsaver();
    void idchecker(int n);
    void monitorScreen();
};



void MyList::balsaver(){
int p,n;
n = currID;
p = locate(n);
L.atmacc[p].balance = AccountBalance;
gotoxy(46,24);cout<<"Balance Updated"<<endl;
gotoxy(46,25);system("pause");
}

void MyList::makenull(){
    L.marker=-1;
}

void MyList::add(REC x){
    L.marker++;
    L.atmacc[L.marker]=x;
}

void MyList::cardChecker(){
REC x;
int p;
int n;
p = locate(n);
const char *filename = "C:\\Data Structures\\Card.txt";
  std::ifstream in ( filename );
  if ( !in )
    std::cerr<< filename <<" failed to open\n";
  else {
    bool empty = ( in.get(), in.eof() );
    if (empty)
        accCreate(x);

  }
}



void MyList::accCreate(REC acc){
system("cls");
monitorScreen();
srand((unsigned) time(NULL));
int random = 100000 + (rand() % 10001);
gotoxy(40,8);cout<<"You don't have any account yet in this atm.";
gotoxy(43,9);cout<<"Please fill up the form in this screen";
gotoxy(51,11);cout<<"PERSONAL INFORMATION"<<endl;
gotoxy(41,13);cout<<"Account Number: "<<random<<endl;
acc.accNum = random;
gotoxy(41,14);cout<<"Name: ";getline(cin,acc.name);
gotoxy(41,15);cout<<"Birthdate (use numbers(mm/dd/yyyy))"<<endl;
gotoxy(41,16);cout<<"Month: ";cin>>acc.mm;
gotoxy(41,17);cout<<"Day: ";cin>>acc.dd;
gotoxy(41,18);cout<<"Year: ";cin>>acc.yy;
gotoxy(41,19);cout<<"Cellphone Number: ";cin.ignore();getline(cin,acc.cpnum);
gotoxy(41,20);cout<<"Insert Pin: ";cin>>acc.setpin;
currPin = acc.setpin;
currName = acc.name;
currID = acc.accNum;
acc.balance = 0;
AccountBalance = acc.balance;
add(acc);
gotoxy(50,22);cout<<"Registered successfully.";
gotoxy(40,24);system("pause");
menubar();

}

int MyList::locate(int n){
for (int i = 0;i<=L.marker;i++)
    if (L.atmacc[i].accNum==n)
         return i;
return -1;

}

void MyList::saveCard(){
fstream fp;
fp.open("C:\\Data Structures\\Card.txt",ios::out);
 if (!fp){
    cout <<"File Error.\n";
        system("pause");
} else {
    fp << currID <<endl<<encrypt(currPin);
    fp.close();
}
}

void MyList::save(){
fstream fp;
fp.open("C:\\Data Structures\\atm.txt",ios::out);
if (!fp){
    cout <<"File Error.\n";
        system("pause");
} else {
        for (int i=0;i<=L.marker;i++){
        fp <<L.atmacc[i].name<<endl<<L.atmacc[i].accNum<< " " <<L.atmacc[i].mm<< " " <<L.atmacc[i].dd<< " " <<L.atmacc[i].yy
        << " " <<L.atmacc[i].cpnum<< " " <<L.atmacc[i].setpin<<" "<<L.atmacc[i].balance<<endl;
        }
    fp.close();
}
}

void MyList::retrieveCard(){
fstream fp;
fp.open("C:\\Data Structures\\Card.txt",ios::in);
if (!fp){
    cout << "File Error.\n";
    system("pause");
}else {
    fp >>currID;
    fp >> currPin;
    fp.ignore();

    currPin = decrypt(currPin);
} fp.close();

}

void MyList::retrieve(){
fstream fp;
REC x;
fp.open("C:\\Data Structures\\atm.txt",ios::in);
if (!fp){
    cout << "File Error.\n";
    system("pause");
} else {
    while(true){
    getline (fp,x.name);
    fp >> x.accNum >> x.mm >> x.dd >> x.yy >> x.cpnum >> x.setpin>> x.balance;
    fp.ignore();


if (!fp.eof())
    add(x);
else
    break;
    } fp.close();

}}



void MyList::insertcard(){
FILE *fp;
do{ system("cls");
    printf("Please insert card...");
    fp=fopen("C:\\Data Structures\\Card.txt","r");
} while(fp==NULL);
fclose(fp);
}


int MyList::checker(){
int p = stoi(pin);
int sp = stoi(currPin);
if (p == sp)
    return 1;
else
 return -1;
}

int main(){

MyList obj;
obj.makenull();
obj.insertcard();
obj.retrieve();
obj.cardChecker();
obj.login();

return 0;
}

void MyList::idchecker(int n){
int p;

p=locate(n);
if (p<0){
   gotoxy(55,18); cout <<"Invalid Id.\n";
    gotoxy(41,24);system("pause"); login();
    } else{
           if ( currID!=L.atmacc[p].accNum){
       gotoxy(55,18); cout <<"Invalid Id.\n";
        gotoxy(41,24);system("pause");
        login();}
    }         currName=L.atmacc[p].name;
            AccountBalance = L.atmacc[p].balance;

}

void MyList::login(){
int p;
int n;
int a = 0;
string text;
REC x;
retrieveCard();
system("cls");
monitorScreen();
gotoxy(51,10);text = "WELCOME TO GG BANK ";;
while (text[a] != '\0')
	{
		cout << text[a];
		Sleep(50);

		a++;}
gotoxy(44,15);cout<<"ID: ";cin >> x.accNum; idchecker(x.accNum);
gotoxy(44,16);cout<<"Enter PIN: ";
pincode();
if (checker()==1){
    gotoxy(56,20);  cout<<"Welcome! "<<x.name<<endl;
    gotoxy(39,24);system("pause");
    menubar();}
else{
    gotoxy(50,20);cout<<"Wrong PIN try again"<<endl;
    gotoxy(39,24);system("pause");
   login();
}

}



void MyList::pincode(){
REC x;
int index =0;
char ch;
while((ch=getch())!=13 && index<6){
    if (index<0)
        index=0;
    if(ch==8){
        putch('\b');
        putch(' ');
        putch('\b');
        index--;
     continue;
    }
    if(isdigit(ch)){
     pin[index++]=ch;
     putchar('*');
    }
}
if (index==6)
    pin[index++]=ch;
pin[index]='\0';

}

int MyList::menu(){
int op;
system("cls");
monitorScreen();
gotoxy(44,8);cout << "Welcome to Your Account "<<currName<<"!!"<<endl;
gotoxy(44,9);cout<<"Please choose Option to Proceed";
gotoxy(42,11);cout <<"1. Balance Inquiry"<<endl;
gotoxy(42,13);cout <<"2. Withdraw"<<endl;
gotoxy(42,15);cout <<"3. Deposit"<<endl;
gotoxy(42,17);cout <<"4. Fund Transfer"<<endl;
gotoxy(42,19);cout <<"5. Change PIN Code"<<endl;
gotoxy(42,21);cout <<"6. Save and log out"<<endl;
gotoxy(42,22);cout <<"Select(1-6): ";
cin >> op;
return op;
}

void MyList::menubar(){
int op;
while (true){
    op = menu();
    switch (op){
    case 1: balIn(); break;

    case 2: withDraw(); break;

    case 3: deposit(); break;

    case 4: fundTrans(); break;

    case 5: changePins(); break;

    case 6: save();saveCard();gotoxy(55,24);exit(0);

    default: gotoxy(55,24);cout<<" 1 to 6 only.";gotoxy(42,25);system("pause");

    }
}}

void MyList::tester(){
  //  REC acc;
system("cls");
system("pause");
    for (int i=0;i<=L.marker;i++){

cout<<endl<<L.atmacc[i].name<<endl<<L.atmacc[i].accNum<<endl<<L.atmacc[i].mm<<endl<<L.atmacc[i].dd<<endl<<L.atmacc[i].yy<<endl<<L.atmacc[i].cpnum<<endl<<L.atmacc[i].setpin<<endl<<L.atmacc[i].balance<<endl;
    }
system("pause");

}
void MyList::balIn(){

    system("cls");
    monitorScreen();
    gotoxy(49,10);cout << "You Account Balance is:" << endl;
    gotoxy(58,15);cout << "$" <<AccountBalance << endl;
    gotoxy(42,23);system("pause");
}
void MyList::withDraw(){
    do {
        system("cls");
        monitorScreen();
        gotoxy(52,7);cout << "Withdrawal options:" << endl;
        gotoxy(42,9);cout << "1 - $20" << endl;
        gotoxy(42,11); cout << "2 - $40" << endl;
        gotoxy(42,13);cout << "3 - $60" << endl;
        gotoxy(42,15);cout << "4 - $100" << endl;
        gotoxy(42,17); cout << "5 - $200" << endl;
        gotoxy(42,19);cout << "6 - cancel transaction" << endl;
        gotoxy(42,21);cout << "7 - Other Amount" << endl;
        gotoxy(45,23);cout << "choose a withdrawal option (1-7)";
        cin >> UserInputOption;
        switch (UserInputOption) {
        case 1:
            valueToWithdraw = 20;
            break;
        case 2:
            valueToWithdraw = 40;
            break;
        case 3:
            valueToWithdraw = 60;
            break;
        case 4:
            valueToWithdraw = 100;
            break;
        case 5:
            valueToWithdraw = 200;
            break;
        case 6:
            isNotFinished = false;
            break;
        case 7:
            system("cls");
            monitorScreen();
           gotoxy(42,16); cout << "Enter Amount to Withdraw:  ";
            cin >> CustomerRequest;
            valueToWithdraw = CustomerRequest;
            isNotFinished = false;
            break;
        default:
            cout << "Invalid option! Try again." << endl;
            break;
        }

        if (valueToWithdraw != 0) {
            if (valueToWithdraw > AccountBalance) {
               gotoxy(42,24); cout <<"You can't withdraw $" << valueToWithdraw << endl;
                gotoxy(42,25);system("pause");
            }
            else {
                AccountBalance = AccountBalance - valueToWithdraw;
                isNotFinished = false;
                balsaver();
            }
            valueToWithdraw = 0;
        }

    } while (isNotFinished);
}

void MyList::deposit(){
    do {
        system("cls");
        monitorScreen();
        gotoxy(50,8);cout << "Enter Amount to Deposit" << endl;
        gotoxy(42,10);cout << "1 - $20" << endl;
        gotoxy(42,12);cout << "2 - $40" << endl;
        gotoxy(42,14);cout << "3 - $60" << endl;
        gotoxy(42,16);cout << "4 - $100" << endl;
        gotoxy(42,18);cout << "5 - $200" << endl;
        gotoxy(42,20);cout << "6 - cancel transaction" << endl;
        gotoxy(42,22);cout << "7 - Other Amount" << endl;
        gotoxy(45,23);cout << "Choose a deposit option (1-7)";

        cin >> UserInputOption;
        switch (UserInputOption) {
        case 1:
            AccountBalance = AccountBalance + 20;
            isNotFinished = false;
            balsaver();
            break;
        case 2:
            AccountBalance = AccountBalance + 40;
            isNotFinished = false;
            balsaver();
            break;
        case 3:
            AccountBalance = AccountBalance + 60;
            isNotFinished = false;
            balsaver();
            break;
        case 4:
            AccountBalance = AccountBalance + 100;
            isNotFinished = false;
            balsaver();
            break;
        case 5:
            AccountBalance = AccountBalance + 200;
            isNotFinished = false;
            balsaver();
            break;
        case 6:
            isNotFinished = false;
            break;
        case 7:
            system("cls");
            monitorScreen();
            gotoxy(42,16);
            cout << "Please Enter Amount to Deposit: ";
            cin >> depositAmount;
            AccountBalance = AccountBalance + depositAmount;
            isNotFinished = false;
            balsaver();
            break;
        default:
            cout << "Invalid option! Try again." << endl;
            break;
        }

    } while (isNotFinished);
}

void MyList::fundTrans(){
    system("cls");
    monitorScreen();
int p,tempID,tempbal;
currBal = AccountBalance;
gotoxy(54,8);cout << "Transfer Funds"<<endl;
gotoxy(54,10);cout << "Sender "<<endl;
gotoxy(42,12);cout << "Name : "<<currName<<endl;
gotoxy(42,13);cout << "Your Account number : "<<currID<<endl;
gotoxy(42,14);cout << "Current Balance: "<<currBal<<endl;
gotoxy(54,16);cout << "Reciever "<<endl;
gotoxy(42,18);cout << "Enter Account Number : ";cin>>tempID;
if(currID == tempID){
   gotoxy(42,20); cout<<"cannot use own account"<<endl;
    gotoxy(42,24);system("pause");
    menubar();
}
p = locate(tempID);
gotoxy(42,19);cout<<"current receiver: "<<L.atmacc[p].name<<endl;

 if (tempID != L.atmacc[p].accNum){
    gotoxy(42,22);cout << "not existed!";
    gotoxy(41,24);system("pause");
 }
    else{
   gotoxy(42,20); cout << "Enter Money to transfer ";cin>>tempbal;
 if (AccountBalance < tempbal){
   gotoxy(42,21); cout << "Insufficient Funds!";
    gotoxy(41,24);system("pause");
 }
    else{
    AccountBalance = AccountBalance - tempbal;
    L.atmacc[p].balance = L.atmacc[p].balance + tempbal;
    gotoxy(45,22);cout<<"Money Transferred Successfully "<<endl;
    gotoxy(42,24);system("pause");
    balsaver();
    }}
}
void MyList::changePins(){
 system("cls");
 monitorScreen();
  int p,n;
 n = currID;
 p = locate(n);
 gotoxy(49,10);cout<<" Change your Pin Account";
gotoxy(42,14); cout << "Enter your Current pin: ";cin>>currPin;
 if (currPin !=L.atmacc[p].setpin){
gotoxy(55,20); cout << "wrong pin!";
   gotoxy(42,24); system("pause");
 }
 else{
   gotoxy(42,16); cout << "Enter New Pin: "; cin>>currPin;
    L.atmacc[p].setpin = currPin;
   gotoxy(55,20); cout<<"Pin Updated";
    gotoxy(42,24);system("pause");
}
}
string MyList::encrypt(string pin){
int i=0;

while(pin[i]!='\0'){
    pin[i]=pin[i] + 20;
    i++;
}
return pin;
}
string MyList::decrypt(string pin){
int i=0;
REC x;
while(pin[i]!='\0'){
    pin[i]=pin[i] - 20;
    i++;
}
return pin;
}

void MyList::monitorScreen(){
 gotoxy(30,5); cout<<" ============================================================";
 gotoxy(30,6); cout<<"|      ________________________________________________      |";
 gotoxy(30,7); cout<<"|     |                                                |     |";
 gotoxy(30,8);cout<<"|     |                                                |     |";
 gotoxy(30,9);cout<<"|     |                                                |     |";
 gotoxy(30,10);cout<<"|| 1 ||                                                || 5 ||";
 gotoxy(30,11);cout<<"|     |                                                |     |";
 gotoxy(30,12);cout<<"|     |                                                |     |";
 gotoxy(30,13);cout<<"|     |                                                |     |";
 gotoxy(30,14);cout<<"|| 2 ||                                                || 6 ||";
 gotoxy(30,15);cout<<"|     |                                                |     |";
 gotoxy(30,16);cout<<"|     |                                                |     |";
 gotoxy(30,17);cout<<"|     |                                                |     |";
 gotoxy(30,18);cout<<"|| 3 ||                                                || 7 ||";
 gotoxy(30,19);cout<<"|     |                                                |     |";
 gotoxy(30,20);cout<<"|     |                                                |     |";
 gotoxy(30,21);cout<<"|     |                                                |     |";
 gotoxy(30,22);cout<<"|| 4 ||                                                || 8 ||";
 gotoxy(30,23);cout<<"|     |                                                |     |";
 gotoxy(30,24);cout<<"|     |                                                |     |";
 gotoxy(30,25);cout<<"|     |                                                |     |";
 gotoxy(30,26);cout<<"|     |________________________________________________|     |";
 gotoxy(30,27);cout<<"|                                                            |";
 gotoxy(30,28);cout<<" ============================================================";


}

