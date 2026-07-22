class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> roman = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };

        int answer = 0;

        for( int i = 0; i< s.length(); i++){

            int current = roman[s[i]];

            if(i < s.length() -1){
                int next = roman[s[i+1]];

                if(current < next)
                answer -= current;

                else
                answer += current;
            }
            else{
                answer += current;
            }
        }
        return answer ;
        
    }
};