// Cserich David

#include <iostream>
#include <vector>
#include <iterator>
#include <map>

using namespace std;

class TimeStamp {
  int hour;
  int min;
public:
  TimeStamp(int h = 0, int m = 0) : hour(h), min(m) {}

  bool operator< (const TimeStamp &a) const {
    if (this->hour < a.hour) {
      return true;
    } else if ((this->hour == a.hour) && (this->min < a.min)) {
      return true;
    }
    return false;
  }
    
  friend ostream& operator<< (ostream& os, const TimeStamp& ts) {
    os << ts.hour << ":" << ts.min;
    return os;
  }
};

ostream &operator<< (ostream& os, const map<TimeStamp, double> m);

int main(int argc, const char * argv[]) {
  int hour[]    = {6,8,14,8,18,8,21};
  int min[]     = {11,22,33,44,55,31,41};
  double dat[]  = {36.5,37.3,38.5,37.1,37.1,37.5,37.4};
  
  vector<int>     hour_v(begin(hour),end(hour));
  vector<int>     min_v (begin(min), end(min));
  vector<double>  dat_v (begin(dat), end(dat));

  
  map<TimeStamp,double> log;
  
  auto i = hour_v.begin();
  auto j = min_v.begin();
  auto k = dat_v.begin();
  
  for (; i != hour_v.end(); ++i, ++j, ++k) {
    log.insert(pair<TimeStamp, double>(TimeStamp(*i,*j),*k));
  }
  
  cout << log;
  
  return 0;
}

ostream &operator<< (ostream& os, const map<TimeStamp,double> m) {
  for (auto i = m.begin(); i != m.end(); ++i) {
    os << (*i).first << "\t" << (*i).second << endl;
  }
  return os;
}
