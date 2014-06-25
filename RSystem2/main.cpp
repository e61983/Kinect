#include "main.h"

using namespace std;

int main(void){
	BaseDevice	b1;
	Model		m1;
	Controler	*c1 = 0;
	View		*v1 = 0;

	v1 = new View(*c1);
	c1 = new Controler(m1,*v1);

	c1->setStatus(1);
	c1->setStatus(2);
	c1->setStatus(3);
	system("PAUSE");
	return 0;
}