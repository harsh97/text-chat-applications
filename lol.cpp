#include<iostream.h>
#include<process.h>
#include<strings.h>
#include<fstream>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<thread>
#include<time.h>
#include<windows.h>
#include<chrono.h>

using namespace std;

char ch[1];
char ch1;

void exploreMenu();
void menu();
void exitConversation();


 void displayJoinedConvos();
void sendMessage();
int timeLapse();
void recordActivity();
void displayConvoDetails();
const int namesize=30,passwordsize=30,roomsjoinedsize=50,inviteSize=10,messageSize=150,totalMessages=1000;
int strcmpr(char string1[],char string2[])
{
    if(strlen(string1)!=strlen(string2))
    return 1;
    for(int i=0;i<strlen(string1);i++)
    {
        if(string1[i]!=string2[i])
        {
            return 1;
        }
    }
    return 0;
}
class conversation
    {
    public:
        static int convoCount;
    char convoName[namesize];
    char message[totalMessages][messageSize];
    int convoNo;
    int visibility;
    int secure;
    int usersJoined[roomsjoinedsize];
    char password[passwordsize];
conversation findConvo(int convoNoToBeFound)
{
    conversation tempConvo;
    ifstream data("userdata.dat",ios::binary);
    while(!data.eof())
    {
        data.read((char*)&tempConvo,sizeof(tempConvo));
        if(tempConvo.convoNo==convoNoToBeFound)
            return tempConvo;
}
}
void convoSettings()
{
    system("clrscr");
    char ch;
    cout<<"1.Change visibility\n2.Details\n3. Exit Conversation\n";
    cin>>ch;
    if(ch=='1')
    {

        if(this->visibility==1)
        {
            cout<<"The conversation is currently visible to everyone\nPress y to change it\n";
            cin>>ch;
            if(ch=='y')
            {
                this->visibility=0;
                cout<<"Visibility was successfully changed\n";
                system("pause");
                menu();
            }
            else
            {
                menu();
            }
        }
        else
        {
            cout<<"The conversation is not visible.\n press y to change it ";
            cin>>ch;
            if(ch=='y')

            {
                                this->visibility=1;
                cout<<"Visibility was successfully changed\n";
                system("pause");
                menu();
            }
            else
            {
                menu();
            }
        }
    }
   else if(ch=='2')
    {
        displayConvoDetails();

    }
    else if(ch=='3')    {
        exitConversation();
    }
}
    int verifyPassword()
     {
    conversation tempConversation;
    cout<<"Enter your password \n";
    tempConversation.feedPassword();
    if(strcmpr(tempConversation.password,password)==0)
    {
       return 1;
    }
    return 0;
    }
void display()
{

       readUpdateCurrentConvo();
    system("cls");
    cout<<convoName<<"\n";
     for(int i=0;strlen(message[i])!=0;i++)
            {
                cout<<message[i]<<"\n";
            }
            sendMessage();


}
    void displayMessages();



    void exploreConversation()
    {
        conversation conversations[10];
        ifstream data("convodata.dat",ios::binary);
        if(!data)
        {
            cout<<"there is no data";
            data.close();
        }
        else
        {
            int j=0;
        for(int i=0;i<10&&i<convoCount;i++)
        {
            data.read((char*)&conversations[i],sizeof(conversations[i]));
            if(conversations[i].visibility==1)
           {cout<<(j+1)<<" "<<conversations[i].convoName<<"\n";
            j++;}
    }
      int choice;
        cin>>choice;
        if(choice==0)
            menu();
        recordActivity();
        data.close();
        *this=conversations[choice-j];
        this->displayMessages();

        }

    }

     void feedPassword()
    {
           for(int i=0;password[i-1]!=13;i++)
    {

 password[i] = getch();
      cout << '*';

    }
    }
    int uniqueName()
        {

            ifstream data("convodata.dat",ios::binary);
            if(!data)

            {
                data.close();return 1;
            }
            else
            {
                conversation tempConvo;
                while(!data.eof())
                {
                    data.read((char*)&tempConvo,sizeof(tempConvo));
                    if(strcmpr(tempConvo.convoName,convoName)==0)
                       {
                           data.close();
                           return 0;
                       }
                }
                data.close();
                return 1;
            }
        }
    void addConvo()
    {        cout<<"Please enter the unique name of the convo\n";
            cin>>convoName;
        char choice;
        cout<<"Will this conversation be secured with a password\n";
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {
            secure=1;
        }
        if(secure==1)
        {
            feedPassword();
        }
        cout<<"Do you want it to be visible to other people\n";
        cin>>choice;
        if(choice=='y'||choice=='Y')
            visibility=1;
        else
            visibility=0;
        cout<<"Conversation has been created \n";
        convoCount+=1;
        cout<<"\nconvocount"<<convoCount;
        convoNo=convoCount;
        updateCurrentConvo();
        displayMessages();

    }
    void readUpdateCurrentConvo()
    {
        conversation tempConvo;
        ifstream data("convodata.dat",ios::binary);
        if(!data)
        {
           data.close();
        }
        else
        {


        while(!data.eof())
        {
            data.read((char*)&tempConvo,sizeof(tempConvo));
            if(tempConvo.convoNo==this->convoNo)
                *this=tempConvo;
        }
        data.close();
    }
    }
    void updateCurrentConvo()
    {

     ofstream dataWriteCount("convocount.dat",ios::trunc);
     dataWriteCount<<convoCount;
     dataWriteCount.close();
    ifstream data("convodata.dat",ios::binary);
    if(!data)
    {
        data.close();
        ofstream dataWrite("convodata.dat",ios::binary);
        dataWrite.write((char*)this,sizeof(*this));
        dataWrite.close();
    }
    else
    {
        conversation tempStore=*this;
        ofstream dataWrite("temp.dat",ios::binary);

        dataWrite.write((char*)&tempStore,sizeof(tempStore));

int i=1;
        while(!data.eof()&&i<convoCount)
        {
            i++;
            data.read((char*)&tempStore,sizeof(tempStore));
if(this->convoNo!=tempStore.convoNo)
            dataWrite.write((char*)&tempStore,sizeof(tempStore));
        }
        data.close();
        dataWrite.close();
        remove("convodata.dat");
        rename("temp.dat","convodata.dat");
    }
    }

}currentConversation,conversation1;
conversation findConvo(int);

 class User
    {
        public:
            int userNo;
        static int userCount;
        char userName[namesize];
        char password[passwordsize];
        int roomsJoined[roomsjoinedsize];
        int lastActivity;
        int visibility;//0 vissible
        int invites[10];
        char inviteType[10];
    int exists()
    {
        ifstream data("userdata.dat",ios::binary);
        if(!data)
        {
            data.close();
            return 0;

        }
        User tempUser;
        int i=0;
        while(!data.eof()&&i<userCount)
        {
            i++;

            data.read((char*)&tempUser,sizeof(tempUser));
            if(strcmpr(this->userName,tempUser.userName)==0)
               {
                   data.close();
                   *this=tempUser;
                   return 1;

               }
        }
        data.close();
            return 0;
    }
    void feedPassword()
    {
           for(int i=0;password[i-1]!=13;i++)
    {

 password[i] = getch();
      cout << '*';

    }
    }
    void addUser()
    {

      cout<<"Please enter your password\n";
      feedPassword();
      char choice;
      cout<<"\nDo you want to be visible to other persons?\n";
      cin>>choice;
      if(choice=='y'||choice=='Y')
      {
          visibility=1;
      }
      else{visibility=0;}
      userCount+=1;
      userNo=userCount;
       ofstream dataCount("usercount.dat",ios::trunc);
    dataCount<<userCount;
    dataCount.close();

      updateCurrentUser();


    }
void updateCurrentUser()
{



    ifstream data("userdata.dat",ios::binary);
    if(!data)
    {
        data.close();
        ofstream dataWrite("userdata.dat",ios::binary);
        dataWrite.write((char*)this,sizeof(*this));
        dataWrite.close();
    }
    else
    {
        User tempUser;
        ofstream dataWrite("temp.dat",ios::binary);
 dataWrite.write((char*)this,sizeof(*this));


        int i=0;
        while(!data.eof()&&i<userCount)
        {
            data.read((char*)&tempUser,sizeof(tempUser));
            if(this->userNo!=tempUser.userNo)
            {
                dataWrite.write((char*)&tempUser,sizeof(tempUser));
            }


            i++;
        }
        data.close();
        dataWrite.close();
        remove("userdata.dat");
        rename("temp.dat","userdata.dat");
    }
}
int verifyPassword()
{
    User tempUser;
    cout<<"Enter your password \n";
    tempUser.feedPassword();
    if(strcmpr(tempUser.password,password)==0)
    {
       return 1;
    }
    return 0;


}
void changeVisibility()
{
    if(visibility==1)
    {
        cout<<"You are currently visible to everyone\n";
        char choice;
        cout<<"Press c to change or any other key to continue\n";
        cin>>choice;
        if(choice=='c')
            visibility=0;

    }
    else if(visibility==0)
    {
        cout<<"You are currently invisible\n";
        char choice;
        cout<<"Press c to change or any other key to continue\n";
        cin>>choice;
        if(choice=='c')
            visibility=1;

    }
}
void explorePeople()
{
    User users[10],tempUser;
        ifstream data("userdata.dat",ios::binary);
        int j=0;
        for(int i=0;i<10&&i<userCount;i++)
        {
            data.read((char*)&tempUser,sizeof(tempUser));


               users[j]=tempUser;
               cout<<(j+1)<<" "<<users[j].userName<<"\n";
            j++;}

    data.close();
    int choice;
    cin>>choice;
    if(choice==0)
        menu();
    users[j-1].recieveInviteUser(userNo);
    cout<<"Invite sent"<<"\n";
    system("pause");
    menu();


}
void recieveInviteUser(char userNoOfSendee)
{
    int i=0;
    for(i=0;invites[i]!=0;i++);
    invites[i]=userNoOfSendee;
    i=strlen(inviteType);
    inviteType[i]='u';
    updateCurrentUser();
}
void openInvites();
User findUser(int userNoToBeFound)
{
    User tempUser;
    ifstream data("userdata.dat",ios::binary);
    while(!data.eof())
    {
        data.read((char*)&tempUser,sizeof(tempUser));
        if(tempUser.userNo==userNoToBeFound)
            return tempUser;
    }
}
void readUpdateUser()
{
     User tempUser;
        ifstream data("userdata.dat",ios::binary);
        if(!data)
        {
            cout<<"No records found";
            data.close();
        }
        while(!data.eof())
        {
            data.read((char*)&tempUser,sizeof(tempUser));
            if(tempUser.userNo==this->userNo)
                {*this=tempUser;
                  break;
                }
        }
        data.close();
}
    }currentUser,user;
void addUserConvo(User &user1,User &user2);
    int User::userCount=0;
     void convoUserConnect(User &user1);
    int conversation::convoCount=0;
void getConversationCount()
{
     ifstream data("convocount.dat");
    if(!data)
    {
        data.close();
    }
else
    { cout<<"execute";
      data>>conversation1.convoCount;
     }
}
void getUserCount()
{
    ifstream data("usercount.dat");
    if(!data)
    {
        data.close();
        currentUser.userCount=0;
    }
else
{
  data>>currentUser.userCount;
  data.close();}
}
    void conversation::displayMessages()
    {

     readUpdateCurrentConvo();
        cout<<convoName<<"\n";
        if(secure)
        {
            if(verifyPassword())
             {
                 convoUserConnect(currentUser);
                 display();
             }
             else
             {
                 cout<<"Incorrect password\n";
             }
        }
        else
        {
            convoUserConnect(currentUser);
            display();
        }
        }
void menu()
{
    char choice;
    start:
    cout<<"1.Joined Conversations\n2.Explore\n3.Visibility\n4.Invites\n5.Start a conversation\n";
            cin>>choice;
            switch(choice)
            {
                case '1':displayJoinedConvos();
                         break;
                case '5':currentConversation.addConvo();
                         break;
                case '2':exploreMenu();
                         break;
                case '3':currentUser.changeVisibility();
                         goto start;
                         break;
                case '4':currentUser.openInvites();
                         break;

            }
}
void display()
{    while(ch1!='@')
    {
 this_thread::sleep_for(chrono::seconds(3));
 this_thread::sleep_for(chrono::seconds(3));
 if(ch1!='@')
 {
       system("cls");
            currentConversation.readUpdateCurrentConvo();
    cout<<currentConversation.convoName<<"\n";
     for(int i=0;strlen(currentConversation.message[i])!=0;i++)
            {
                cout<<currentConversation.message[i]<<"\n";
            } }}    }
void sendMessage()
{
    thread refresh;
    refresh=thread(display);

    ch1='1';
    ch[0]=getch();

if(ch[0]=='0')
    {
        menu();
        ch1='@';
    }
    else if(ch[0]=='*')
    {
        ch1='@';
        currentConversation.convoSettings();
    }
    else
        {
            ch[1]='@';
            cout<<ch[0];
            currentConversation.readUpdateCurrentConvo();
            char name[namesize];
            strcpy(name,currentUser.userName);
            recordActivity();
            char line[messageSize];
            int i;
            for(i=0;strlen(currentConversation.message[i])!=0;i++);
            strcpy(currentConversation.message[i],name);
            strcat(currentConversation.message[i]," is typing....");
            currentConversation.updateCurrentConvo();
            cin.getline(line,messageSize);
             ch1='!';
            recordActivity();
            currentConversation.readUpdateCurrentConvo();
            strcat(name,":");
            strcpy(currentConversation.message[i],name);
            strcat(currentConversation.message[i],ch);
            strcat(currentConversation.message[i],line);
            currentConversation.updateCurrentConvo();
            currentConversation.display();
        }
}
 void recordActivity()
    {
        time_t t;
        currentUser.lastActivity=time(&t);
    }
int timeLapse()
{
    time_t t;
     return (time(&t)-currentUser.lastActivity);
}
int main()
{
    getUserCount();
    getConversationCount();
    cout<<"Welcome. Please enter your user name\n";
    cin>>currentUser.userName;
    if(!currentUser.exists())
    {
        currentUser.addUser();
        menu();
    }
    else if(currentUser.exists())
    {
        if(currentUser.verifyPassword()==0)
       {
          cout<<"Wrong password.Program will now exit\n";
          goto last;
       }
       else
       {
           recordActivity();
            cout<<"Access Granted\n";
            menu();
       }    }
    last:
    return 0;
    }
    void displayJoinedConvos()
    {
        conversation tempConvo,conversations[10];
        ifstream convoData("convodata.dat",ios::binary);
        int j=0;
     int k=0;
User tempUser;
    ifstream data("userdata.dat",ios::binary);
    while(!data.eof())
    {
        data.read((char*)&tempUser,sizeof(tempUser));
        while(!convoData.eof()&&k<currentConversation.convoCount&&j<10)
        {
            k++;
            convoData.read((char*)&tempConvo,sizeof(tempConvo));
            for(int i=0;currentUser.roomsJoined[i]!=0;i++)
            {
                if(currentUser.roomsJoined[i]==tempConvo.convoNo)
                {
                    conversations[j]=tempConvo;


                    j++;
                    cout<<j<<" "<<conversations[j-1].convoName<<"\n";               }
            }
        }
        convoData.close();
        int choice;
        cin>>choice;
        if(choice==0)
        menu();
        currentConversation=conversations[choice-1];
        currentConversation.display();
    }
    }
    void convoUserConnect(User &user1)
    {
        cout<<"connect";
        currentConversation.readUpdateCurrentConvo();
        int i;
        int j;

        for(i=0;user1.roomsJoined[i]!=0;i++);
        cout<<i;
        for(j=0;currentConversation.usersJoined[j]!=0;j++);
        cout<<j;
         system("pause");
        user1.roomsJoined[i]=currentConversation.convoNo;
        currentConversation.usersJoined[j]=user1.userNo;
        currentConversation.updateCurrentConvo();
        user1.updateCurrentUser();

    }
    void exploreMenu()
    {
        int choice;
        cout<<"1.People\n2.Conversations";
        cin>>choice;
        switch(choice)
        {
            case 0:menu();
                   break;
            case 1:currentUser.explorePeople();
                   break;
            case 2:currentConversation.exploreConversation();
                   break;
        }
    }

void addUserConvo(User &user1,User &user2)
{
    cout<<"hi";
    currentConversation.readUpdateCurrentConvo();
    strcpy(currentConversation.convoName,user1.userName);
    strcat(currentConversation.convoName,"+");
    strcat(currentConversation.convoName,user2.userName);
    currentConversation.visibility=0;
    currentConversation.secure=0;

    currentConversation.convoCount+=1;
    cout<<"hi";

    currentConversation.convoNo=currentConversation.convoCount;
     currentConversation.updateCurrentConvo();

    convoUserConnect(user1);
    convoUserConnect(user2);
    currentConversation.updateCurrentConvo();


   currentConversation.display();

}
void User::openInvites()
{
    char choice;
    User tempUser;
    readUpdateUser();
    for(int i=0;i<10;i++)
    {
        if(inviteType[i]=='u')
            {
                tempUser=findUser(invites[i]);
                cout<<tempUser.userName<<" has invited you for a private chat(y/n)";
                cin>>choice;
                if(choice=='y')
                    addUserConvo(*this,tempUser);
                if(choice=='n')
                {
                    cout<<"You have denied request from "<<tempUser.userName<<"\n";
                    system("pause");
                    menu();
                 }

        }    }
system("pause");
}
conversation findConvo(int invite)
{
    conversation tempConvo;
    ifstream readData("conversation.dat",ios::binary);
    if(!readData)
    {
        readData.close();
        cout<<"No conversation data exists on this computer\n";
        exit(0);
    }
    while(!readData.eof())
    {
        readData.read((char*)&tempConvo,sizeof(tempConvo));
        if(tempConvo.convoNo==invite)
        {
            readData.close();
            return tempConvo;
        }
    }
    readData.close();
}
void displayConvoDetails()
{
    int k=1;
    User tempUser;
    ifstream dataRead("userdata.dat",ios::binary);
    int tempUserNo;
    while(!dataRead.eof())
    {
        dataRead.read((char*)&tempUser,sizeof(tempUser));
        if(tempUserNo!=tempUser.userNo)
        {
             tempUserNo=tempUser.userNo;
        for(int i=0;currentConversation.usersJoined[i]!=0;i++)
        {
            for(int j=0;tempUser.roomsJoined[j]!=0;j++)
            {
                if(currentConversation.usersJoined[i]==tempUser.roomsJoined[j])
                   {
                       cout<<k<<". "<<tempUser.userName<<"\n";
                       k++;
                   }            }
        }        }
    }
    dataRead.close();
    system("pause");
}
void exitConversation()
{
    int i=0;
     for(i=0;currentConversation.usersJoined[i]!=currentUser.userNo;i++);
     currentConversation.usersJoined[i]=0;
      for(i=0;currentConversation.convoNo!=currentUser.roomsJoined[i];i++);
      currentUser.roomsJoined[i]=0;
      menu();
}
