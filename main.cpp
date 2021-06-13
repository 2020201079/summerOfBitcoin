#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string fileName = "mempool.csv";
set<string> included_tx_id; //contains the tx_ids which are included
class Transaction
{
    public:
    string tx_id;
    int fee;
    int weight;
    vector<string> parents;
};

pair<string,Transaction*> createTransaction(vector<string>& row){
    auto ans = new Transaction();
    ans->tx_id = row[0];
    ans->fee = stoi(row[1]);
    ans->weight = stoi(row[2]);
    vector<string> p;
    for(int i=3;i<row.size();i++){
        p.push_back(row[i]);
    }
    ans->parents = p;
    return {row[0],ans};
}

void readCSV(string fileName,unordered_map<string,Transaction*>& umap){
    ifstream fin(fileName);
    vector<string> row;
    string temp,line,word;
    getline(fin,line); //skipping the header of csv
    while(getline(fin,line)){
        row.clear();
        stringstream s(line);
        while(getline(s,word,',')){
            row.push_back(word); // row contains all the transaction details
        }
        pair<string,Transaction*> p = createTransaction(row);
        umap[p.first] = p.second;
    }
    fin.close();
    cout<<"num of transactions read : "<<umap.size()<<endl;
}

int main(){

    unordered_map<string,Transaction*> umap; //map tx_id to its pointer
    readCSV(fileName,umap);
    
}