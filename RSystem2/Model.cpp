#include "Model.h"

Model::Model(void ):status(0){
}

Model::~Model( void ){
}

void
Model::setStatus(int status){
	this->status = status;
}

int		
Model::getStatus(void){
	return this->status;
}