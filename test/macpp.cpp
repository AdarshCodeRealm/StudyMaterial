#include<iostream>
#include<map>
using namespace std;
int main(){
 map<char,int> mp;
 mp['a']=3;
 cout<<mp['a']++;
 auto it = mp.begin();
return 0; 
}