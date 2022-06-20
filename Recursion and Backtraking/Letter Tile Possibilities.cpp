// problem link --> https://leetcode.com/problems/letter-tile-possibilities/

class Solution {
public:
    int count=0;
    void helper(int box,string &tiles,map<char,int> &freq)
    {
        if(box==tiles.size()) return;
        for(auto &it:freq)
        {
            if(it.second>0)
            {
                count++;
                tiles[box]=it.first;
                it.second--;
                helper(box+1,tiles,freq);
                it.second++;
                tiles[box]='0';
            }
        }
    }
    int numTilePossibilities(string tiles) {
        map<char,int> freq;
        for(int i=0;i<tiles.size();i++){
            freq[tiles[i]]++;
            tiles[i]='0';
        }
        helper(0,tiles,freq);
        return count;
    }
};