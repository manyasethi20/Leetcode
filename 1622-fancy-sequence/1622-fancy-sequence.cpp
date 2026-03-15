class Fancy {
public:
    const long long MOD = 1e9+7;

    vector<long long> seq;
    long long mul = 1;
    long long add = 0;

    long long modInverse(long long x){
        long long res = 1;
        long long p = MOD-2;

        while(p){
            if(p&1) res = (res*x)%MOD;
            x = (x*x)%MOD;
            p >>= 1;
        }
        return res;
    }

    Fancy() {}

    void append(int val) {
        long long v = ((val - add) % MOD + MOD) % MOD;
        v = (v * modInverse(mul)) % MOD;
        seq.push_back(v);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if(idx >= seq.size()) return -1;

        long long val = seq[idx];
        return (val * mul % MOD + add) % MOD;
    }
};