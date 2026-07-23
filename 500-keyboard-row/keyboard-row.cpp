class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char , int> mp;

        for(char c : string("qwertyuiop"))
        mp[c]= 1;

        for(char c : string("asdfghjkl"))
        mp[c] = 2;

        for(char c : string("zxcvbnm"))
        mp[c] = 3;

        vector<string> ans;

        for(string word : words){
            int row = mp[tolower(word[0])];
            bool sameRow = true;

            for (char c : word){

                if(mp[tolower(c)] != row){
                    sameRow = false;
                    break;
                }
            }
            if(sameRow)
            ans.push_back(word);
        }   
        return ans;     
    }
};