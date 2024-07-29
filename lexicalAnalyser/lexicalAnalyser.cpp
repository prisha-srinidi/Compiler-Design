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
	if(st.length()==0){
        return false;
    }
    int i=0;
    for(i=0;i<st.length();i++){
        if(!isdigit(st[i])) break;
    }
    if(i<st.length()) return false;
    return true;
}

bool isIdentifier(string st) 
{ 
	return (isalpha(st[0]) );
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
                cout<<"( "<<" , "<<s[r]<<" )"<<endl;
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