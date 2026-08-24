class Solution { 
public: 
    int totalWaviness(int num1, int num2) { 
        
        if(num1 < 100 && num2 >= 120) { 
            num1 = 101; 
        } 
        
        if(num1 < 100 && num2 < 100) { 
            return 0; 
        } 
        
        int sum = 0; 
        
        for(int i = num1; i <= num2; i++) { 
            int t = i; 
            
            int temp1 = t % 10; 
            t = t / 10; 
            
            while(t > 9) { 
                int temp2 = t % 10; 
                t = t / 10; 
                
                if(temp2 > temp1 && temp2 > t % 10) { 
                    sum++; 
                } 
                
                if(temp2 < temp1 && temp2 < t % 10) { 
                    sum++; 
                } 
                
                temp1 = temp2; 
            } 
        } 
        
        return sum; 
    } 
};