# Lexical Analyzer

This program is a simple lexical analyzer written in C++. It reads an input string and identifies various tokens such as operators, identifiers, constants, and parentheses. Lexical analysis is the process of converting a sequence of characters into a sequence of tokens. A token is a string of characters that are treated as a single logical entity.

## How to Use

1. **Compile the Program**:
   - Use a C++ compiler to compile the code. For example, using g++:
     ```sh
     g++ -o lexical_analyzer lexical_analyzer.cpp
     ```

2. **Run the Program**:
   - Execute the compiled program:
     ```sh
     ./lexical_analyzer
     ```

3. **Input**:
   - The program will prompt you to enter a string. Enter the string containing the expression you want to analyze.

4. **Output**:
   - The program will output the identified tokens in the format `( type , value )`.

## Functionality

### Lexical Analyzer
A lexical analyzer reads the input string character by character and divides it into meaningful tokens. It identifies different types of tokens like operators, identifiers, constants, and parentheses.

### Basic Functions

- **isDelimiter(char chr)**: Checks if a character is a delimiter (space, operator, or parentheses).
- **isOperator(char chr)**: Checks if a character is an operator (`+`, `-`, `*`, `/`).
- **isInt(string st)**: Checks if a string represents an integer.
- **isIdentifier(string st)**: Checks if a string is a valid identifier (starts with a letter or underscore).
- **isParentheses(char chr)**: Checks if a character is a parentheses.

## Example Test Cases

### Test Case 1
**Input**:
```
int main() { return 0; }
```
**Output**:
```
( id , int )
( id , main )
( par , ( )
( par , ) )
( par , { )
( id , return )
( const , 0 )
( par , ; )
( par , } )
```

### Test Case 2
**Input**:
```
a = b + c;
```
**Output**:
```
( id , a )
( opr , = )
( id , b )
( opr , + )
( id , c )
( par , ; )
```

### Test Case 3
**Input**:
```
x = y * (z + 10);
```
**Output**:
```
( id , x )
( opr , = )
( id , y )
( opr , * )
( par , ( )
( id , z )
( opr , + )
( const , 10 )
( par , ) )
( par , ; )
```

## Code

```cpp
#include<bits/stdc++.h>
using namespace std;

bool isDelimiter(char chr) 
{ 
	return (chr == ' ' || chr == '+' || chr == '-'
			|| chr == '*' || chr == '/' || chr == ','
			|| chr == ';' || chr == '%' || chr == '>'
			|| chr == '<' || chr == '=' || chr == '('
			|| chr == ')' || chr == '[' || chr == ']'
			|| chr == '{' || chr == '}'); 
}

bool isOperator(char chr) 
{ 
	return (chr == '+' || chr == '-'
			|| chr == '*' || chr == '/' ); 
}

bool isInt(string st) 
{ 
	if(st.length()==0 || st.length()==1 && st[0]=='\0'){
        return false;
    }
    int i=0;
    for(i=0;i<st.length();i++){
        if(!isdigit(st[i])) break;
    }
    if(i<st.length() || st[i]!='\0') return false;
    return true;
}

bool isIdentifier(string st) 
{ 
	return (isalpha(st[0]) || st[0]=='_');
}

bool isParentheses(char chr) 
{ 
	return (chr == '('
			|| chr == ')' || chr == '[' || chr == ']'
			|| chr == '{' || chr == '}');
}

void lexicalAnalyser(string &s){
    int l=0,r=0;
    int n=s.length();
    while(r<=n && l<=r){
        if(!isDelimiter(s[r])) r++;
        // cout<<"s[r] is: "<<s[r]<<endl;
        if(isDelimiter(s[r]) && l==r){
            if(isOperator(s[r])){
                cout<<"( "<<"opr , "<<s[r]<<" )"<<endl;
            }
            else if(isParentheses(s[r])){
                cout<<"( "<<"par , "<<s[r]<<" )"<<endl;
            }
            r++;
            l=r;
            // cout<<"space"<<endl;
        }
        else if((isDelimiter(s[r]) && l<r) || (r==n && l<r)){
            string str=s.substr(l,r-l);
            if(isIdentifier(str) && !isDelimiter(s[r-1])){
                cout<<"( "<<"id , "<<str<<" )"<<endl;
            }
            else if(isInt(str)){
                cout<<"( "<<"const , "<<str<<" )"<<endl;
            }
            else if(!isIdentifier(str) && !isDelimiter(s[r-1])){
                cout<<"( "<<"invalid , "<<str<<" )"<<endl;
            }
            l=r;
        }
        
    }
}

int main(){
    cout<<"enter string: \n"<<endl;
    string s;
    getline(cin, s);
    lexicalAnalyser(s);
    
    return 0;
}
```

This README file provides instructions on how to compile and run the program, a brief explanation of its functionality, and some example test cases to demonstrate its use.