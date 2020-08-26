#include <iostream>
#include <map>
using namespace std;

int main(){
    //multimap can store same keys and their values
    multimap<int, string> lookup;
    lookup.insert(make_pair(20, "ABC"));
    lookup.insert(make_pair(45, "PWT"));
    lookup.insert(make_pair(2172, "JHKD"));
    lookup.insert(make_pair(20, "adg"));
    lookup.insert(make_pair(75, "afgd"));
    lookup.insert(make_pair(2172, "asdasfdf"));


    for(multimap<int, string>::iterator i = lookup.find(45); i != lookup.end(); i++){
        cout << i->first<<" : "<<i->second<<endl;

    }

    cout<<endl;
    //equal_range returns a pair of iterator from start of range and end of range
    //pass the key you want to find
    pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(45);

    //auto gives proper type to returned value
    auto itss = lookup.equal_range(20);

    //iterate from one iterator returned in its to second
    for(multimap<int, string>::iterator i = its.first; i != its.second; i++){
        cout << i->first<<" : "<<i->second<<endl;
    }
    return 0;
}