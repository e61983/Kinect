#include "Controler.h"

Controler::Controler( Model &model, View &view ):mView(0),mModel(0){
	this->mModel = &model;
	this->mView = &view;
}

Controler::~Controler( void ){
	this->mModel = 0;
	this->mView = 0;
}

void	
Controler::setStatus(int status){
	this->mModel->setStatus(status);
	this->mView->show(this->mModel->getStatus());
}