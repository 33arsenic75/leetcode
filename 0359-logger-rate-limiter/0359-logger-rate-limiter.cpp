class Logger {
public:
    Logger() {
        
    }
    
    map<int,int>mp;

    int hash(string s){
        long long ret_val = 0;
        for(char c: s){
            ret_val = 2003 * ret_val + (c-'0');
            ret_val %= (long long)1e9+7;
        }
        return (int)ret_val;
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(mp.find(hash(message)) == mp.end()){
            mp[hash(message)] = timestamp;
            return true;
        }

        if(timestamp - mp[hash(message)] < 10)return false;

        mp[hash(message)] = timestamp;
        
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */