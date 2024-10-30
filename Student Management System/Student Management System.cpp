#include<iostream>
#include<limits>
#include<windows.h>
#include <algorithm>

using namespace std;

class Management {
public:

    struct Student {
        int student_id;
        int admission_year;
        string name;
        string Class;
        string degree;
        int paid_fee;
        int remaining_fee=0;
    };
	Student std[30];
};

class Login:public Management{
	public:

	void login(){
	string user;
	int pass;
    cout<<"\n\n\t\t\t\t\t|--------------LOGIN----------------|"<<endl;
    cout<<"\n\t\t\t\t\tEnter your User Name : ";
    cin>>user;
   while(user!="admin123"){
    cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout<<"\n\t\t\t\t\tERROR.....! Wrong User Name!";
    cout<<"\n\t\t\t\t\tEnter username Again: ";
    cin>>user;
   }
    cout<<"\n\t\t\t\t\tEnter Password : ";
    cin>>pass;
 	while(pass!=46465) {
    cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout<<"\n\t\t\t\t\tERROR.....! Wrong Password!";
    cout<<"\n\t\t\t\t\tEnter Password Again: ";
    cin>>pass;
 	}
        system("cls");
        cout << "logging in";
        for (int i = 0; i < 10; i++){
            cout << ".";
            Sleep(200);
        } 
        cout<<"\nSuccessfully Logged In"<<endl;
        cout<<endl;
	}
};
	    
class Student_Management:public Management{
		public:
		static int total;
		const int total_fee=50000;
		void Insert_Data(){
	    int ch;
    	cout << "Enter The Number of Students you want to add: ";
    	do {
        if (!(cin >> ch) || cin.peek() != '\n' || ch < 1 || ch > 30) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a numeric digit between 1 and 30: ";
        }
    	} while (cin.peek() != '\n' || ch < 1 || ch > 30); 
    		
		if(total==0){
		total=ch+total;
		for(int i=0; i<ch; i++){
			cout<<"\nEnter the Data of student "<<i+1<<endl<<endl;
			
			cout<<"Enter Student ID : "<<endl;
			while (!(cin >> std[i].student_id) || cin.peek() != '\n' || std[i].student_id < 1 || std[i].student_id> 999999) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a valid sap ID of 6 or fewer digits: ";
			}
				
			cout<<"Enter Name(30): "<<endl;
			cin.ignore();
			getline(cin,std[i].name);
			while (cin.fail() || std[i].name.length() > 30 || !all_of(std[i].name.begin(), std[i].name.end(), [](unsigned char c) { return (isspace(c) || isalpha(c)); })) {
		    cin.clear();
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		    cout << "Please enter a valid name of 30 characters : ";
		    getline(cin,std[i].name);
			}
			cout << "Enter Class: ";
			getline(cin, std[i].Class);
			
			cout << "Enter degree: ";
			getline(cin,std[i].degree);
			while (cin.fail() || std[i].degree.length() > 40 || !all_of(std[i].degree.begin(), std[i].degree.end(), [](unsigned char c) { return (isspace(c) || isalpha(c)); })) {
		    cin.clear();
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		    cout << "Please enter a valid degree name of 40 characters : ";
		    getline(cin,std[i].degree);
			}
			cout<<"Enter Admission Year: "<<endl;
			cin>>std[i].admission_year;
			while(cin.fail() || std[i].admission_year<1990 || std[i].admission_year>2023){
			    cin.clear();
			    cin.ignore(numeric_limits<streamsize>::max(),'\n');
			    cout<<"Please Enter Valid Admission Year(1990 - 2023) : ";
			    cin>>std[i].admission_year;
			}
			cout<<"Paid fee out of 50000 : ";
			while (!(cin >> std[i].paid_fee) || cin.peek() != '\n' || std[i].paid_fee < 1 || std[i].paid_fee> total_fee) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a valid amount (0 - 50000) : ";
			}
			std[i].remaining_fee=total_fee-std[i].paid_fee;
			cout<<"Student Added Successfully"<<endl;
			}
		}
			else
			{
			for(int i=total;i<ch+total;i++){
			cout<<"\nEnter the Data of student "<<i+1<<endl<<endl;
			
			cout<<"Enter Student ID : "<<endl;
			while (!(cin >> std[i].student_id) || cin.peek() != '\n' || std[i].student_id < 1 || std[i].student_id > 999999) {
			    cin.clear();
			    cin.ignore(numeric_limits<streamsize>::max(), '\n');
			    cout << "Invalid input. Please enter a valid sap ID of 6 or fewer digits: ";
				}
				
			cout<<"Enter Name(30): "<<endl;
			cin.ignore();
			getline(cin,std[i].name);
			while (cin.fail() || std[i].name.length() > 30 || !all_of(std[i].name.begin(), std[i].name.end(), [](unsigned char c) { return (isspace(c) || isalpha(c)); })) {
		    cin.clear();
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		    cout << "Please enter a valid name of 30 characters : ";
		    getline(cin,std[i].name);
			}
			cout << "Enter Class: ";
			getline(cin, std[i].Class);
			
			cout << "Enter degree: ";
			getline(cin,std[i].degree);
			while (cin.fail() || std[i].degree.length() > 40 || !all_of(std[i].degree.begin(), std[i].degree.end(), [](unsigned char c) { return (isspace(c) || isalpha(c)); })) {
		    cin.clear();
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		    cout << "Please enter a valid degree name of 40 characters : ";
		    getline(cin,std[i].degree);
			}
			cout<<"Enter Admission Year: "<<endl;
			cin>>std[i].admission_year;
			while(cin.fail() || std[i].admission_year<1990 || std[i].admission_year>2023){
			    cin.clear();
			    cin.ignore(numeric_limits<streamsize>::max(),'\n');
			    cout<<"Please Enter Valid Admission Year(1990 - 2023) : ";
			    cin>>std[i].admission_year;
			}
			cout<<"Paid fee out of 50000 : ";
			while (!(cin >> std[i].paid_fee) || cin.peek() != '\n' || std[i].paid_fee < 1 || std[i].paid_fee> total_fee) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a valid amount (0 - 50000) : ";
			}
			std[i].remaining_fee=total_fee-std[i].paid_fee;
			cout<<"Student Added Successfully"<<endl;
			}
			total=ch+total;
		}
	}
	
	
		void Display_Data()	{
			if(total==0)
			cout<<"No Data is Entered yet"<<endl;
			else
			{
			for(int i=0;i<total;i++){
			cout<<"\nDisplaying Data : "<<endl<<endl;
			cout<<"Data of Student : "<<i+1<<endl;
			cout<<"Sap ID : "<<std[i].student_id<<endl;
			cout<<"Name : "<<std[i].name<<endl;
			cout<<"Class : "<<std[i].Class<<endl;
			cout<<"degree : "<<std[i].degree<<endl;
			cout<<"Admission Year : "<<std[i].admission_year<<endl;
			cout<<"Paid Fee : "<<std[i].paid_fee<<endl<<endl;
			cout<<"Data Displayed Successfully"<<endl;
			
			}
		}
	}
		
	    void Update_Data(){
			if(total==0){
			cout<<"No data is entered yet"<<endl;
			}
			else                             
			{
			bool found=false;
			int stuID2;
			cout<<"Enter the Student ID of a student : "<<endl;
			while (!(cin >> stuID2) || cin.peek() != '\n' || stuID2 < 1 || stuID2 > 999999) {
			    cin.clear();
			    cin.ignore(numeric_limits<streamsize>::max(), '\n');
			    cout << "Invalid input. Please enter a valid sap ID of 6 or fewer digits: ";
				}
			for(int i=0;i<total;i++){
			if(stuID2==std[i].student_id){
			found=true;
			cout<<"\nPrevious data"<<endl<<endl;
			cout<<"Data of Student "<<i+1<<endl;
			cout<<"Sap ID: "<<std[i].student_id<<endl;
			cout<<"Name "<<std[i].name<<endl;
			cout<<"Class "<<std[i].Class<<endl;
			cout<<"degree "<<std[i].degree<<endl;
			cout<<"Admission Year "<<std[i].admission_year<<endl;
			cout<<"Paid Fee : "<<std[i].paid_fee<<endl;
			cout<<"\nEnter new data"<<endl<<endl;
			
			cout<<"Enter Student ID : "<<endl;
			while (!(cin >> std[i].student_id) || cin.peek() != '\n' || std[i].student_id < 1 || std[i].student_id> 999999) {
			    cin.clear();
			    cin.ignore(numeric_limits<streamsize>::max(), '\n');
			    cout << "Invalid input. Please enter a valid sap ID of 6 or fewer digits: ";
				}
				
			cout<<"Enter Name(30): "<<endl;
			cin.ignore();
			getline(cin,std[i].name);
			while (cin.fail() || std[i].name.length() > 30 || !all_of(std[i].name.begin(), std[i].name.end(), [](unsigned char c) { return (isspace(c) || isalpha(c)); })) {
		    cin.clear();
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		    cout << "Please enter a valid name of 30 characters : ";
		    getline(cin,std[i].name);
			}
			cout << "Enter Class: ";
			getline(cin, std[i].Class);
			
			cout << "Enter degree: ";
			getline(cin,std[i].degree);
			while (cin.fail() || std[i].degree.length() > 40 || !all_of(std[i].degree.begin(), std[i].degree.end(), [](unsigned char c) { return (isspace(c) || isalpha(c)); })) {
		    cin.clear();
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		    cout << "Please enter a valid degree name of 40 characters : ";
		    getline(cin,std[i].degree);
			}
			cout<<"Enter Admission Year: "<<endl;
			cin>>std[i].admission_year;
			while(cin.fail() || std[i].admission_year<1990 || std[i].admission_year>2023){
			    cin.clear();
			    cin.ignore(numeric_limits<streamsize>::max(),'\n');
			    cout<<"Please Enter Valid Admission Year(1990 - 2023) : ";
			    cin>>std[i].admission_year;
			}
			cout<<"Paid fee out of 5000 : ";
			while (!(cin >> std[i].paid_fee) || cin.peek() != '\n' || std[i].paid_fee < 1 || std[i].paid_fee> 5000) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a valid amount (0 - 5000) : ";
			}
			std[i].remaining_fee=total_fee-std[i].paid_fee;
			cout<<"Data Updated Successfully";
				}
			}
			if(!found){
				cout<<"\nData Not Found!!!"<<endl;
				cout<<"Back to MENU"<<endl;
			}

		 	}
		}

		void search_by_student_id(){
			bool found=false;
			int stuID1;
			cin.ignore();
			cout<<"Enter the Sap ID of student : ";
			while (!(cin >>stuID1) || cin.peek() != '\n' || stuID1< 1 || stuID1 > 999999) {
			    cin.clear();
			    cin.ignore(numeric_limits<streamsize>::max(), '\n');
			    cout << "Invalid input. Please enter a valid sap ID of 6 or fewer digits: ";
				}
			for(int i=0;i<total;i++){
			if(stuID1==std[i].student_id){
			found=true;
			cout<<"Data Found"<<endl<<endl;
			cout<<"Student ID "<<std[i].student_id<<endl;
			cout<<"Name "<<std[i].name<<endl;
			cout<<"Class "<<std[i].Class<<endl;
			cout<<"degree "<<std[i].degree<<endl;
			cout<<"Admission Year "<<std[i].admission_year<<endl;
			cout<<"Paid Fee : "<<std[i].paid_fee<<endl;	
			}
			cout<<endl;
		}
	
		if(!found){
			cout<<"Data Not Found!!!"<<endl;
			cout<<"Back to MENU"<<endl;
		}
	} 	
	
		void search_by_Name(){
			
			bool found=false;
			string name1;
			cout<<"Enter the Name of student : ";
			cin.ignore();
			getline(cin,name1);
			while (cin.fail() || name1.length() > 30 || !all_of(name1.begin(), name1.end(), [](unsigned char c) { return (isspace(c) || isalpha(c)); })) {
		    cin.clear();
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		    cout << "Please enter a valid name of 30 characters : ";
		    getline(cin,name1);
			}
			for(int i=0;i<total;i++){
			if(name1==std[i].name){
			found=true;
			cout<<"Data Found"<<endl<<endl;
			cout<<"Student ID "<<std[i].student_id<<endl;
			cout<<"Name "<<std[i].name<<endl;
			cout<<"Class "<<std[i].Class<<endl;
			cout<<"degree "<<std[i].degree<<endl;
			cout<<"Admission Year "<<std[i].admission_year<<endl;
			cout<<"Paid Fee : "<<std[i].paid_fee<<endl;
				}
				cout<<endl;
			}
		
		if(!found){
			cout<<"Data Not Found!!!"<<endl;
			cout<<"Back to MENU"<<endl;
		}
	}
	 	
		void search_by_Class(){
			
			bool found=false;
			string Class1;
			cout<<"Enter the Class of student : ";
			cin.ignore();
			getline(cin,Class1);
			for(int i=0;i<total;i++){
			if(Class1==std[i].Class){
			found=true;
			cout<<"Data Found"<<endl<<endl;
			cout<<"Student ID "<<std[i].student_id<<endl;
			cout<<"Name "<<std[i].name<<endl;
			cout<<"Class "<<std[i].Class<<endl;
			cout<<"degree "<<std[i].degree<<endl;
			cout<<"Admission Year "<<std[i].admission_year<<endl;
			cout<<"Paid Fee : "<<std[i].paid_fee<<endl;
				}
				cout<<endl;
			}
		
		if(!found){
			cout<<"Data Not Found!!!"<<endl;
			cout<<"Back to MENU"<<endl;
		}
	}
	 	
		void search_by_degree(){
			bool found=false;
			string degree1;
			cout<<"Enter the degree of student : ";
			cin.ignore();
			getline(cin,degree1);
			while (cin.fail() || degree1.length() > 40 || !all_of(degree1.begin(), degree1.end(), [](unsigned char c) { return (isspace(c) || isalpha(c)); })) {
		    cin.clear();
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		    cout << "Please enter a valid degree name of 40 characters : ";
		    getline(cin,degree1);
			}
			for(int i=0;i<total;i++){
			if(degree1==std[i].degree){
			found=true;
			cout<<"Data Found"<<endl<<endl;
			cout<<"Student ID "<<std[i].student_id<<endl;
			cout<<"Name "<<std[i].name<<endl;
			cout<<"Class "<<std[i].Class<<endl;
			cout<<"degree "<<std[i].degree<<endl;
			cout<<"Admission Year "<<std[i].admission_year<<endl;
			cout<<"Paid Fee : "<<std[i].paid_fee<<endl;
				}
				cout<<endl;
			}
		
		if(!found){
			cout<<"Data Not Found!!!"<<endl;
			cout<<"Back to MENU"<<endl;
		}
	}
		
		void search_by_Admission_Year(){
			bool found=false;
			int admission_year1;
			cout<<"Enter Admission Year: "<<endl;
			cin>>admission_year1;
			while(cin.fail() || admission_year1<1990 || admission_year1>2023){
			    cin.clear();
			    cin.ignore(numeric_limits<streamsize>::max(),'\n');
			    cout<<"Please Enter Valid Admission Year(1990 - 2023) : ";
			    cin>>admission_year1;
			}
			for(int i=0;i<total;i++){
			if(admission_year1==std[i].admission_year){
			found=true;
			cout<<"Data Found"<<endl<<endl;
			cout<<"Student ID "<<std[i].student_id<<endl;
			cout<<"Name "<<std[i].name<<endl;
			cout<<"Class "<<std[i].Class<<endl;
			cout<<"degree "<<std[i].degree<<endl;
			cout<<"Admission Year "<<std[i].admission_year<<endl;
			cout<<"Paid Fee : "<<std[i].paid_fee<<endl;
				}
				cout<<endl;
			}
		
		if(!found){
			cout<<"Data Not Found!!!"<<endl;
			cout<<"Back to MENU"<<endl;
		}
	}

		void fee(){
		if(total==0)
			cout<<"No Data is Entered yet"<<endl;
			else
			{
			int fe;
			cout<<"1-View Fee Record"<<endl;
			cout<<"2-Submit Fee"<<endl;
			cout<<"3-Back"<<endl;
			while (!(cin>>fe) || cin.peek() != '\n' || fe<1 || fe>3) {
			cin.clear();
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		    cout << "Invalid input. Please enter a valid value between(1 - 3) : ";
			}
			switch(fe){
				case 1:
					{
					cout<<"\nDisplaying Data : "<<endl<<endl;
					for(int i=0; i<total; i++){
						cout<<"Data of Student : "<<i+1<<endl;
						cout<<"Student ID : "<<std[i].student_id<<endl;
						cout<<"Name : "<<std[i].name<<endl;
						cout<<"Remaining Fee : "<<total_fee-std[i].paid_fee<<endl;
						cout<<endl;
					}
					break;
				}
				case 2:
					{
						int stuid3;
						long id;
						int amount;
						string bankname;
			
					bool found=false;
					cin.ignore();
					cout<<"Enter sap ID : "<<endl;
					while (!(cin >>stuid3) || cin.peek() != '\n' || stuid3< 1 || stuid3 > 999999) {
					    cin.clear();
					    cin.ignore(numeric_limits<streamsize>::max(), '\n');
					    cout << "Invalid input. Please enter a valid sap ID of 6 or fewer digits: ";
						}
					for(int i=0;i<total;i++){
					if(stuid3==std[i].student_id){
					cout<<"Data Found"<<endl<<endl;
					cout<<"Student ID : "<<std[i].student_id<<endl;
					cout<<"Name : "<<std[i].name<<endl;
					cout<<"Remaining Fee : "<<total_fee-std[i].paid_fee<<endl<<endl;
					if(std[i].remaining_fee < 1){
						cout<<"Fee Cleared "<<endl;
						break;
					}
					else{
					cout<<"Enter Bank Name : ";
					cin.ignore();
					getline(cin,bankname);
					while (cin.fail() || bankname.length() > 50 || !all_of(bankname.begin(), bankname.end(), [](unsigned char c) { return (isspace(c) || isalpha(c)); })) {
				    cin.clear();
				    cin.ignore(numeric_limits<streamsize>::max(), '\n');
				    cout << "Please enter a valid name of 30 characters : ";
				    getline(cin,bankname);
					}
					cout<<"Enter Transaction id number : ";
					while (!(cin >>id) || cin.peek() != '\n' || id< 1) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Please enter a valid Number : ";
					}
					cout << "Enter the Fee Amount: ";
              		while (!(cin >> amount) || cin.peek() != '\n' || amount < 1 || amount > std[i].remaining_fee) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Please enter a valid amount (1 - " << std[i].remaining_fee << "): ";
                }
					std[i].paid_fee+=amount;
					std[i].remaining_fee -= amount;
					cout<<"Fee Updated Successfully"<<endl;
					found=true;
					break;
				}
			}
		}
					if(!found){
						cout<<"\nData not Found "<<endl;
						cout<<"Back to MENU"<<endl<<endl;
						break;
					}
				
					break;
				}
				
				case 3:
					break;
					
				default:
					{
					cout<<"Error Occurred"<<endl;
				}
				
			}
		}
	}
};

int Student_Management::total = 0;

class Deletion:public Student_Management{
	public:
		void Delete_Data(){
			if(total==0)
			cout<<"No data is entered yet"<<endl;
			else
			{
			int a;
			cout<<"Are you Sure to Delete Data?"<<endl;
			cout<<"Press 1 to Delete All Records"<<endl;
			cout<<"Press 2 to Go Back"<<endl;
			cin>>a;
			switch(a){
				case 1:
					int b;
					cout<<"Are you sure You want to Delete All Data ?"<<endl;
					cout<<"1-Yes\n2-NO"<<endl;
					cin>>b;
						switch(b){
							case 1:
								total=0;
								system("cls");
								cout<<"Deleting Data";
								for(int i = 0; i < 10; i++){
							    cout<<".";
						        Sleep(200);
						    	}
					        	cout<<"\nAll records are deleted..!!"<<endl;
					        	break;
					        	
					        case 2:
					        	cout<<"\nData Not Deleted"<<endl;
					        	break;
					        	
					        default:
					        	cout<<"You Entered Something else."<<endl;
					        	cout<<"Data Not Deleted."<<endl;
					        	break;
					        }
					        break;
					        
							case 2:	
								cout<<"Back to MENU"<<endl;
								break;
								
							default:
					        	cout<<"You Entered Something else."<<endl;
					        	cout<<"Data Not Deleted."<<endl;
					        	break; 
			}		
		}
	}


};

	
int main(){
				system("color f1");
				Login l1;
				Student_Management stm;
			    Deletion d;
			    l1.login();
			    int value;
			    while(true){
			    	        cout<<"\n\n--------------Menu--------------"<<endl<<endl;
							cout<<"Press 1  to Insert data"<<endl<<endl;
							cout<<"Press 2 to Display  data"<<endl<<endl;
							cout<<"Press 3 to Search data"<<endl<<endl;
							cout<<"Press 4 to Update data"<<endl<<endl;
							cout<<"Press 5 to Delete data"<<endl<<endl;
							cout<<"Press 6 to go to Fee Department"<<endl<<endl;
							cout<<"Press 7 to Log Out"<<endl<<endl;
					     	while (!(cin>>value) || cin.peek() != '\n' || value<1 || value>7) {
							    cin.clear();
							    cin.ignore(numeric_limits<streamsize>::max(), '\n');
							    cout << "Invalid input. Please enter a valid value between(1 - 7) : ";
								}
						switch(value){
						case 1:
						    stm.Insert_Data();
						   break;
						case 2:
							stm.Display_Data();
							break;
						case 3:
							int choice;
							if(stm.total==0)
							cout<<"No data is entered yet"<<endl;
							else
							{
							cout<<"Press 1 to Search by Sap ID "<<endl;
							cout<<"Press 2 to Search by Name "<<endl;
							cout<<"Press 3 to Search by Class "<<endl;
							cout<<"Press 4 to Search by degree "<<endl;
							cout<<"Press 5 to Search by Admission Year "<<endl;
							cout<<"Press 6 to Go Back"<<endl;
							cin>>choice;
							switch(choice){
								case 1:
									stm.search_by_student_id();
									break;
									
								case 2:
									stm.search_by_Name();
									break;
									
								case 3:
									stm.search_by_Class();
									break;
									
								case 4:
									stm.search_by_degree();
									break;
									
								case 5:
									stm.search_by_Admission_Year();
									break;
									
								case 6:
									cout<<"Back to MENU";
									break;	
									
								default:
									cout<<"You Entered Something else"<<endl;
							}
						}
							break;
							
						case 4:
							stm.Update_Data();
							break;
							
						case 5:
							d.Delete_Data();
							break;
							
						case 6:
							stm.fee();
							break;
							
						case 7:
							system("cls");
					        cout << "logging out";
					        for (int i = 0; i < 10; i++){
					            cout << ".";
					            Sleep(200);
					        } 
					        cout<<"\nSuccessfully Logged Out";
							exit(0);
							break;
						default:
						cout<<"You Entered Something else."<<endl;
						break;
						}
					}
				}