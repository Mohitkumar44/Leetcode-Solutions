// T.C. O(n) where n is number of operations.
// All operations are performed in constant time.
class BusBooking {
public:
    vector<vector<int>> book;
    int time;
    int size;
    int mtime;
    BusBooking(int n) {
        vector<vector<int>> temp(4, vector<int> (n, 0));
        book = temp;
        time = 0;
        size = n;
        mtime = 0;
    }
    
    void toggle(string seat) {
        int ch = seat[0]-'A';
        int num = stoi(seat.substr(1))-1;
        if(num+1 > size) return;
        if(book[ch][num] != 0) {
            time -= book[ch][num];
            book[ch][num] = 0;
            mtime--;
        } 
        else {
            if(ch == 1 or ch == 2) {
                time += 1;
                book[ch][num] = 1;
            } 
            else if(ch == 0) {
                if(book[1][num] != 0) {
                    time+=3;
                    book[ch][num] = 3;
                }
                else {
                    time+=1;
                    book[ch][num] = 1;
                }
            }
            else {
                if(book[2][num] != 0) {
                    time+=3;
                    book[ch][num] = 3;
                }
                else {
                    time+=1;
                    book[ch][num] = 1;
                }                
            }
            mtime++;
        } 
    }
    
    int getTotalTime() {
        return time;
    }
    
    int getMinTime() {
        return mtime;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */