#include<iostream>
#include<set>
using namespace std;
int main(){
   set<int> s ={2,4,1,2,3};
   for(auto i:s){
    cout<<i<<" ";
   }
   s.insert(38);
   s.erase(2);
   if(s.find(38)!=s.end()){
    cout<<"present";
   }
   else{
    cout<<"not present";
   }
   cout<<endl<<"print:"<<s.size();
//    for(auto i:s){
//     cout<<i<<" ";
//    }
 
return 0; 
}