#include<iostream>
using namespace std;

int main()
{
  int arr[] = {1,1,0,1,0,0,0,1,1,1,0,0,1,0,0,0,0};
  int size = sizeof(arr)/sizeof(arr[0]);
  int count0 = 0;
  for (int i = 0; i<n; i++)
  {
    if(arr[0] == 0)
    {
      count0++;
    }
  }
  for(int i = 0; i<n; i++)
  {
    if(i < count0)
    {
      a[i] = 0;
    }else{
      a[i] = 1;
    }
  }
    for(int i = 0; i<n; i++)
    {
      cout << a[i] << endl;
    }
}
