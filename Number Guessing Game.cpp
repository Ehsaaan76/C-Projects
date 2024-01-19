#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
int main() {
	int user,count=1;
    srand(time(nullptr));
	int randomNumber = 1+ (rand() % 10);
	cout<<randomNumber<<endl;
	cout<<"Guess the number between (1-10) : ";
	cin>>user;
	while(user!=randomNumber){
		if((randomNumber>user && randomNumber<user+2) || (randomNumber<user && user<randomNumber+2)){
			cout<<"Close Try"<<endl;
			count += 1;
			cout<<"Wrong Guess! Try Again : ";
			cin>>user;
		}
		else{
			count += 1;
			cout<<"Wrong Input! Try Again : ";
			cin>>user;
	
		}
	}
	cout<<"Right Guess "<<endl;
	cout<<"Tries : "<<count;
    return 0;
}