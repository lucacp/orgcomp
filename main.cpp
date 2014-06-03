
#include "memcache.h"

using namespace std;
using namespace org;
void teste1(){
	acessaMemoria(0,true);
	acessaMemoria(0,true);
	acessaMemoria(2,false);
	acessaMemoria(2,false);

};

int main(int nargs,char** args){
	int i=0,d,o;
	mCache *c;
	mPri *p;
	cache=new mCache();
	pri= new mPri();
	o=0;
	d=0;
	cout << "\ndigite opção: ";
	cin >> i;
	if(i==1)
	{
		teste1();
		cache->update();
	}
	return 0;
}
