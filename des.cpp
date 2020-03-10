#include <string>
#include <iostream>
using namespace std;
typedef string String;
typedef int byte;

class Serial_ {
	public :
	
	void begin (int no) {}
	
	void print (String some_var) {
		cout << some_var;
	}
	void println (String some_var) {
		cout << some_var << endl;
	}
	
	void print (int some_var) {
		cout << some_var;
	}
	void println (int some_var) {
		cout << some_var << endl;
	}
};

Serial_ Serial = Serial_();


class Vector {
  private:
    int top = 0;
    int MAX = 10;
  public :
    String data[16];
    void push_back (String str) {
      
      Serial.print("No: ");
      Serial.println(this -> top);

        data[top] = str;
        top++;
      }
    String begin(){
      return data[0];
      }
    String end() {
      return data[top - 1];
      }
  };

int pow(int num, int p) {
  int n_num = 1;
  for (int i = 0; i < p; i++) {
    n_num *= num;
  }
  return n_num;
}

void swap(char &x, char &y) {
   char temp;
   temp = x; /* save the value at address x */
   x = y;    /* put y into x */
   y = temp; /* put x into y */
  
   return;
}

void swap(String &x, String &y) {
   String temp;
   temp = x; /* save the value at address x */
   x = y;    /* put y into x */
   y = temp; /* put x into y */
  
   return;
}


void reverseStr(String& str) 
{ 
    int n = str.length(); 
  
    // Swap character starting from two 
    // corners 
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
} 

String numToBin(int num) {
  String bin = "";
  for (int i = 0; i < 4; i++){
    bin += char((char)num%2 + '0');
    num = num/2;
  }
  reverseStr(bin);
  return bin;
}

String getNibble (char c) {
  if (c <= '9')
    return numToBin(int(c) - '0');
  else
    return numToBin(int(c) - '7');
}
char getChar (String nibble) {
  int num = 0;
  for (int i= 3; i >= 0; i--) {
    num += int(nibble[i] - '0') * pow(2, 3-i);
  }
  if (num <= 9)
    return (char)num + '0';
  else
    return (char)num + '7';
}

String hex2bin(String s) {
  
  String bin = "";
  for (int i = 0; i < s.length(); i++) {
    //cout << "Comp: " <<s[i]<<" "<< mp[s[i]] << " " << getNibble(s[i]) << endl;
    //bin += mp[s[i]];
    bin += getNibble(s[i]);
  }
  return bin;
}

String bin2hex (String s) {
  
  String hex = "";
  for (int i = 0; i < s.length(); i += 4) {
    String ch = s.substr(i, 4);
    hex += getChar(ch);
  }
  return hex;
}

String permute(String k, byte *arr, int n) {
  String per = "";
  for (int i = 0; i < n; i++) {
    per += k[arr[i] - 1];
  }
  return per;
}

//permutations start here

String initial_permutation (String pt) {
    byte initial_perm[64]=
    {   58,50,42,34,26,18,10,2, 
        60,52,44,36,28,20,12,4, 
        62,54,46,38,30,22,14,6, 
        64,56,48,40,32,24,16,8, 
        57,49,41,33,25,17,9,1, 
        59,51,43,35,27,19,11,3, 
        61,53,45,37,29,21,13,5, 
        63,55,47,39,31,23,15,7 
    };
    return permute(pt, initial_perm, 64);
}

String final_permutation (String pt) {
    byte final_perm[64]=  
   {    40,8,48,16,56,24,64,32, 
     39,7,47,15,55,23,63,31, 
     38,6,46,14,54,22,62,30, 
     37,5,45,13,53,21,61,29, 
     36,4,44,12,52,20,60,28, 
     35,3,43,11,51,19,59,27, 
     34,2,42,10,50,18,58,26, 
     33,1,41,9,49,17,57,25 
   };
   return permute(pt, final_perm, 64);
}

String expansion (String pt) {
    byte exp_d[48]=  
      {    32,1,2,3,4,5,4,5, 
          6,7,8,9,8,9,10,11, 
          12,13,12,13,14,15,16,17, 
          16,17,18,19,20,21,20,21, 
          22,23,24,25,24,25,26,27, 
          28,29,28,29,30,31,32,1 
      };
	  
	  return permute(pt, exp_d, 48);
}

String key_permutation (String key) {
    byte keyp[56]=  
      {    57,49,41,33,25,17,9, 
          1,58,50,42,34,26,18, 
          10,2,59,51,43,35,27, 
          19,11,3,60,52,44,36,           
          63,55,47,39,31,23,15, 
          7,62,54,46,38,30,22, 
          14,6,61,53,45,37,29, 
          21,13,5,28,20,12,4 
      };
	return permute(key, keyp, 56);
}

String key_compression(String key) {
    byte key_comp[48]= 
    {    14,17,11,24,1,5, 
        3,28,15,6,21,10, 
        23,19,12,4,26,8, 
        16,7,27,20,13,2, 
        41,52,31,37,47,55, 
        30,40,51,45,33,48, 
        44,49,39,56,34,53, 
        46,42,50,36,29,32 
    }; 
	return permute(key, key_comp, 48);
}

//permutations end here

String shift_left(String k, int shifts) {
  String s = "";
  for (int i = 0; i < shifts; i++) {
    for (int j = 1; j < k.length(); j++) {
      s += k[j];
    }
    s += k[0];
    k = s;
    s = "";
  }
  return k;
}

String xor_ (String a, String b) {
  String ans = "";
  for (int i = 0; i < a.length(); i++) {
    if (a[i] == b[i])
      ans += "0";
    else
      ans += '1';
  }
  return ans;
}

//part2

String encryption (String pt, Vector rkb, Vector rk) {
  pt = hex2bin(pt);
  Serial.println("point 1");
  
  pt = initial_permutation(pt);
  Serial.println("point 2");
  String left = pt.substr(0, 32);
  String right = pt.substr(32, 32);
  Serial.println("point 3");
  

  for (byte i = 0; i < 16; i++) {
  	byte s[8][4][16]= 
    {{ 
        14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7, 
        0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8, 
        4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0, 
        15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13 
    }, 
    { 
        15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10, 
        3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5, 
        0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15, 
        13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9 
    }, 
  
  
    { 
        10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8, 
        13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1, 
        13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7, 
        1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12 
    }, 
    { 
        7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15, 
        13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9, 
        10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4, 
        3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14 
    }, 
    { 
        2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9, 
        14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6, 
        4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14, 
        11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3 
    }, 
    { 
        12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11, 
        10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8, 
        9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6, 
        4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13 
    }, 
    { 
        4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1, 
        13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6, 
        1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2, 
        6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12 
    }, 
    { 
        13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7, 
        1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2, 
        7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8, 
        2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11 
    }}; 
    Serial.println("abc");
    String right_expanded = expansion(right);
    String x = xor_(rk.data[i], right_expanded);
    
    String op = "";
    
    for (byte i = 0; i < 8; i++) {
      int row = 2 * (x[i * 6] - '0') + (x[i * 6 + 5] - '0');
      int col = 8 * (x[i * 6 + 1] - '0') + 4 * (x[i * 6 + 2] - '0') + 2 * (x[i * 6 + 3] - '0')+ (x[i * 6 + 4] - '0');
      
      int val = s[i][row][col];
      op += char(val / 8 + '0');
      val = val % 8;
      op += char(val / 4 + '0');
      val = val % 4;
      op += char(val / 2 + '0');
      val = val % 2;
      op += char(val + '0');
    }
    byte per[32]= 
    {    16,7,20,21, 
        29,12,28,17, 
        1,15,23,26, 
        5,18,31,10, 
        2,8,24,14, 
        32,27,3,9, 
        19,13,30,6, 
        22,11,4,25 
    };
    op = permute(op, per, 32);
    
    x = xor_(op, left);
    
    left = x;
    
    if (i != 15) {
      swap(left, right);
    }
  }
    
  String combine = left + right;
  
  
  
  String cipher = bin2hex(final_permutation(combine));
  
  return cipher;
  
}


//part2

//part3

String encrypt(String pt, String key) {
  key = hex2bin(key);

  byte shift_table[16]= 
    {    1, 1, 2, 2, 
        2, 2, 2, 2,  
        1, 2, 2, 2,  
        2, 2, 2, 1 
    };
  
  //Key- Compression Table 
  
  String left = key.substr(0, 28);
  String right = key.substr(28, 28);

   Vector  rkb;
  Vector rk;

  for (byte i = 0; i < 16; i++) {
    left = shift_left(left, shift_table[i]);
    right = shift_left(right, shift_table[i]);
    
    String combine = left + right;
    
    String RoundKey = key_compression(combine);
    
    //rkb.push_back(RoundKey);
    rk.push_back(bin2hex(RoundKey));
  }

  String cipher = encryption(pt, rkb, rk);
  return cipher;
  
}



int main(){
  //Serial.begin(9600);
  //Serial.println("working");
	//String c =  encrypt("123456ABCD132536", "AABB09182736CCDD");
	String c = encrypt("D1B932CC749AB312", "AABB09182736CCDD");
	Serial.println(c);
  }
void loop(){
  
  }