/*
Tokenizing a given code snippet

Created on 20/01/2016 by Jigyasa Grover
*/

#include<iostream>
#include<string>
using namespace std;

string keywords[12] = {"if" , "else" , "for", "int", "while", "string", "include", "return", "iostream", "void", "main", "print"};
string operators[8] = {"+" , "=", "-" ,"*" ,"/" , "<" , ">", "%"};
string specialsymbols[8] = {";" , "{" , "}" , "(" , ")", "[", "]" , "," };

void findtype(string word)
{
	cout<<">  Token \""<<word<<"\" is  ";
	
	int flag = 0;
	
	for(int i = 0;i<12 ;i++)
	{
		if(keywords[i] == word)
		{
			cout<<"a Keyword (keywords["<<i<<"])."<<endl;
			flag = 1;
			break;
		}
	}
	
	if(flag == 0)
	{
		for(int i = 0;i<8 ;i++)
		{
			if(operators[i] == word)
			{
				cout<<"an Operator (operator["<<i<<"])."<<endl;
				flag = 1;
				break;
			}
		}
	}
	
	if(flag == 0)
	{
		for(int i = 0;i<8 ;i++)
		{
			if(specialsymbols[i] == word)
			{
				cout<<"a Special symbol (specialsymbols["<<i<<"])."<<endl;
				flag = 1;
				break;
			}
		}
	}
	
	if(flag ==0)
		cout<<"an Identifier"<<endl;
}

int checkDelimiter(int a)
{
	//a is a blank space
	if(a == 32)
		return 1;
	
	//a = '(' or ')' or '+' or ',' or '-' or '*' or '#' or '%' or ''' or ';' or '<' or  '=' or '>'
	else if(a == 35 || (a >=40 && a<= 45) || a == 47 || (a>=59 && a<=62))
	{
		cout<<">  Token \""<<char(a)<<"\" is a de-limiter in [( ) + - , * # % ' ; < = >]."<<endl;
		return 1;
	}
	
	else
		return 0;
}

int main()
{
	cout<<endl<<"***Tokenizing a given sample input code snippet***"<<endl<<endl;
	
	string input;	
	cout<<"Enter sample program/code snippet (without new line): "<<endl<<endl;
	getline(cin, input);
	
	cout<<endl<<endl<<"Tokenizing..."<<endl<<endl;
	
	int initial = 0,count = 0;
	
	string word; 
	while(count<input.length())
	{
		//if current symbol is a delimiter
		if(checkDelimiter((int)input[count]))
		{
			word = input.substr(initial,(count-initial)); 
			findtype(word);
			count++;
			initial = count;
		}
		count ++;
	}
	
	word = input.substr(initial,(count-initial));
	findtype(word); 
	
	cout<<endl<<endl;
	return 0;
}
