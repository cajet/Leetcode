/*把所有的时间段都画在一张map上，找寻最多重叠时间段，
把时间段起始时间和结束时间映射为+1/-1，就把实际问题转换成了一个简单的数学问题*/

int minMeetingRooms(vector<Interval>& intervals) {
    map<int,int> mm;
    for(auto&a:intervals){
        mm[a.start]++; //开始时刻映射成+1
        mm[a.end]--;  //结束时刻映射为-1
    }
    int res=0,cur=0;
    for(auto&k:mm){
        cur+=k.second;
        res=max(res,cur);
    }
    return res;
}