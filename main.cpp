// main.cpp
#include<string>
#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

// macro
#define ONLINE \
	make_tuple("q","quit"       ,&quit),\
	make_tuple("+","operation 1",&op1) ,\
	make_tuple("-","operation 2",&op2) ,
#define MENU_PRINT_FORMAT "%5s - %-20s\n"

// labor
void op1(){
	cout<<"Carrying out op #1 ..."<<endl;
	// do the heck
}
void op2(){
	cout<<"Carrying out op #2 ..."<<endl;
	// do the heck
}
void quit(){
	cout<<"Bye."<<endl;
	// save something to a (binary) file
}

// showcase
typedef tuple<string,string,void(*)()> ugly_t;
// another solution
// typedef string shorthand_t;
// typedef string fullname_t;
// typedef map<shorthand_t,pair<fullname_t,void(*)()>> ugly_t;
vector<ugly_t> vec({ONLINE});
void display_menu(){
	for(auto& ref:vec){
		printf(MENU_PRINT_FORMAT,get<0>(ref).c_str(),get<1>(ref).c_str());
	}
}
// void display_menu(){
// 	for(auto& ref:vec){
// 		cout<<get<0>(ref)<<" - "<<get<1>(ref)<<endl;
// 	}
// }
bool executeOperation(const std::string &t_operation){
	// return false if the operation loop should stop
	bool ret=true;
	auto it=find_if(
		vec.begin(),
		vec.end(),
		[=](const ugly_t& tu){return get<0>(tu)==t_operation;}
	);
	if(it==vec.end()){
		cout<<"Invalid choice"<<endl;
		return true;
	}
	if(get<0>(*it)=="q"){
		ret=false;
	}
	// (this->*(get<2>(*it)))();
	(*(get<2>(*it)))();
	return ret;
}
int main(){
	display_menu();
	while(true){
		string op;
		getline(cin,op);
		// how to deal with EOF more smartly?
		if(!executeOperation(op)||!cin)
			break;
	};
	return 0;
}