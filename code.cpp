#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Railway{

    string name;
    string classtype;
    int total_seats;
    int available_seats;

    public:
        Railway(int total,string s):total_seats(total),available_seats(total),classtype(s){};

        void reserve_seat(){
            available_seats--;
            
        }

        int checkSeat(){
            return available_seats;
        }

        void generateTicket(string name, string dest){
            ofstream writeFile(name+"_ticket.txt");

            writeFile << "Name\t\tSource\tDestination\tPaid"<<endl;
            writeFile << name <<"\t\tBangalore" << dest <<"\tYes"<<endl;
            cout<<"Your ticket has been generated"<<endl;
            writeFile.close();
            exit(0);
        }
};

int main() {
    
    ifstream inputFile("departure.txt");

    Railway ac(75,"AC");
    Railway regular(300,"Regular");
    Railway sleeper(150,"Sleeper");

    int ch,classtype,flag=0;
    string dest,str;
    string str;
    string name;
    char yesno;

    cout<<"Please enter your name"<<endl;
    cin >> name;
    cout<<"Welcome to Railway reservation!"<<endl<<"Please choose the below option/s"<<endl;
    cout<<"1. Today's departures/arrivals"<<endl<<"2. Reserve seat/s"<<endl;
    cin >> ch;

    switch(ch){
        case 1:
            while(getline(inputFile , str)){
                cout<<str<<endl;
            }
            break;

        case 2:
            cout<<"Please choose your destination"<<endl;
            cin>>dest; 
            while(getline(inputFile,str)){
                if(str==dest){
                    flag=1;
                }
            }
            if(flag != 1){
                cout<<"Wrong choice"<<endl;
                exit(0);
            }
             
            cout<<"Please choose your class"<<endl;
            cout<<"1. Regular :"<<endl<<"2. Sleeper"<<endl<<"3. AC"<<endl;
            cin>>classtype;
            switch(classtype){
                case 1:
                    if(regular.checkSeat()){
                        cout<<"Seat is available (Rs 1000). Would you like to confirm ? (y/n)"<<endl;
                        cin>>yesno;
                        if(yesno == 'n'){cout<<"Please come again"<<endl;exit(0);}
                        else{
                            regular.reserve_seat();
                            regular.generateTicket(name,dest);
                        }
                    }
                    break;

                case 2:
                    if(sleeper.checkSeat()){
                        cout<<"Seat is available (Rs 1000). Would you like to confirm ? (y/n)"<<endl;
                        cin>>yesno;
                        if(yesno == 'n'){cout<<"Please come again"<<endl;exit(0);}
                        else{
                            sleeper.reserve_seat();
                            sleeper.generateTicket(name,dest);
                        }
                    }
                    break;

                case 3:
                    if(ac.checkSeat()){
                        cout<<"Seat is available (Rs 1000). Would you like to confirm ? (y/n)"<<endl;
                        cin>>yesno;
                        if(yesno == 'n'){cout<<"Please come again"<<endl;exit(0);}
                        else{
                            ac.reserve_seat();
                            ac.generateTicket(name,dest);
                        }
                    }
                    break;

                default:
                    cout<<"Wrong choice"<<endl;
                    exit(0);
                    break;            
                    
            }

        default:
            cout<<"Wrong choice"<<endl;
            exit(0);
            break;      
    }
    inputFile.close();
    return 0;
}
