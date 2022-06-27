// problem link --> https://leetcode.com/problems/maximum-frequency-stack/

class FreqStack {
public:
    map<int,int> freq;
    map<int,vector<int>> freqNodes;
    int maxFreq=0;
    
    void push(int val) {
        freq[val]++;
        int currFreq=freq[val];
        
        freqNodes[currFreq].push_back(val);
        maxFreq=max(maxFreq,currFreq);
    }
    
    int pop() {
        vector<int> nodes=freqNodes[maxFreq];
        
        int val=nodes[nodes.size()-1];
        nodes.pop_back();
        freq[val]--;
        
        if(nodes.size()==0){
            freqNodes.erase(maxFreq);
            maxFreq--;
        }else{
            freqNodes[maxFreq]=nodes;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */