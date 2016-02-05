/*
	Finding the first and follow of all non-terminals in the given grammar.
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int NT;
	cout<<"Enter total number of non terminals: ";
    cin>>NT;
    
    char NonTerminal[100];
    cout<<"Enter Non Terminals: "<<endl;
    
    for(int i=0;i<NT;i++)
    {
        cout<<i+1<<" : ";
        cin>>NonTerminal[i];
    }
    
    int n;
    string str;
    vector<string> Prod[100];
    for(int i=0;i<NT;i++)
    {

        cout<<"Enter total number of production for (use e for Epsilon Symbol) "<<NonTerminal[i]<<": ";
        cin>>n;
        cout<<"Enter Productions:"<<endl;
        
        for(int j=0; j<n; j++)
        {
            cout<<"Production "<<i+1<<" : ";
            cin>>str;
            Prod[i].push_back(str);
        }
    }
    
    char X;
    cout<<"Enter the non terminal for which first is to be found: ";
    cin>>X;
    
    char First[NT][100];
    
    //if X is a non-terminal
    
    
    
    
   return 0;
}
