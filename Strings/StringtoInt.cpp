class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long double num = 0;

        int i=0;
        while(s[i]==' ') i++;

        bool positive = (s[i]=='+');
        bool negative = (s[i] == '-');

        if(positive || negative) i++;

        while(i<n && s[i]>='0' && s[i]<='9'){
            num = num*10 + (s[i]-'0');
            i++;
        }

        if(negative){
            num = -num;
        }

        if(num> INT_MAX){
            return INT_MAX;
        }
        if(num<INT_MIN){
            return INT_MIN;
        }
        return num;
    }
};