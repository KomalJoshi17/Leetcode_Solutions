class Solution {
public:
    string addBinary(string a, string b) {
        int s1=a.size()-1;
        int s2=b.size()-1;

        string ans="";
        char carry='0';
        while(s1 >= 0 || s2 >= 0){

        char bit1 = (s1 >= 0) ? a[s1] : '0';
        char bit2 = (s2 >= 0) ? b[s2] : '0';

        if(carry=='0' && bit1=='1' && bit2=='1'){
            ans+='0';
            carry='1';
        }
        else if(carry=='1' && bit1=='1' && bit2=='0'){
            ans+='0';
            carry='1';
        }
        else if(carry=='1' && bit1=='0' && bit2=='1'){
            ans+='0';
            carry='1';
        }
        else if(carry=='1' && bit1=='1' && bit2=='1'){
            ans+='1';
            carry='1';
        }
        else if(carry=='0' && bit1=='0' && bit2=='1'){
            ans+='1';
            carry='0';
        }
        else if(carry=='0' && bit1=='1' && bit2=='0'){
            ans+='1';
            carry='0';
        }
        else if(carry=='0' && bit1=='0' && bit2=='0'){
            ans+='0';
            carry='0';
        }
        else if(carry=='1' && bit1=='0' && bit2=='0'){
            ans+='1';
            carry='0';
        }
        s1--;
        s2--;
    }

        if(carry=='1') ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};