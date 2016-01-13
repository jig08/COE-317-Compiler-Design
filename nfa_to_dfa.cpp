/*
Converting a given Non-Deterministic Finite State Automata having 4 states and 2 input variables to a 
Deterministic Finite State Automata

Created on 13/01/2016 by Jigyasa Grover
*/

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
	cout<<endl<<"***Converting a given Non-Deterministic Finite State Automata having 4 states and 2 input variables to a Deterministic Finite State Automata***"<<endl;
	
    int input[4][2],output[16][2],flag[16];

    for(int i=0;i<16;i++)
	{
        flag[i] = 0;
        
        for(int j=0;j<2;j++)
            output[i][j] = 0;
    }
    
    cout<<endl<<"Input the Transition Table for two input variables say 0 and 1 in integer form of bit-masked numbers (Q3_Q2_Q1_Q0): "<<endl;
    for(int i=0;i<4;i++)
    {
    	cout<<"State Q"<<i<<": ";
        for(int j=0;j<2;j++)
            cin>>input[i][j];
    }
    
    vector <int> v;
    //Starting from State Q0
    v.push_back(1);
    
    while(v.size()!=0)
    {
        int t = v[0];
        v.erase(v.begin());
        
        if(flag[t] == 0)
        {
            flag[t] = 1;
            
            for(int j=0;j<2;j++)
            {
                int newstate = 0;
                
                for(int i=0;i<4;i++)
                {
                    int a = pow(2,i);
                    
                    if((t&a) == a)
                        newstate = (newstate|input[i][j]);
                }
                
                int temp_flag = 0;
                
                for(int i=0;i<v.size();i++)
                {
                    if(v[i] == newstate)
                    {
                        temp_flag = 1;
                        break;
                    }
                }
                
                output[t][j] = newstate;
                
                if(flag[newstate] == 0 && temp_flag == 0)
                {
                    //cout<<newstate<<endl;
                    v.push_back(newstate);
                }
            }
        }
    }
    
    cout<<endl<<"Transition Table for two input variables say 0 and 1 in integer form of bit-masked numbers (Q3_Q2_Q1_Q0): "<<endl;
    for(int i=0;i<16;i++)
        cout<<"State \tQ"<<i<<": \t"<<output[i][0]<<"\t"<<output[i][1]<<endl;
        
        cout<<endl<<endl;
}
