#include <bits/stdc++.h>
using namespace std;
int Next(vector<int>page, vector<int>& fr, int n, int idx) {
   int res = -1, mx = idx;
   for (int i = 0; i < fr.size(); i++) {
      int j;
      for (j = idx; j < n; j++) {
         if (fr[i] == page[j]) {
            if (j > mx) {
               mx = j;
               res = i;
            }
            break;
         }
      }
      if (j == n)
         return i;
   }
   return (res == -1) ? 0 : res;
}
void opr(vector<int>page, int n, int fn) {
   vector<int> fr;
   int hit = 0;
   for (int i = 0; i < n; i++) {
      if (find(fr.begin(),fr.end(),page[i])!= fr.end()) {
         hit++;
         continue;
      }
      if (fr.size() < fn)fr.push_back(page[i]);
      else {
         int j = Next(page, fr, n, i+1);
         fr[j] = page[i];
      }
   }
   cout << "Hits = " << hit << endl;
   cout << "Misses = " <<n - hit<< endl;
}
int main() {
   int n;
   cout<<"Enter the number of pages :";
   cin>>n;
   vector<int>page(n);
   cout<<"Enter sequence :";
   for(auto &x:page)cin>>x;
   cout<<"Enter frame number:";
   int fn; cin>>fn;
   opr(page,n,fn);
   return 0;
}
