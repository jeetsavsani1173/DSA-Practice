// problem link --> https://leetcode.com/problems/iterator-for-combination/

class CombinationIterator {
    vector<string> combinations;
    int pointer;
public:
    void generateCombi(int idx,string &characters,string output,int len)
    {
        if(idx==characters.size())
        {
            if(output.size()==len)
                combinations.push_back(output);
            return;
        }
        if(output.size()>len) return;
        // take
        generateCombi(idx+1,characters,output+characters[idx],len);
        
        // non-take
        generateCombi(idx+1,characters,output,len);
    }
    CombinationIterator(string characters, int combinationLength) {
        pointer=0;
        string output;
        generateCombi(0,characters,output,combinationLength);
        // for(auto it:combinations) cout<<it<<endl;
    }
    
    string next() {
        string output=combinations[pointer];
        pointer++;
        return output;
    }
    
    bool hasNext() {
        return (pointer<combinations.size());
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */