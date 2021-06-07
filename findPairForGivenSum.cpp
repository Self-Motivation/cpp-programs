//we need to find the pair of elements in a given array such that their sum is given
#include<iostream>
#include<unordered_map>

using namespace std;
void findPair(int a[], int sum, int n)
{
    
  unordered_map <int, int> map;
  bool found = false;
  for (int i = 0; i < n; i++)
  {
     map[a[i]] = i;
    if(map.find(sum-a[i])!=map.end())
    {
      cout << "Found pair: "<< sum-a[i] << " " <<a[i] << endl;
      found = true;
    }
    
  }
  if(!found)
  {
    cout << "No pairs found" << endl;
  }
    
  
}


int main()
{
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int sum = 15;
  int n = sizeof(a)/sizeof(a[0]);
  
  findPair(&a[0], sum, n);
}
