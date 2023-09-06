#include <stack> 
#include <cstring> 

using namespace std; 

 

class Stack { 

private: 

    stack <char> stack; 

public: 

    bool compr (Expression); 

    friend void check(Stack,Expression); 

}; 

 
 

bool Stack::compr (Expression eks){ 

    bool flag=true; 

    for (int i=0; i<=strlen(eks.exp); i++){ 

        if (stack.empty()){ 

            if (eks.start(eks.exp[i])) 

                stack.push(eks.exp[i]); 

            else if (eks.end(eks.exp[i])){ 

                flag=false; 

                break; 

            } 

        } 
 

        else{ 
            if (eks.start(eks.exp[i]))  

                stack.push(eks.exp[i]);
             

            else if (eks.end(eks.exp[i])&&!(eks.zakr(stack.top(),eks.exp[i]))){ 

                flag=false; 
                break; 

            } 

            else if (eks.end(eks.exp[i])&&eks.zakr(stack.top(),eks.exp[i])) 

                stack.pop();  

            else if (!(eks.end((eks.exp[i])))&&i==(strlen(eks.exp)-1))

                flag=false; 
                
        } 

    } 

  return flag; 

}