/*
Time conversion 
*/
string timeConversion(string s) {
    for(int i=0;i<int(s.length());i++){
        if(s[i]=='A'){
            // AM conversion
            if(s[0]=='1'&&s[1]=='2'){
                // for 12:00:00 am 
                s[0]='0';
                s[1]='0';
            }
       
        }
        if(s[i]=='P'){
            //PM conversion
            if(s[0]=='1'&&s[1]=='2') return s.substr(0,8); // fpr 12:00:00pm
            else {
                s[0]+=1; 
                s[1]+=2;
               
               //--> 01:00:00PM 
                // s[0]=s[0]+1==>'0'+1==> 48+1=49 ==>49 is ascii for '1'
                // s[1]=s[1]+2==> '1'+2==> 49+2=51==> 51 is ascii for '3'
            }
        }
    }
      return s.substr(0,8); 
}
