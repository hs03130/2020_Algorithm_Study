#include<iostream>
using namespace std;
#include<map>

map <int, int> nerds;

bool isDominated(int x, int y) {
   map<int, int>::iterator it = nerds.lower_bound(x);

   if (it == nerds.end()) return false;

   return y < it->second;
}

void del(int x, int y) {
   map<int, int>::iterator it = nerds.lower_bound(x);

   if (it == nerds.begin()) return;   //1

   --it;
   while (true) {
      if (it->second > y) break;   //2

      if (it == nerds.begin()) {   //3
         nerds.erase(it);
         break;
      }
      else {   //4
         map<int, int>::iterator tmp = it;
         --tmp;
         nerds.erase(it);
         it = tmp;
      }
   }
}

int add(int x, int y) {
   if (isDominated(x, y)) return nerds.size();

   del(x, y);

   nerds.insert(make_pair(x, y));
   return nerds.size();
}

int main() {
   int C;
   cin >> C;

   for (int c = 0; c < C; c++) {
      int N;
      cin >> N;

      nerds.clear(); //맵의 원소들 모두 삭제

      int ret = 0;
      for (int i = 0; i < N; i++) {
         int x, y;
         cin >> x >> y;

         ret += add(x, y);
      }
      cout << ret << endl;
   }
   return 0;
}




/*
#include<iostream>
using namespace std;
#include<map>

map<int, int> nerds;

bool isDominated(int x, int y) {
   nerds[x] = y;
   map<int, int>::iterator it = nerds.find(x);
   if (it == nerds.end()) return false;

   it++;
   return y < it->second;
}

void del(int x, int y) {
   map<int, int>::iterator it = nerds.find(x);
   if (it == nerds.begin()) return;   //1

   --it;
   while (true) {
      if (it->second > y) break;   //2

      if (it == nerds.begin()) {   //3
         nerds.erase(it);
         break;
      }
      else {   //4
         map<int, int>::iterator tmp = it;
         --tmp;
         nerds.erase(it);
         it = tmp;
      }
   }
}
int add(int x, int y) {
   if (isDominated(x, y)) return nerds.size();

   del(x, y);

   nerds.insert(make_pair(x, y));
   return nerds.size();
}

int main() {
   int C;
   cin >> C;

   for (int c = 0; c < C; c++) {
      int N;
      cin >> N;

      nerds.clear(); //맵의 원소들 모두 삭제

      int ret = 0;
      for (int i = 0; i < N; i++) {
         int x, y;
         cin >> x >> y;

         ret += add(x, y);
      }
      cout << ret << endl;
   }
   return 0;
}
*/

/*
#include<iostream>
using namespace std;
#include<map>

map<int, int> nerds;

bool isDominated(int x, int y) {
    nerds[x] = y;
    map<int, int>::iterator it = nerds.find(x);
    if (it == nerds.end()) return false;

    it++;
    return y < it->second;
}

int main() {
    nerds[72] = 50;
    nerds[57] = 67;

}
*/