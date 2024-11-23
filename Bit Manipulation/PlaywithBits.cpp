
// kth bit set?
bool checkKthBit(int n, int k) {
    int f = n & (1<<k);
    
    if(f==0) return false;
    else return true;
}

