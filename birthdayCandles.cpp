/*
You are in charge of the cake for a child's birthday. 
You have decided the cake will have one candle for each year of their total age. 
They will only be able to blow out the tallest of the candles.
Count how many candles are tallest.

Example
candles=[4,4,1,3]
The maximum height candles are 4  units high.
There are  2 of them, so return 2 .

Function Description
Complete the function birthdayCakeCandles in the editor below.
birthdayCakeCandles has the following parameter(s):
int candles[n]: the candle heights

Returns
int: the number of candles that are tallest

Input Format
The first line contains a single integer,n , the size of candles[].
The second line contains  space-separated integers,
where each integer i describes the height of candles[i].

Constraints
1<=n<=10^5
1<=candles[i]<=10^7

Sample Input 0
4
3 2 1 3

Sample Output 0
2

Explanation 0
Candle heights are 3 2 1 3. 
The tallest candles are  3 units,
and there are 2 of them.
*/

int birthdayCakeCandles(vector<int> candles) {

int counter=0,max=0;
//3 2 1 3
for(int i=0;i<candles.size();i++){
   
    if(max<candles[i]){ 
        max=candles[i];
        counter=1; // reset counter when new value of max is found :o
        } else if(max==candles[i])counter++; 
        // Increment the counter if the current candle matches the max height
}
return counter;

}

