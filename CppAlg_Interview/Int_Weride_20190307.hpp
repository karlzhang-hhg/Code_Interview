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

// Weride.ai 挂经：
// 我在想把这个文件夹转到github去，这样感觉好像方便看，然后可以用comment直接评论。
//
// There is a new programming language, we want to find the length of the output. There are several key words.
//
// Every programming is surrounded by BEGIN and END;
// There is a LOOP … END, and after LOOP, there is a positive number as the number of iteration;
// There is a command PRINT followed by a string.
//
// We want to calculate the length of the output.
//
// Example 1:
//
// BEGIN
//   LOOP 3
//     LOOP 3
//       PRINT Moe
//     END
//   END
// END
//
// // Output length is 27
//
// Example 2:
//
// BEGIN
//   LOOP 3
//     LOOP 3
//       PRINT Moe
//       LOOP 4
//         PRINT 3456
//         PRINT jjjj
//       END
//       PRINT adc
//     END
//   END
// END
//
// // Output length is 3*3*(3+4*(4+4)+3)=342
//
//
//
// BEGIN
//
// END
//
// // Output 0
//
// BEGIN
//   LOOP 3
//     LOOP 3
//       PRINT Moe
//     END
//   END
// END
//
// // Output 27
//
// BEGIN
//   LOOP 3
//     LOOP 3
//       PRINT Moe
//       LOOP 4
//         PRINT 3456
//         PRINT jjjj
//       END
//       PRINT adc
//     END
//   END
// END
//
// //Output 3*3*(3+4*(4+4)+3)=342
//
// BEGIN
//   LOOP 3
//     LOOP 3
//       PRINT Moe
//       LOOP 2
//         PRINT 3456
//         PRINT jjjj
//       END
//       PRINT adc
//     END
//   END
//   PRINT 12
// END
//
// //Output 3*3*(3+2*(4+4)+3)+2=200
//
// Verison 0: Passed the above tests. I didn’t do well, because I was trying to transfer this problem into a calculator, but it took too much time. This is actually a simpler problem than a calculator. I figure out the a more concise solution afterwards, but it also has lots of redundant conversion between integer and string.
//
// int OPLen(const string& fname){
//     fstream file(fname, ios_base::in);
//     string kw;
//     int cnt=0;
//     int ans=0;
//     stack<string> num_st;
//     num_st.push("1");
//     num_st.push("*");
//     do{
//         file>>kw;
//         if(kw=="BEGIN") cnt++;
//         else if(kw=="END"){
//             cnt--;
//             int t_i=0;
//             while(num_st.top()!="*"){
//                 t_i += stoi(num_st.top()); num_st.pop();
//             }
//             num_st.pop();
//             t_i *= stoi(num_st.top());num_st.pop();
//             num_st.push(to_string(t_i));
//             if(cnt==0)
//                 break;
//         }
//         else if(kw=="LOOP"){
//             cnt++;
//             string num_s;
//             file>>num_s;
//             num_st.push(num_s);
//             num_st.push("*");
//         }else if(kw=="PRINT"){
//             string t_s;
//             file>>t_s;
//             num_st.push(to_string(t_s.length()));
//         }
//     }while(true);
//     return stoi(num_st.top());
// }
//
//
// Version 1: I don’t use so much conversion. Instead, I use another stack to remember the idx of multiplier.
//
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

// lcc version:
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


// Test main function.
// int main(int argc, char** argv) {
//     const string fname0="int_weride_test0.txt";
//     cout<<OPLen(fname0)<<endl;
//
//     const string fname1="int_weride_test1.txt";
//     cout<<OPLen(fname1)<<endl;
//
//     const string fname2="int_weride_test2.txt";
//     cout<<OPLen(fname2)<<endl;
//
//     const string fname3="int_weride_test3.txt";
//     cout<<OPLen(fname3)<<endl;
//
//     return 0;
// }
