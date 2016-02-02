/*
	Converting given left recursive grammar to right recursive grammar.
	Created on 02/02/2016 by Jigyasa Grover
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int NT, i, j, k, n;
    string str;
    char NonTerminal[100];
    
    vector<string> Prod[100];
    vector<string> alpha, beta;
    
    cout<<endl<<endl<<"*** Converting given left recursive grammar to right recursive grammar ***"<<endl<<endl;
    
    cout<<"Enter total number of non terminals:";
    cin>>NT;
    
    cout<<"Enter Non Terminals                :"<<endl;
    
    for(i=0;i<NT;i++)
    {
        cout<<i+1<<" : ";
        cin>>NonTerminal[i];
    }
    
    
    for(i=0;i<NT;i++)
    {

        cout<<"Enter total number of production for "<<NonTerminal[i]<<": ";
        cin>>n;
        cout<<"Enter Productions                  :"<<endl;
        
        for(j=0; j<n; j++)
        {
            cout<<"Production "<<i+1<<" : ";
            cin>>str;
            Prod[i].push_back(str);
        }
    }
    
    
    for(i=0; i<NT; i++)
    {
        for(j=0; j<Prod[i].size(); j++)
        {
            if(Prod[i][j][0] == NonTerminal[i])
            {
                alpha.push_back(Prod[i][j].substr(1, Prod[i][j].length()-1 ));
            }
            else
            {
                beta.push_back(Prod[i][j]);
            }
        }
        
        if(alpha.size() > 0)
        {
            cout<<NonTerminal[i]<<" -> ";
            for(j=0; j<beta.size(); j++)
            {
                cout<<beta[j]<<NonTerminal[i]<<"'"<<"|";
            }
            cout<<endl;

            cout<<NonTerminal[i]<<"' -> ";
            for(j=0;j<alpha.size();j++)
            {
                cout<<alpha[j]<<NonTerminal[i]<<"'|";
            }
            
            cout<<"e"<<endl;

            alpha.clear();
            beta.clear();
        }
        
        else
        {
            cout<<NonTerminal[i]<<" -> ";
            
            for(j=0;j<beta.size();j++)
            {
                cout<<beta[j]<<"|";
            }
            cout<<endl;
        }
    }
    return 0;
}
