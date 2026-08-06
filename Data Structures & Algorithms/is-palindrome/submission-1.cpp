class Solution {
public:
    bool isPalindrome(const string& s) {
        int l = 0, r = s.size() - 1;

        while(l < r) {
            // skips if not alnum
            while(l<r && !isalnum(static_cast<unsigned char>(s[l]))) ++l;
            while(l<r && !isalnum(static_cast<unsigned char>(s[r]))) --r;

            if(tolower(static_cast<signed char>(s[l])) != tolower(static_cast<unsigned char>(s[r]))) return false;

            ++l, --r;
        }
        return true;
    }
};
