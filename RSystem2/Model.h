#ifndef _H_MODEL_
#define _H_MODEL_
class Model{

private:
	int		status;

public:
			Model( void );
			~Model( void );
	void	setStatus(int);
	int		getStatus(void);
};

#endif /* _H_MODEL_ */
