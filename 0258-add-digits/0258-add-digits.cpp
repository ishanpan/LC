class Solution {
public:
    int addDigits(int num) {
        
        
        while(num>9){
            int numnew = 0;
            
            while(num){
                numnew += num%10;
                num = num/10;
            }
            num = numnew;
        }
        return num;
    }
};