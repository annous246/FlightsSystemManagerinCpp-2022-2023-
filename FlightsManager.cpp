#include<iostream>
#include<fstream>
#include"fun.cpp"
using namespace std;
int main(){
int n=0,b=0,k,ok=0,v=0,rn,si;
passenger *tp,p;plane *f,*aux;
int nb=0;
		cout<<("Welcome to Emirates Airlines\n");
remove("flights.txt");
do{

cout<<"Give number of flights that you are going to add in total"<<endl;
cin>>nb;}while(nb<1&&nb<100);
for(int i=0;i<100;i++){int j;
	string ss=to_string(i+1);
	char dir[5000]="flight";
	int dl=7;
	for( j=0;j<ss.length();j++){dir[dl-1+j]=ss[j];
	}
	dir[dl-1+j]='.';
	dir[dl+j]='t';
	dir[dl+1+j]='x';
	dir[dl+2+j]='t';
	dir[dl+3+j]='\0';
remove(dir);
	
}
plane *pp;// constructor->maximum number of pass,numero de vole,numero de membres de lequipe d'avion(hotesses,steward, pilotes,marshal,staff technique...),country
int mx,np,nv;
string country;
for(int i=0;i<nb;i++){
	do{cout<<"Give maximum number of passengers on flight number "<<i+1<<"(Including avation staff)"<<endl;
	cin>>mx;
	}while(mx<2);
	do{cout<<"Give maximum number of avation staff on this flight "<<endl;
	cin>>np;
	}while(np<1||np>mx);
	do{cout<<"Give plane country_direction "<<endl;
	cin>>country;
	}while(country.length()==0);
	pp=new plane(mx,i+1,np,country);
	
}
	

string fn,ln;
cout<<("Please choose option\n");
while(1){
	do{
		men:
		cout<<(" (1) Make Reservation\n (2) Cancel Reservation\n (3) Search for Reservation\n (4) Change Reservation \n (5) Display reserving passengers\n (6) Display full flight reservation report\n (7) Display all Programmed flights \n (8) Display canceled reservations \n (9) Clear Display\n (10) Cancel all reservations \n (0) Save & Exit\n");
		cout<<"(666) History Deletion"<<endl;
		cin>>b;
		if((b>10||b<0)&&b!=666){cout<<"This option dosent exist , try again\n";
		}

	}while((b>10||b<0)&&b!=666);
		 f=get_flights(k);
		if(b==1){
		
		 fn,ln;int count=0;
		    for(int i=0;i<k;i++){if(f[i].get_max_p()>f[i].get_nb_p()){count=1;break;
			}
			}if(!count){
				cout<<"Sorry all Programmed flights for the day are Full .Please Book the Upcoming Day"<<endl;goto men;
			}
		do{
		cout<<"Your first name"<<endl;
		cin>>fn;}while(!fn.length());
		do{
		cout<<"Your last name"<<endl;
		cin>>ln;}while(!ln.length());
		passenger p(fn,ln);
		 ok=0;
		do{ v=0;ok=1;
		do{cout<<"Available flights of the day are:"<<endl<<endl;
		    for(int i=0;i<k;i++){if(f[i].get_max_p()>f[i].get_nb_p()){f[i].print();ok=0;
			}
			}
			
			cout<<"Choose a valid flight number to fly on (positive) "<<endl;
			cin>>v;}while(v<1);
			
			 tp=get_passengers(v,n);
			 int al[n],x=0;
			 for(int i=0;i<n;i++){if(tp[i].get_status()){al[x]=tp[i].get_seat();x++;
			 }
			 }
			 heapSort(al,x);
			for(int i=0;i<k;i++){if(f[i].get_num_v()==v){if(f[i].get_nb_p()<f[i].get_max_p()){char key;do{
		   cout<<"do you wanna procede with the reservation ? (NO:press n or N/YES:press y or Y)"<<endl;
		  
		   cin>>key;}while((key!='y')&&(key!='n')&&(key!='Y')&&(key!='N'));
		   if(key=='n'||key=='N'){goto pull;
		   }ok=1;int stt=-1;f[i].set_nb_p(f[i].get_nb_p()+1);change_flight(f,k);
		    
			if(n!=0){
				for(int i=0;i<x;i++){if(al[i]!=i+1){stt=i+1;break;
				}
				}
				if(stt==-1){stt=al[x-1]+1;
				}
			p.make_reservation(v,tp[n-1].get_reservation()+1,stt);
			
			cout<<"Seat number "<<stt<<" is reserved Successfully"<<endl;
			
			}
			else{tp[0].set_flight(v);
			tp[0].set_fn(fn);
			tp[0].set_ln(ln);
			tp[0].set_res_n(1);
			tp[0].set_seat_n(1);
			tp[0].set_status(1);
			p.make_reservation(v,tp[0].get_reservation(),tp[0].get_seat());
			cout<<"Seat number "<<tp[0].get_seat()<<" is reserved Successfully"<<endl;
			}goto e;
			}
			
			
			
			else{cout<<"Sorry flight "<<f[i].get_num_v()<<" is full procede to another flight"<<endl;break;
			}}
			}e:;
		}while(!ok);
		;}
		else if(b==2){
		do{
		
			cout<<"Choose a valid flight number to manipulate (exists)"<<endl;
			cin>>v;}while(v<1);
			 tp=get_passengers(v,n);
			 ok=0;
			 if(n!=0){
			 
			 do{
			 	cout<<"Choose reservation number to cancel"<<endl;
			 	cin>>rn;
			 }while(rn<1);
			 si=search_passenger(v,rn,tp,n);
			 if(si==-1){cout<<"This reservation dosent exist on flight number "<<v<<endl;
			 }
			 else{if(tp[si].get_status()){
			 char ch;do{cout<<"Are you sure you want to cancel Mr(s) "<<tp[si].get_fn()<<" "<<tp[si].get_ln()<<" reservation?(y/n)"<<endl;
			 cin>>ch;
			 
			 }while(ch!='y'&&ch!='n');if(ch=='y'){cancel_reservation(v,rn,tp,n);for(int i=0;i<k;i++){if(f[i].get_num_v()==v){f[i].set_nb_p(f[i].get_nb_p()-1);break;
			 }
			 }change_flight(f,k);
			 cout<<"Reservation number "<<rn<<" on flight "<<v<<" has been canceled"<<endl;
			 }
			 else{cout<<"Cancellation Aborted"<<endl;
			 }
			 }
			 else{cout<<"This reservation has been already canceled"<<endl;
			 }
			 }
			 
			 
			 
		}
		
		}
		else if(b==3){
		do{
		
			cout<<"Choose a valid flight number to manipulate (exists)"<<endl;
			cin>>v;}while(v<1);
			 tp=get_passengers(v,n);
			 ok=0;
			 if(n!=0){
			 	int c=0;
			 	do{
			 		cout<<"Search by:\n (1) First name \n (2) Last name\n (3) Seat number \n (4) Reservation number\n (0) Quit";
			 		cin>>c;
				 }while(c<0&&c>4);
			 switch(c){
			 	case(0):cout<<endl;goto pull;break;
			 	case(1):
			 		do{cout<<"Give First name :"<<endl;
			 		cin>>fn;
					 }while(!fn.length());
					 for(int i=0;i<n;i++){if(cmp(fn,tp[i].get_fn())==0){
			 	if(tp[i].get_status()){
			 		cout<<"This reservation no= "<<tp[i].get_reservation()<<" is valid and exists under the full name "<<tp[i].get_fn()<<" "<<tp[i].get_ln()<<" on the flight "<<v<<endl;
				}
				else{
			 		cout<<"This reservation no= "<<tp[i].get_reservation()<<" is canceled and exists under the full name "<<tp[i].get_fn()<<" "<<tp[i].get_ln()<<" on the flight "<<v<<endl;
				
				}
					 }
					 }
				 ;break;
			 	case(2):
			 		do{cout<<"Give Last name :"<<endl;
			 		cin>>ln;
					 }while(!ln.length());
					 for(int i=0;i<n;i++){if(cmp(ln,tp[i].get_ln())==0){
			 	if(tp[i].get_status()){
			 		cout<<"This reservation no= "<<tp[i].get_reservation()<<" is valid and exists under the full name "<<tp[i].get_fn()<<" "<<tp[i].get_ln()<<" on the flight "<<v<<endl;
				}
				else{
			 		cout<<"This reservation no= "<<tp[i].get_reservation()<<" is canceled and exists under the full name "<<tp[i].get_fn()<<" "<<tp[i].get_ln()<<" on the flight "<<v<<endl;
				
				}
					 }
					 };break;
			 	case(3):
			 do{
			 	cout<<"Choose seat number to find"<<endl;
			 	cin>>rn;
			 }while(rn<1);
			 for(int i=0;i<n;i++){if(tp[i].get_seat()==rn){si=i;
			 	if(tp[si].get_status()){
			 		cout<<"This reservation no= "<<tp[i].get_reservation()<<" is valid and exists under the full name "<<tp[si].get_fn()<<" "<<tp[si].get_ln()<<" on the flight "<<v<<endl;
				}
				else{
			 		cout<<"This reservation no= "<<tp[i].get_reservation()<<" is canceled and exists under the full name "<<tp[si].get_fn()<<" "<<tp[si].get_ln()<<" on the flight "<<v<<endl;
				
				}
			 }
			 }
			 if(si==-1){cout<<"This seat dosent exist or its not reserved yet on flight number "<<v<<endl;
			 }break;
			 	case(4):
			 do{
			 	cout<<"Choose reservation number to find"<<endl;
			 	cin>>rn;
			 }while(rn<1);
			 si=search_passenger(v,rn,tp,n);
			 if(si==-1){cout<<"This reservation dosent exist on flight number "<<v<<endl;
			 }
			 else{
			 	if(tp[si].get_status()){
			 		cout<<"This reservation no= "<<rn<<" is valid and exists under the full name "<<tp[si].get_fn()<<" "<<tp[si].get_ln()<<" on the flight "<<v<<endl;
				}
				else{
			 		cout<<"This reservation no= "<<rn<<" is canceled and exists under the full name "<<tp[si].get_fn()<<" "<<tp[si].get_ln()<<" on the flight "<<v<<endl;
				
				}
				 
			 };break;
			 	
			 }
			 
			 
			 
		}
		else{cout<<"This flight is empty"<<endl;
		}
		}
		else if(b==4){
		do{
		
			cout<<"Choose a valid flight number to manipulate (exists)"<<endl;
			cin>>v;}while(v<1);
			 tp=get_passengers(v,n);
			 ok=0;
			 if(n!=0){
			 
			 do{
			 	cout<<"Choose reservation number to change "<<endl;ok=-1;
			 	cin>>rn;
			 	for(int i=0;i<n;i++){if(tp[i].get_reservation()==rn&&tp[i].get_status()==0){cout<<"Sorry this reservation is canceled"<<endl;goto pull;
				 }
				 }
			 }while(rn<1);
				 do{
				 	cout<<"Do you still want to procede with the change? (0:no/1:yes)"<<endl;
				 	cin>>ok;
				 }while(ok==-1);
				 	if(!ok){goto pull;
					 }
			 si=search_passenger(v,rn,tp,n);
			 if(si==-1){cout<<"This reservation dosent exist on flight number "<<v<<endl;
			 }
			 else{int st;
			 do{
			 	cout<<"Choose the seat to change to"<<endl;
			 	cin>>st;
			 }while(st<1);
			 for(int i=0;i<k;i++){if(f[i].get_num_v()==v&&f[i].get_max_p()<st){cout<<"Sorry this seat dosent exist on this plane"<<endl;goto pull;
			 }
			 }
			 int id=-1;
			 for(int i=0;i<n;i++){if(tp[i].get_seat()==st&&(tp[i].get_status()&&tp[i].get_reservation()!=v)){goto h;
			 }
			 else if(tp[i].get_seat()==st){id=i;
			 }
			 }if(id!=-1){
			 	int aux=tp[si].get_seat();
			 	
			 	if(aux==tp[id].get_seat()){cout<<"You are already on this seat , please choose a different one"<<endl;
				 }
				 else{
			 	change_reservation(v,rn,st,tp,n);
			 	cout<<"Mr(s) "<<tp[si].get_fn()<<" "<<tp[si].get_ln()<<" reserved seat number "<<aux<<" is changed to seat number "<<tp[si].get_seat()<<" replacing mr(s) "<<tp[id].get_fn()<<" "<<tp[id].get_ln()<<"'s canceled reservation."<<endl;
			 	
				 }
			 }
			 else{
			 	int aux=tp[si].get_seat();
			 	change_reservation(v,rn,st,tp,n);
			 	cout<<"Mr(s) "<<tp[si].get_fn()<<" "<<tp[si].get_ln()<<" reserved seat number "<<aux<<" is changed to seat number "<<st<<" as a first reserver"<<endl;
			 	
			 }
			 if(0){h:cout<<"Sorry this seat is reserved "<<endl;
			 }
				 
			 }
			 
			 
			 
		}
		}
		
		else if(b==5){
		do{
		
			cout<<"Choose a valid flight number to manipulate (exists)"<<endl;
			cin>>v;}while(v<1);
			 tp=get_passengers(v,n);
			cout<<"List of flight number "<<v<<" reserving passengers:"<<endl;
			for(int i=0;i<n;i++){
				if(tp[i].get_status()){
				cout<<"-Mr(s) "<<tp[i].get_fn()<<" "<<tp[i].get_ln()<<" -> Seat number "<<tp[i].get_seat()<<endl;
				}
			}
		}
		else if(b==6){
		do{
		
			cout<<"Choose a valid flight number to get full status report (exists)\n"<<endl;
			cin>>v;}while(v<1);
			 tp=get_passengers(v,n);
			cout<<"List of flight number "<<v<<" full status report :\n"<<endl;
			for(int i=0;i<n;i++){
				tp[i].print();
			}
		}
			
		else if(b==9){system("CLS");
		}
		else if(b==7){
			cout<<"List of all programmed flights in total p\n"<<endl;
			for(int i=0;i<k;i++){
				f[i].print();
			}
			
		}
		else if(b==8){
		do{
		
			cout<<"Choose a valid flight number to manipulate (exists)"<<endl;
			cin>>v;}while(v<1);
			 tp=get_passengers(v,n);
			cout<<"List of flight number "<<v<<" canceled passengers:"<<endl;
			for(int i=0;i<n;i++){
				if(!tp[i].get_status()){
				cout<<"-Mr(s) "<<tp[i].get_fn()<<" "<<tp[i].get_ln()<<" with a canceled reservation number ="<<tp[i].get_reservation()<<endl;
				}
			}
		}
		else if(b==10){
		do{
		
			cout<<"Choose a valid flight number to manipulate (exists)"<<endl;
			cin>>v;}while(v<1);
			 tp=get_passengers(v,n);int w=-1;for(int i=0;i<k;i++){if(f[i].get_num_v()==v){w=i;break;
			 }
			 }
			 for(int i=0;i<n;i++){cancel_reservation(v,i+1,tp,n);f[w].set_nb_p(f[w].get_nb_p()-1);change_flight(f,k);
			 }
		}
		
		else if(b==666){
			int ck=0;
			cout<<"Danger Zone!"<<endl;
			do{
			cout<<"Do you want to erase all Flights history? (666 to confirm)"<<endl;
			cin>>ck;
			}while(ck!=666);
			do{
			cout<<"Are you certain ? (Second Fail-Safe)"<<endl;
			cin>>ck;
			}while(ck!=666);
            remove("flight_history.txt");
            fstream in,out;char dir2[5000]="flight_history.txt";
			cout<<"Flights-History Erased"<<endl;
			
		
		}
		else{goto exit;
		}pull:;
	}
	

	exit:
		//Saving section
		
		
 fstream in,out;char dir2[5000]="flight_history.txt";
	string var="1";int j;
 out.open(dir2,ios::in);
 string line;
 char auxx[500];
 int d,okk=0;
 while(getline(out,line)){
 	if(line[0]=='D'){okk=1;
 	for( j=0;j<line.length()-4;j++){auxx[j]=line[j+4];
	 }
	 }auxx[j]='\0';
 }var=auxx;
	 if(!okk)d=0;
	 else d=stoi(var);
	 d++;
	 var=to_string(d);
 out.close();
 
 out.open(dir2,ios::app);
 out<<"Day "+var+"\n\n";
for(int i=0;i<nb;i++){int j;
	string ss=to_string(i+1);
	char dir[5000]="flight";int dl=7;
	for( j=0;j<ss.length();j++){dir[dl-1+j]=ss[j];
	}
	dir[dl-1+j]='.';
	dir[dl+j]='t';
	dir[dl+1+j]='x';
	dir[dl+2+j]='t';
	dir[dl+3+j]='\0';
 in.open(dir,ios::in);
 out<<"Flight "+to_string(i+1)<<endl<<endl;
 while(getline(in,line)){
 	out<<line<<endl;
 }
	
in.close();
}
out.close();
//end saving process


		cout<<"note : all text files will be deleted automatically after the next execution!(Except flight history)"<<endl;
	cout<<"Thanks for using our flight management system!"<<endl;}

	
	
	
	

