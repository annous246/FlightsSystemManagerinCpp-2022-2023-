#include"lib.h"

int search_passenger(int flight,int res_n,passenger *p,int n);

void swap(int* a, int* b)
{
 int temp = *a;*a = *b; *b = temp;
}
 
void heapify(int arr[], int N, int i){
    int largest = i;
 
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && arr[left] > arr[largest])
        largest = left;
    if (right < N && arr[right] > arr[largest])
 
        largest = right;
    if (largest != i) {
 
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}
void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
 
        heapify(arr, N, i);
    for (int i = N - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int cmp(string a,string b){
int n1=a.length(),n2=b.length();
if(n1>n2){return 1;
}
else if(n2<n1){return -1;
}
else{
	for(int i=0;i<n1;i++){if(a[i]!=b[i]){return ((char) a[i]>(char)b[i])?1:-1;
	}
	}
}return 0;
}


passenger::passenger(){
res_n=0;
seat_n=0;
flight=0;
f_name="";
l_name="";
}
passenger::passenger(string f_name,string l_name){
		this->f_name=f_name;
		this->l_name=l_name;
		res_n=0;
		seat_n=0;
		status=0;
		
		}
string passenger::get_fn(){
	return f_name;
}
string passenger::get_ln(){
	return l_name;
}
int passenger::get_reservation(){return res_n;
}
int passenger::get_status(){return status;
}
int passenger::get_seat(){return seat_n;
}
int passenger::get_flight(){return flight;
}
void passenger::set_fn(string &a){f_name=a;
}
void passenger::set_ln(string &a){l_name=a;
}
void passenger::set_status(int a){status=a;
}
void passenger::set_res_n(int a){res_n=a;
}
void passenger::set_seat_n(int a){seat_n=a;
}
void passenger::set_flight(int a){flight =a;
}
void passenger::print(){
	string ss;
	if(status){ss="validated";
	}
	else{ss="canceled";
	}
cout<<" Reservation number: "<<res_n<<"\n First name: "<<f_name<<"\n Last name: "<<l_name<<"\n Registered Seat number: "<<seat_n<<"\n Reservation status= "<<ss<<"\n Designated flight: "<<flight<<"\n"<<endl;
}


void cancel_reservation(int flight_n,int res,passenger *p,int n){
	int ind=search_passenger(flight_n,res,p,n);
	p[ind].set_status(0);
	fstream file;
	string f=to_string(flight_n);
	string adir="flight"+f+".txt";
	char dir[50000];
	int i;
	for( i=0;i<adir.length();i++){dir[i]=adir[i];
	}
	dir[i]='\0';
	
	file.open(dir,ios::out);
	if(file.is_open()){
		for(int i=0;i<n;i++){
		string r=to_string(p[i].get_reservation());
		string st=to_string(p[i].get_seat());
		string ss="";
		if(i!=ind){if(p[i].get_status()){ss="validated";
		}
		else{ss="canceled";
		}
		}
		else{ss="canceled";
		}
		file<<"reservation: "<<r<<endl;
		file<<"first name: "<<p[i].get_fn()<<endl;
		file<<"last name: "<<p[i].get_ln()<<endl;
		file<<"seat number: "<<st<<endl;
		file<<"Status="<<ss<<endl;
		file<<endl;
		}
		file.close();
	}
	else{cout<<"error while opening reservation file (check directory)"<<endl;
	}
	
}

void change_reservation(int flight_n,int res,int st,passenger *p,int n){
	int ind=search_passenger(flight_n,res,p,n);
	p[ind].set_seat_n(st);
	fstream file;
	string f=to_string(flight_n);
	string adir="flight"+f+".txt";
	char dir[50000];
	int i;
	for( i=0;i<adir.length();i++){dir[i]=adir[i];
	}
	dir[i]='\0';
	
	file.open(dir,ios::out);
	if(file.is_open()){
		for(int i=0;i<n;i++){
		string r=to_string(p[i].get_reservation());
		string st=to_string(p[i].get_seat());
		string ss="";
		if(p[i].get_status()==0){ss="canceled";
		}
		else{ss="validated";
		}
		file<<"reservation: "<<r<<endl;
		file<<"first name: "<<p[i].get_fn()<<endl;
		file<<"last name: "<<p[i].get_ln()<<endl;
		file<<"seat number: "<<st<<endl;
		file<<"Status="<<ss<<endl;
		file<<endl;
		}
		file.close();
	}
	else{cout<<"error while opening reservation file (check directory)"<<endl;
	}
	
}

void passenger::make_reservation(int flight_n,int res,int seat){
	flight=flight_n;
	res_n=res;
	seat_n=seat;
	status=1;
	fstream file;
	string f=to_string(flight_n);
	string adir="flight"+f+".txt";
	char dir[50000];
	int i;
	for( i=0;i<adir.length();i++){dir[i]=adir[i];
	}
	dir[i]='\0';
	string r=to_string(res);
	string st=to_string(seat);
	string ss="validated";
	file.open(dir,ios::app);
	if(file.is_open()){
		file<<"reservation: "<<r<<endl;
		file<<"first name: "<<get_fn()<<endl;
		file<<"last name: "<<get_ln()<<endl;
		file<<"seat number: "<<st<<endl;
		file<<"Status="<<ss<<endl;
		file<<endl;
		file.close();
	}
	else{cout<<"error while opening reservation file (check directory)"<<endl;
	}
}
plane::plane(){
num_vol=0;
max_pass=0;
nb_pass=0;
}
plane::plane(int max_pass,int num_vol,int nb_pass,string p){
	this->num_vol=num_vol;
	this->nb_pass=nb_pass;
	this->max_pass=max_pass;
	pays=p;
	string v=to_string(num_vol);
	fstream file;
	
	string adir="flight"+v+".txt";
	string f=to_string(num_vol);
	string np=to_string(nb_pass);
	string m=to_string(max_pass);
	char dir[50000];
	int i;
	for( i=0;i<adir.length();i++){dir[i]=adir[i];
	}
	dir[i]='\0';
    file.open(dir,ios::out);
	file.close();
	
	adir="flights.txt";
	for( i=0;i<adir.length();i++){dir[i]=adir[i];
	}
	dir[i]='\0';
	
	
    file.open(dir,ios::app);
	if(file.is_open()){
		file<<"flight number "+f<<endl;
		file<<"to : "<<p<<endl;
		file<<"number of passengers is: "+np<<endl;
		file<<"maximum capacity is: "+m<<endl<<endl;
		file.close();
	}
	else{cout<<"error while opening reservation file (check directory)"<<endl;
	}
	
}
void plane::set_max_p(int n){
	max_pass=n;
}
void plane::set_nb_p(int n){
	nb_pass=n;
}
void plane::set_num_v(int n){
	num_vol=n;
}
void plane::set_pays(string p){pays=p;
}
int plane::get_max_p(){return max_pass;
}
int plane::get_nb_p(){return nb_pass;
}
int plane::get_num_v(){return num_vol;
}
string plane::get_pays(){return pays;
}
void plane::print(){
	
	cout<<"Flight number "<<num_vol<<"\nto "<<pays<<"\nNumber of passengers is :"<<nb_pass<<"\nMaximum capacity :"<<max_pass<<"\n"<<endl;
}

int search_passenger(int flight,int res_n,passenger *p,int n){
	for(int i=0;i<n;i++){if(res_n==p[i].get_reservation()&&flight==p[i].get_flight()){return i;
	}
	}return -1;
}
passenger * get_passengers(int flight,int &l){
	passenger *p=new passenger[5000];
	int i=0;
	string f=to_string(flight);
	fstream file;
	string adir="flight"+f+".txt";
	
	char dir[50000];int v;
	for(  v=0;v<adir.length();v++){dir[v]=adir[v];
	}
	dir[v]='\0';
	file.open(dir,ios::in);
	if(file.is_open()){
		string line;
		while(getline(file,line)){char c[5000],cp=line[0];int v;string k,cc;
	p[i].set_flight(flight);
				switch(cp){
					case('r'):
						 v=0;
						for(int j=13;j<line.length();j++){
							c[v]=line[j];v++;
						}
						
						c[v]='\0';
						cc=c;
						p[i].set_res_n(stoi(cc));
						break;
					case('f'):
						 v=0;
						for(int j=12;j<line.length();j++){
							c[v]=line[j];v++;
						}
						c[v]='\0';
						k=c;
						p[i].set_fn(k);
						
						;break;
					case('l'):
						 v=0;
						for(int j=11;j<line.length();j++){
							c[v]=line[j];v++;
						}
						c[v]='\0';
						 k=c;
						p[i].set_ln(k);
						;break;
					case('s'):
						 v=0;
						for(int j=13;j<line.length();j++){
							c[v]=line[j];v++;
						}
						c[v]='\0';
						 cc=c;
						p[i].set_seat_n(stoi(cc));break;
					case('S'):
						if(line[7]=='v'){p[i].set_status(1);
						}
						else{p[i].set_status(0);
						};break;
					default:i++;break;
				}
				
				
			}
		
		
		file.close();}
	
	else{cout<<"flight dosent exist"<<endl;
	}l=i;
	return p;
	
}
plane * get_flights(int &l){
	plane *p=new plane[100];
	int i=0;
	fstream file;
	string adir="flights.txt";
	
	char dir[50000];int v;
	for(  v=0;v<adir.length();v++){dir[v]=adir[v];
	}
	dir[v]='\0';
	file.open(dir,ios::in);
	if(file.is_open()){
		string line;
		while(getline(file,line)){char c[5000],cp=line[0];int v;string k,cc;
				switch(cp){
					case('f'):
						 v=0;
						for(int j=14;j<line.length();j++){
							c[v]=line[j];v++;
						}
						
						c[v]='\0';
						cc=c;
						p[i].set_num_v(stoi(cc));
						break;
					case('t'):for(int j=5;j<line.length();j++){
						c[j-5]=line[j];
					}
					c[line.length()-5]='\0';
					cc=c;
					p[i].set_pays(cc);
					
					
					;break;
					case('n'):
						 v=0;
						for(int j=25;j<line.length();j++){
							c[v]=line[j];v++;
						}
						c[v]='\0';
						k=c;
						p[i].set_nb_p(stoi(k));
						
						;break;
					case('m'):
						 v=0;
						for(int j=21;j<line.length();j++){
							c[v]=line[j];v++;
						}
						c[v]='\0';
						 k=c;
						p[i].set_max_p(stoi(k));
						;break;
					default:i++;break;
				}
				
				
			}
		
		
		file.close();}
	
	else{cout<<"error while opening reservation file (check directory)"<<endl;
	}l=i;
	return p;
	
}
void change_flight(plane *t,int n){
	int i=0;
	fstream file;
	string adir="flights.txt";
	
	char dir[50000];int v;
	for(  v=0;v<adir.length();v++){dir[v]=adir[v];
	}
	dir[v]='\0';
	file.open(dir,ios::out);
	if(file.is_open()){
		for(i=0;i<n;i++){
	string f=to_string(t[i].get_num_v());
	string np=to_string(t[i].get_nb_p());
	string m=to_string(t[i].get_max_p());
		file<<"flight number "+f<<endl;
		file<<"to : "<<t[i].get_pays()<<endl;
		file<<"number of passengers is: "+np<<endl;
		file<<"maximum capacity is: "+m<<endl<<endl;
		}
		file.close();}
	
	else{cout<<"error while opening reservation file (check directory)"<<endl;
	}
	
}
		
