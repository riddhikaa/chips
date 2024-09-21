string kangaroo(int x1, int v1, int x2, int v2) {
if((x1>x2&&v1>v2)||(x1<x2&&v1<v2)||(x1==x2&&v1!=v2)) return "NO";

int sum1=x1+v1;
int sum2=x2+v2;
int counter=0;
while(counter<1e4){
    if(sum1==sum2) return "YES";
    sum1+=v1;
    sum2+=v2;
    counter++;
}
return "NO";

}

/*
was very challenging for me , srishneet  helped me T_T <3
it was easy, do revise it

*/
