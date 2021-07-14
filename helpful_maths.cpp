#include <iostream>

using namespace std;

// newline
void br(){
  cout<<endl;
}

// Check if sorted
bool isSorted(int* a, int arr_len){
  bool ok=true;
  for(int i=0; i<arr_len; i++){
    if(a[i]>a[i+1])
      ok = false;
  }
  
  return ok;
}

// Adding element to end
void push_end(int* a,int i,int arr_len)
{
  int aux;
    aux = a[i];

  // Shifting to left  
  for(int x=i;x<arr_len-1;x++)
    a[x] = a[x+1];

  a[arr_len-1] = aux;
}

void push_beg(int* a,int i, int arr_len)
{
  int aux = a[i];

  // shifting to right
  for(int x=i; x>0; x--)
    a[x] = a[x-1];

  a[0] = aux;
}

void print_arr(int *a, int arr_len)
{
  // Printing the array
  for(int i=0; i<arr_len; i++)
    cout<<a[i]<<endl;
}

int main()
{
  string s="2+1+2+2+2+3+3+1+3+1+2";
  cin>>s;
  int arr_len=(s.length()+1)/2;
  int a[arr_len];

  // Printing the initial string
  /* cout<<s; */
  /* br(); */

  // Getting the numbers
  for(int i=0; i<arr_len; i++){
    a[i]=s[i*2]-48;
  }

  /* print_arr(a,arr_len); */
  /* br(); */

  // Defining the index
  int i=0;

  // Sorting the array
  while(!isSorted(a, arr_len)){
      if(a[i]==3)
      {
        push_end(a, i, arr_len);
        i--;
      }
      else if(a[i]==1)
        push_beg(a, i, arr_len);
      i++;
    }
  
  /* br(); */
  /* print_arr(a,arr_len); */
  /* br(); */

  // Creating the ordered string
  for(int i=0; i<arr_len; i++)
  {
    s[i*2] = a[i] + 48;
  }

  cout<<s;

  return 0;
  }
