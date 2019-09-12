#include <iostream>
#include <vector>
#include <algorithm>
using std::max;
using std::min;

using std::vector;

 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
 //只适合间隔是有序且递增的情况
/*class Solution {
public:
	vector<Interval> merge(vector<Interval> &intervals) {
		if (intervals.size() <= 1) return intervals;
		vector<Interval> res;
		int start_index = 0;
		int end_index = 0;
		for (int i = 0; i < intervals.size(); ++i)
		{
			if (intervals[start_index].end < intervals[i].start)
			{
				res.push_back(Interval(intervals[start_index].start, intervals[end_index].end));
				start_index = i;
			}
			end_index = i;
		}
		res.push_back(Interval(intervals[start_index].start, intervals[end_index].end));

		return res;
	}
};*/

 class Solution {
 public:
	 vector<Interval> merge(vector<Interval> &intervals) {
		 vector<Interval> res;
		 for (int i = 0; i < intervals.size(); ++i)
		 {
			 insert(res, intervals[i]);
		 }
		 return res;
	 }
	 void insert(vector<Interval>& res, Interval new_interval)
	 {
		 auto it = res.begin();
		 while (it != res.end())
		 {
			 if (it->start > new_interval.end)
			 {
				 res.insert(it, new_interval);
				 return;
			 }
			 else if (it->end < new_interval.start)
			 {
				 ++it;
				 continue;
			 }
			 else
			 {
				 new_interval.start = min(it->start, new_interval.start);
				 new_interval.end = max(it->end, new_interval.end);
				 it = res.erase(it);
			 }

		 }
		 res.push_back(new_interval);
	 }

 };

