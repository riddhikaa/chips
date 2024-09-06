vector<int> gradingStudents(vector<int> grades) {
 vector<int>ans(grades.size());
for(int i=0;i<grades.size();i++)ans[i]=0;
 for(int i=0;i<grades.size();i++){
     ans[i]=grades[i];
     if(ans[i]>=38&&(ans[i]%5==3||ans[i]%5==4)){
         // 38 and above since we can round it of to 40
         // and 58,59,54,53
         int div=ans[i]%5; //3 or 5
         ans[i]+=div;//58+3=61
         if(ans[i]%5!=0){
             int div2=ans[i]%5; // 61%5=1
             ans[i]=ans[i]-div2;//61-1
         }
     }
 }
 return ans;
}
