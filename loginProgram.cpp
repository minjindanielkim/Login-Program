#include<iostream>
#include<string>
#include<Windows.h>
#define max_len 100
using namespace std;
class log_in{
private:
	char id[max_len];
	char password[max_len];
public:						
	log_in(char * id,char * password){
		strcpy(this->id,id);strcpy(this->password,password);
	}
	void set_id_pw(char * id,char * password){
		strcpy(this->id,id);strcpy(this->password,password);return;
	}
	char * getid(){
		return id;
	}
	void display();
	int search(char * ,char * );
	void insert(char * ,char *);
};
void log_in::display(){
	int i,k;char id[max_len],password[max_len];
	while(true){
		cout<<"1.register"<<endl;
		cout<<"2.login"<<endl;
		cout<<"3.leave"<<endl;
		cout<<"enter >>>";
		cin>>i;
		switch(i){
		case 1:cout<<"enter id :";cin>>id;cout<<"enter password :";cin>>password;insert(id,password);break;
		case 2:cout<<"enter id :";cin>>id;cout<<"enter password :";cin>>password;k=search(id,password);
			if(!k){
				cout<<"login success"<<endl;system("pause");system("cls");
			}
			else cout<<"login fail"<<endl;
			break;
		case 3:exit(1);
		}
		system("pause");system("cls");
	}
}
void log_in::insert(char * id,char * password){
	int i;
	if(getid()){
		cout<<"currently logged in"<<endl;
		system("pause");system("cls");
	}
	while(true){
		cout<<"1.change"<<endl;
		cout<<"2.return"<<endl;
		cout<<"enter >>>>>";cin>>i;
		switch(i){
		case 1:cout<<"enter id : ";cin>>id;cout<<"password : ";cin>>password;set_id_pw(id,password);break;
		case 2:return ;
		}
		system("pause");system("cls");
	}
}
int log_in::search(char * id,char *password){
	if(!(strcmp(this->id,id)||strcmp(password,this->password))){
		return false;
	}return true;
}
int main(){
	log_in log("private","0402");
	log.display();
}
