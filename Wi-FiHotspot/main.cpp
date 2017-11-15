#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

int main()
{
   char ch;
   do{
    system("cls");
    string HSname,HSpwd,HSpwd1; //HotSpot Name ,HotSpot Password check
    char pwd;  //char to process * for while typing Passwords
    int option; //Choice to Selected
    cout << "\n\n\t\t\t Wi-Fi HotSpot Manager v 1.0" << endl;
    cout << "\n\n\n\n";
    cout << "Select as u Wish..." << endl;
    cout << "\n\n\t\t 1.Start HotSpot \n\t\t 2.Stop HotSpot \n\t\t 3.Create or Edit HotSpot \n\t\t 4.Show Clients Connected \n\t\t 5.Show HotSpot Password \n\t\t 6.Exit \n\n Waiting for your Selection...\n";
    cin>>option;
    switch(option)
{
case 1:
      cout<<"Starting..."<<endl;
      system("netsh wlan start hostednetwork");
      break;
case 2:
    cout <<"Stopping..."<<endl;
    system("netsh wlan stop hostednetwork");
    break;
case 3:
    cout<<"\nCreate / Edit a HotSpot such as BSSID name and Password" << endl;
    cout <<"\nDefault Security is WPA2-PSK for HotSpot"<<endl;
    cout << "\nChoose a WiFi-HotSpot name..."<<endl;
    cin>>HSname;
    cout << "\n\n\t\t\tNOTE:FOR SECURITY REASONS,\n"<< endl;
    cout <<"\n USING BACKSPACE IF YOU TYPED WRONG PASSWORD DOES NOT REVERT * BUT IT DELETES CHARACTERS BACKGROUND!!!\n" << endl;
    cout << "\nChoose a HotSpot Password..."<<endl;
    pwd = _getch();

    while (pwd != 13) //Awaits for USER to HIT Enter!!! 13 is ASCII CODE for ENTER
     {
        HSpwd.push_back(pwd);
        if(pwd!= 8){
        cout<< '*';}
        pwd= _getch();
     }
   // cin>>HSpwd;
    cout << "\n Re-Type HotSpot Password..." << endl;
    pwd = _getch();
   if(pwd!= 8){
    while (pwd != 13) //Awaits for USER to HIT Enter!!! 13 is ASCII CODE for ENTER
     {
        HSpwd1.push_back(pwd);
        if(pwd!= 8){
        cout<< '*';}
        pwd= _getch();
     }
   }  cout << endl;
   // cin >>HSpwd1;
    if (HSpwd==HSpwd1)
    {
    cout<<"\n\n"<<endl;
    system(("netsh wlan set hostednetwork mode=allow ssid="+HSname+" key="+HSpwd+"").c_str());
    }
    else
    {
    cout <<"Passwords Mis-Match, Try Again!!!";
    }
    break;
case 4:
    cout <<"\n\t\t>>> Clients Connected to HotSpot Wi-Fi are Shown as Below <<<";
    system("netsh wlan show hostednetwork");
    cout <<"End of Report";
    break;
case 5:
    cout <<"\n\t\t >>> Your Wi-Fi HotSpot Password <<<";
    system("netsh wlan show hostednetwork setting=security");
    break;
case 6:
    system("exit ");
    break;
default:
    cout <<"Incorrect Choice";
    break;
}
cout <<"\n\n\n\t\tContinue = ANY_KEY  , Exit = y";
ch=getch();
}while (ch != 'y');
cout <<"\n\n\n\t\t\t>>> Developed by MyPCEthics <<<\n\n\t    >>> Like and Support US,on facebook.com/mypcethics <<<" << endl;
getch();
return 0;
}


