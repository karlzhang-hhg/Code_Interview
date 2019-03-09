/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

// int OPLen(const string& fname){
//     fstream file(fname, ios_base::in);
//     string kw;
//     int cnt=0;
//     int ans=0;
//     stack<int> num_st; // Store numbers.
//     stack<int> op_i_st; // Store index for position of loop number.
//     num_st.push(1);
//     op_i_st.push(0);
//     do{
//         file>>kw;
//         if(kw=="BEGIN") cnt++;
//         else if(kw=="END"){
//             cnt--;
//             int t_i=0;
//             while(num_st.size()-1!=op_i_st.top()){
//                 t_i += num_st.top(); num_st.pop();
//             }
//             op_i_st.pop();
//             t_i *= num_st.top();num_st.pop();
//             num_st.push(t_i);
//             if(cnt==0)
//                 break;
//         }
//         else if(kw=="LOOP"){
//             cnt++;
//             string num_s;
//             file>>num_s;
//             op_i_st.push(num_st.size());
//             num_st.push(stoi(num_s));
//         }else if(kw=="PRINT"){
//             string t_s;
//             file>>t_s;
//             num_st.push(t_s.length());
//         }
//     }while(true);
//     return num_st.top();
// }


int OPLen(const string& fname){
   fstream file(fname, ios_base::in);
   string kw;
   int ans=0;
   stack<int> num_st;
   num_st.push(1);
   int multiplier = 1;
   do{
       file>>kw;
       if (kw=="BEGIN") {/* do nothing */}
       else if(kw=="END"){
           multiplier /= num_st.top();
           num_st.pop();
       }
       else if(kw=="LOOP"){
           int num_s;
           file>>num_s;
           num_st.push(num_s);
           multiplier *= num_s;
       }else if(kw=="PRINT"){
           string t_s;
           file>>t_s;
           ans += multiplier * t_s.length();
       }
   }while(!num_st.empty());
   return ans;
}
