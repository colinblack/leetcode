#include <iostream>
#include <list>
//如果使用stl中的list要怎么写？
using std::list;

void mergeList(list<int>& src1, list<int>& src2, list<int>& dst)
{
	auto p_src1 = src1.begin();
	auto p_src2 = src2.begin();
	auto p_dst = dst.begin();

	while (p_src1 != src1.end() && p_src2 != src2.end())
	{
		if (*p_src1 < *p_src2)
		{

		}
		else
		{
		
		
		}

	
	}




}


int main()
{


	return 0;
}