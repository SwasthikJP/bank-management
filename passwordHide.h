#include<string>
#include<conio.h>

using namespace std;

int getInput(){
     string res;
    char c;
    
    do{
        c = getch();
        switch(c){
        case 0://special keys. like: arrows, f1-12 etc.
            getch();//just ignore also the next character.
            break;
        case 13://enter
            cout<<endl;
            break;
        case 8://backspace
            if(res.length()>0){
                res.erase(res.end()-1); //remove last character from string
                cout<<c<<' '<<c;//go back, write space over the character and back again.
            }
            break;
        default://regular ascii
            res += c;//add to string
            cout<<'*';//print `*`
            break;
        }
    }while(c!=13);
    //print result:
  return stoi(res);
}