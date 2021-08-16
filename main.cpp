#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main() {
  string str1;
  int lc=0;
  int mc=0;
  int sc=0;
  cin >> str1;
  char s[str1.size()];
  char sd[str1.size()];
  strcpy(s,str1.c_str());
  int sl=strlen(s);

for(int i=0;i<sl;i++)
{ 
  if ((s[i]!='L')&&(s[i]!='M')&&(s[i]!='S')){
    cout << "Invalid input\n";
    return 1;
  }

  if (s[i]=='L'){
    lc++;
  }
  if (s[i]=='M'){
    mc++;
  }
  if (s[i]=='S'){
    sc++;
  }
  
}

int ls=0;
int le=lc-1;
int ms=lc;
int me=lc+mc-1;
int ss=lc+mc;
int se=lc+mc+sc-1;

for(int i=ls;i<=le;i++)
  {sd[i]='L';}
for(int i=ms;i<=me;i++)
  {sd[i]='M';}
for(int i=ss;i<=se;i++)
  {sd[i]='S';}

cout<<"\n";
if (sl<=20){
  cout<<"\t";
  for(int i=0;i<sl;i++)
    { cout << s[i]<<"\t";}
    cout<<"\n\n\n";
}

char t;
int a=0,b=0;
int step=0;

for(int i=0;i<sl;i++)
{
  if (s[i]!=sd[i]){
    if ((ls<=i)&&(i<=le)){
      t='L';
    }
    if ((ms<=i)&&(i<=me)){
      t='M';
    }
    if ((ss<=i)&&(i<=se)){
      t='S';
    }

    if (s[i]=='S'){
      a=ss;
      b=se;
    }
    if (s[i]=='M'){
      a=ms;
      b=me;
    }
    if (s[i]=='L'){
      a=ls;
      b=le;
    }

    bool found=false;
    int j=a;
    while ((!found)&&(j<=b))
    {
      if(s[j]==t){
        found=true;
        int z=s[j];
        s[j]=s[i];
        s[i]=z;
        step++;
        if (sl<=20){
          cout << step<<": \t";
          for(int m=0;m<sl;m++)
            { cout << s[m]<<"\t";}
          cout<<"\n\t"; 
          for(int m=0;m<sl;m++)
            if ((m==i)||(m==j)){ 
              cout << "^" <<"\t";
            } else{
              cout << " " <<"\t";
            }
          cout<<"\n\n"; 
        } else {
          cout << step<<":\t"<<i+1<<"\t<->\t"<<j+1<<"\n";
        }
      }
      j++;
    }
    if (!found){
      int k=a;
      bool f=false;
      while ((!f)&&(k<=b))
      {
        if(s[k]!=s[i]){
          f=true;
          int w=s[k];
          s[k]=s[i];
          s[i]=w;
          step++;
          if (sl<=20){
            cout <<step<<": \t";
            for(int m=0;m<sl;m++)
              { cout << s[m]<<"\t";}
            cout<<"\n\t"; 
            for(int m=0;m<sl;m++)
              if ((m==i)||(m==k)){ 
                cout << "^" <<"\t";
              } else{
                cout << " " <<"\t";
              }
            cout<<"\n\n"; 
          } else {
          cout << step<<":\t"<<i+1<<"\t<->\t"<<k+1<<"\n";
          }
        }
        k++;
      }
    }
    i--;
  }
}
cout <<"\nTotal books: " << sl << "\n";
cout <<"\nTotal steps: " << step << "\n";


}