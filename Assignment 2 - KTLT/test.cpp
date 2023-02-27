#include <iostream>
#include <fstream>
#include "studyInPink3a.h"
using namespace std;


int main(){
    cout<<"Done!"<<endl;
    ifstream input("test_case_1000_input.txt");
    ifstream output("test_case_1000_output.txt");
    for (int k =0;k<1000;k++){
    int watson_moves;
    Character watson = Character("watson");
    Character murder = Character("murder");
    input>>watson_moves;
    for (int i=0;i<watson_moves;i++){
	    int x;
        int y;
        input>>x>>y;
        watson.moveToPoint(x,y);
    }
    int mur_moves;
    input>>mur_moves;
    for (int i=0;i<mur_moves;i++){
	    int x;
        int y;
        input>>x>>y;
        murder.moveToPoint(x,y);
    }
    int max_len;
    int max_dis;
    input>>max_len>>max_dis;
    int outdis;
    int result = rescueSherlock(murder,watson,max_len,max_dis,outdis);
    int outdis0;
    int result0;
    output>>result0>>outdis0;
    if ((result==result0)&&(outdis==outdis0))
        cout<<"TEST #"<<k+1<<" :OK"<<endl;
    else
    {
        cout<<"TEST #"<<k+1<<" :FAILED";
        return 0;
    }
    }
    return 0;
}