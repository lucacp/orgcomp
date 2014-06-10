#include "memcache.h"
void acessaCache(unsigned long endereco,bool inst){
		c->count++;
		int i=0;
		i=endereco>>c->var;
		if(c->blo[i].dado==0)
			cout << "Hit "<<endl;
		else
			acessaMemoria(endereco,inst);
		c->update(endereco);
		
			
	};
	void acessaMemoria(unsigned long endereco,bool inst){
		p->count++;
		int i=0;
		i=endereco>>c->var;
		c->blo[(i%c->var)]=p->bloc[i];
		c->lru[(i%c->var)]=0;
		cout << "Miss "<<endl;
	};
