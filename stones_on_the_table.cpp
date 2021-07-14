#include <iostream>

using namespace std;

// Check if string components are unique
bool areUnique(string colors)
{
  bool ok=1;

  for(int i=0; i<colors.length()-1; i++)
    if(colors[i] == colors[i+1])
      ok=0;

  return ok;
}

// Remove a letter from string
void remove(string colors, int i)
{
  for(int i=0; i<colors.length()-1 ;i++)
    colors[i] = colors[i+1];

  colors[colors.length()-1] = 0;
}

int main(){
  int stones, stones_to_remove;
  string colors;
  // Get the number of stones
  cin>>stones;
  // Get the string of colors
  // RGBRR
  cin>>colors;

  // Index to increment in while
  int i=0;

  while(!areUnique(colors))
  {
    if(colors[i] == colors[i+1])
    {
      remove(colors, i);
      stones_to_remove++;
    }
    i++;
  }

  // Output the numbers of stones to remove
  // Eg. 1 for RGBB, 2 for RGGBB
  cout<<stones_to_remove;

  return 0;
}
