//
//  main.cpp
//  N-Repeated Elements
//
//  Created by Aj Gill on 4/9/19.
//  Copyright © 2019 Aj Gill. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int repeatedNTimes(vector<int>& A) {
    int mostFreq = 0;
    int largestCount = 0;
    map<int,int> hMap;
    for(int i=0;i< A.size(); i++){
        //check if it exists, if it does, increment value
        map<int,int>::iterator it;
        it = hMap.find(A[i]);
        if(it != hMap.end()){
            it->second = it->second + 1;
        }
        //if it doesnt, then insert with the value set to 1
        else{
            hMap.insert(make_pair(A[i], 1));
        }
    }
    for(map<int,int>::iterator iter = hMap.begin(); iter != hMap.end(); ++iter){
        //cout << "Number:" << iter->first << " Frequency:" << iter->second << "\n";
        if(iter->second > largestCount){
            largestCount = iter->second;
            mostFreq = iter->first;
        }
    }
    return mostFreq;
}

int main() {
    vector<int> candy = {8, 3, 2, 3};
    int answer = repeatedNTimes(candy);
    cout << "answer is " << answer << "\n";
}


