/*
Validating a string acceptance by the given Deterministic Finite State Automata

Created on 13/01/2016 by Jigyasa Grover
*/


#include<iostream>
using namespace std;

int main()
{
	cout<<endl<<"*** Validating a string acceptance by the given Deterministic Finite State Automata ***"<<endl;
	
    string x;
    int instates, f;
    
    cout<<endl<<"Enter the no. of input states : ";
    cin>>instates;
    
    cout<<endl<<"Enter Transition Table for Deterministic Finite State Automata for two input variables say 0 and 1 as 'i' for transition to state Q'i': "<<endl;
    
    int in[instates][2];
    
    for(int i=0;i<instates;i++)
    {
    	cout<<"State Q"<<i<<": ";
    	
        for(int j=0;j<2;j++)
            cin>>in[i][j];
    }
    
   
    cout<<endl<<"Enter String : ";
        cin>>x;
        
    cout<<endl<<"Enter the number of final states : ";
    cin>>f;
    
    int fin[f];
    for(int i=0;i<f;i++)
    {
    	cout<<"Final State "<<i<<" : ";
    	cin>>fin[i];
    }
        
    
    //Starting from initial state, i.e. Q0
    int currentstate = 0;
    
    for(int i=0;i<x.length();i++)
        currentstate = in[currentstate][x[i]-48];
    
    int flag = 0;
    for(int i=0;i<f;i++)
        if(fin[i] == currentstate)
        {
            flag = 1;
            break;
        }
    
    if(flag == 1)
        cout<<endl<<"Accepted !"<<endl<<endl;
    else
        cout<<endl<<"Not Accepted !"<<endl<<endl;
    
}
