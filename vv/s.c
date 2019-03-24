#include<stdio.h>
#define max 10
struct stack {
int arr[max];
int top;

};
// define object from stack
 typedef struct stack st ;

 // create or initialization stack
 void init(st*s){
     s->top=-1;

 }
 //////////////////////
void push(int element,st*s){
    s->top++;
s->arr[s->top]=element;

}
////////////////////////
int pop(st*s){
s->top--;
return s->arr[s->top];

}
//////////////////
int isempty(st *s ){
if(s->top==-1) return 1;
else return 0;

}
//////////////////////
int isfull(st * s){

if(s->top==max-1) return 1;
else return 0;



}
int peek(st*s){
return s->arr[s->top];


}
//////////////////////
void print(st*s){
    int i;
for(i=0;i<(s->top);i++){
        printf("%d",s->arr[s->top]);
}
}
int main (void){

st *s;

init(s);

   push(5,s);
print(s);








return 0;
}
