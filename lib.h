#include<iostream>
#include<fstream>
using namespace std;


class passenger{
	private:
	string f_name;
	string l_name;
	int res_n;
	int seat_n;
	int status;
	int flight;
	public:
		passenger();
		passenger(string f_name,string l_name);
		void make_reservation(int flight_n,int res,int seat);
		int get_reservation();
		int get_seat();
		int get_status();
		int get_flight();
		string get_ln();
		string get_fn();
		void print();
		void set_res_n(int n);
		void set_seat_n(int n);
		void set_status(int n);
		void set_flight(int n);
		void set_fn(string &n);
		void set_ln(string &n);
		
		
	
};
class plane{
	private:
		int num_vol;
		int max_pass;
		int nb_pass;
		string pays;
	public:
		plane();
		plane(int max_pass,int num_vol,int nb_pass,string p);
		int get_num_v();
		int get_max_p();
		int get_nb_p();
		string get_pays();
		void set_num_v(int n);
		void set_max_p(int n);
		void set_nb_p(int n);
		void set_pays(string p);
		void print();
		
};
