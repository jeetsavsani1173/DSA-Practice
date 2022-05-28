// problem link --> https://leetcode.com/problems/car-pooling/

class Solution {
public: // variation of meeting room-ii without space(Two Pointer)..
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        vector<pair<int,int>> a,b;
        for(int i=0;i<n;i++)
        {
            a.push_back({trips[i][1],trips[i][0]});
            b.push_back({trips[i][2],trips[i][0]});
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        int startIdx=0,endIdx=0;
        int curr_passenger=0,max_passenger=0;
        
        while(startIdx<n)
        {
            if(a[startIdx].first==b[endIdx].first)
            {
                curr_passenger-=b[endIdx].second;
                endIdx++;
            }
            else if(a[startIdx].first<b[endIdx].first)
            {
                curr_passenger+=a[startIdx].second;
                startIdx++;
            }
            else
            {
                curr_passenger-=b[endIdx].second;
                endIdx++;
            }
            max_passenger=max(max_passenger,curr_passenger);
        }
        cout<<max_passenger<<endl;
        if(max_passenger<=capacity)
            return true;
        else
            return false;
    }
};


// using map

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mp;
        for(int i=0;i<trips.size();i++)
        {
            int Passengers=trips[i][0];
            int start=trips[i][1];
            int end=trips[i][2];
            
            mp[start]+=Passengers;
            mp[end]+=(-1*Passengers);
        }
        int cnt=0;
        for(auto it:mp)
        {
            cnt+=it.second;
            if(cnt>capacity)
                return false;
        }
        return true;
    }
};