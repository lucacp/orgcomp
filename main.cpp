
#include "memcache.h"

using namespace std;
using namespace org;

int main(int nargs,char** args){
	int i=0,d,o;
	mCache *cache;
	mPri *pri;
	cache=new mCache();
	pri= new mPri();
	do{
		o=0;
		d=0;
		cout << "\ndigite opção: ";
		cin >> i;
		if(i==1)
		{
			cout<<"\ndigite o: ";
			cin >> o;
			cout<<"\ndigite d: ";
			cin >> d;
			cache->getBloco(o,d,pri);
			cache->update();
		}
		
	}while(i!=4);

	return 0;
}
