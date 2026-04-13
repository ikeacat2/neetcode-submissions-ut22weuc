class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string str = "";
        for(int i = 0; i < 32; i++) {
            int c = (n & 1);
            str+=std::to_string(c);
            n = n/2;
        }
        uint32_t value = static_cast<uint32_t>(std::stoul(str, nullptr, 2));
        return value;
    }
};
