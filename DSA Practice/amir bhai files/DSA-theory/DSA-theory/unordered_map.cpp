#include <iostream>
#include <unordered_map>
using namespace std;
  
int main()
{
    
    // Declaring umap to be of <int, string> type
    // key will be of int type and mapped value will
    // be of STRING
    unordered_map<int, string> umap;
  
    // inserting values by using [] operator
    umap[1944] = "Mohsin Abbas";
    umap[1234] = "abc";
    umap[1] = "number 1";
    umap[22] = "some student";

  
    // Traversing an unordered map
    for (auto x : umap)
      cout << x.first << " " << x.second << endl;
    
    
    //FIND:
    
    int key = 1944;
    
    if (umap.find(key) == umap.end())
        cout << key << " not found\n\n";
    // If key found then iterator to that key is returned
    else
        cout << "Found " << key << "\n\n";
    
    //DELETE:
     umap.erase(1944);
    
    return 0;
  
}
