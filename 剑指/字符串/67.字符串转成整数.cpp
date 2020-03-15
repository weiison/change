class Solution {
public:
    int strToInt(string str) {
        while(str[0]==' ')
            str.erase(0,1);
        int flag=1;
        int cur=0;
        if(str[0]=='-') 
        {
            flag=-1;
            cur=1;
        }
        else if(str[0]=='+') 
        {
            flag=1;
            cur=1;
        }
        else if(str[0]-'0'<=9&&str[0]-'0'>=0) cur=0;
        else return 0;
        long long num=0;
        for(;cur<str.size();++cur)
        {
            if(str[cur]==' ') break;
            if(str[cur]-'0'<=9&&str[cur]-'0'>=0)
            {
                num=num*10+flag*(str[cur]-'0');
                if(num>INT_MAX) return INT_MAX;
                if(num<INT_MIN) return INT_MIN;
            }
            else
                break;
        }
        return num;
    }
};
