#include <iostream>
#include <list>

using namespace std;

list<int> l;

void fun(int size, int b)
{
	if(b == size)
	{
		#if 1
		for(auto i : l)
		{
			cout << i << " ";
		}
		
		cout << endl;
		#endif
		return;
	}

		
	for(int i = b; i < b+3; ++i)
	{	
		l.push_back(i);
		fun(size, (i/3)*3 +3);
		l.pop_back();
	}
	
}




int main()
{
	
	fun(9, 0);
		
	return 0;
}