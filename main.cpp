#include "memcache.h"

void teste1(){
	acessaCache(0,true);
	acessaCache(0,true);
	acessaCache(2,false);
	acessaCache(2,false);
};

void initmemor(int a,int bs,int cs){
	c=new mCache(a,bs,cs);
	p=new mPri();
}
int main(int nargs,char** args){
	initmemor(1,32,128);
	teste1();
	c->update();
	teste1();
	return 0;
}
