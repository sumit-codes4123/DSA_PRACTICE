class Solution {
public:
    bool isPalindrome(string s) {
        string st;
        for (char c: s){
            if(isalnum(c)){
                st+= tolower(c);
            }
        }
        int i=0,j=st.size()-1;
      while(i<=j)
      {
                   if(!isalnum(st[i])){i++; continue;}
           if(!isalnum(st[j])){j--;continue;}

        if((st[i])!=(st[j]))   
        {return false;
        } 
        else
        {
            i++;
            j--;
        }
      }return true;
    }

};