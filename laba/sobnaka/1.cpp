#include <iostream> 
#include "Expression.h" 
#include "Stack.h" 


using namespace std; 

 
void check(Stack stack, Expression eks) { 

  if (stack.compr(eks)) 

    cout<<"brackets are closed\n"; 

  else  

    cout<<"there is some unopened or unclosed brackets\n"; 


} 

int main(){ 

  Expression eks; 

  Stack stack;  

  check(stack,eks); 

} 
