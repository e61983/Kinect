#ifndef _H_CONTROLER_
#define _H_CONTROLER_
class Model;
class View;
#include "Model.h"
#include "View.h"

class Controler{
private:
	View	*mView;
	Model	*mModel;
public:
			Controler( Model&, View& );
			~Controler( void );
	void	setStatus(int);

};

#endif /* _H_CONTROLER_ */