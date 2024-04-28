class Solution {
private:
    bool valid(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z')) {
            return true;
        }
        return false;
    }
    
    char tolowercase(char ch){
        if((ch >= 'A' && ch <= 'Z')) {
            return ch - 'A' + 'a';
        }
        return ch;
    }
    
    bool checkpalindrome(string z){
        int s = 0;
        int e = z.length() - 1;
        while(s <= e){
            if(z[s] != z[e]){
                return false;
            }
            else {
                s++;
                e--;
            }
        }
        return true;
    }
    
public:
    bool isPalindrome(string s) {
        // Remove non-alphanumeric characters and convert to lowercase
        string temp;
        for(int j = 0; j < s.length(); j++){
            if(valid(s[j])){
                temp.push_back(tolowercase(s[j]));
            }
        }
        return checkpalindrome(temp);
    }
};
