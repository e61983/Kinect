#include "View.h"

using namespace std;

View::View( Controler& controler) : mControler(0){
	this->mControler = &controler;
}

View::~View( void ){
	this->mControler = 0;
}

void			
View::show(int status){
	cout << status << endl;
}