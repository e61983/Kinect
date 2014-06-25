#ifndef _H_VIEW_
#define _H_VIEW_
class Controler;
#include <iostream>
#include "Controler.h"
class View{

private:
	Controler	*mControler;
public:
				View( Controler& );
				~View( void );
	void		show(int);
};

#endif /* _H_VIEW_ */
class Controler;