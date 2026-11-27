class ProductOfNumbers {
public:
    vector<int> pr;
    int n;
    ProductOfNumbers() {
        pr.clear();
        n = 0;
    }
    
    void add(int num) {   // O(1).
        if(num == 0) {
            pr.clear();
            n = -1;
        } 
        else if(pr.size() == 0) pr.push_back(num);
        else pr.push_back(pr[n-1]*num);
        n++;
    }
    
    int getProduct(int k) {   // O(1).
        if(k > n) return 0;
        else if(k == n) return pr[n-1];
        else return pr[n-1] / pr[n-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */