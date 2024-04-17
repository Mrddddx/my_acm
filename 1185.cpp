#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int m,n;
int a[100][100];
char c[4000][4000];
int length,width;//长和宽
void innovate()
{
    for(int i=length-1;i>=1;i--)
    {
        for(int j=1;j<=width;j++)
        { 
            
            if((c[i+1][j-1]=='o'||c[i+1][j-1]=='\\')&&c[i][j]=='\0') c[i][j]='\\';
            if((c[i+1][j+1]=='o'||c[i+1][j+1]=='/')&&c[i][j]=='\0') c[i][j]='/';
        
        }
    }
    ////////////////////////////////////////////////////////
        for(int i=length-1;i>=1;i--)
    {
        for(int j=1;j<=width;j++)
        { 
            if(c[i][j]=='k') c[i][j]='\0';
            if((c[i+1][j-1]!='o'&&c[i+1][j-1]!='\\')&&c[i][j]=='\\') c[i][j]='\0';
            if((c[i+1][j+1]!='o'&&c[i+1][j+1]!='/') &&c[i][j]=='/') c[i][j]='\0';
            if(c[i][j]=='o'&&c[i+1][j-1]!='\\'&&c[i+1][j+1]!='/') c[i][j]='\0';
        }
    }
    for(int i=1;i<length;i++)
    {
        for(int j=1;j<=width;j++)
        { 
            if(c[i][j]=='k') c[i][j]='\0';    
            if(c[i][j]=='o'&&c[i+1][j+1]!='/'&&c[i+1][j-1]!='\\') c[i][j]='\0';    
            if((c[i][j]=='/'&&c[i-1][j-1]!='/'&&c[i-1][j-1]!='o')) c[i][j]='\0';    
            if((c[i][j]=='\\')&&c[i-1][j+1]!='\\'&&c[i-1][j+1]!='o') c[i][j]='\0';    
        }
    }
}
void print()
{
    for(int i=length;i>=1;i--)
    {
        for(int j=1;j<=width;j++)
        if(c[i][j]!='\0') cout<<c[i][j];
        else cout<<' ';
        cout<<endl;
    }
}
int main()
{
    memset(a,0,sizeof(a));
    memset(c,0,sizeof(c));
    cin>>m>>n;
    width=6*(1<<(m-2))-1;
    length=(width+1)/2;
    int k;
    while(k<n)
    {
        int x,y;
        cin>>x>>y;
        a[x][y]=1;
        k++;
    }
    int halfwidth=width+1;
    int halflength=length;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=(1<<(i-1));j++)
        {
            if(halflength!=1)
            {
                if(a[i][j]==0)  c[halflength][halfwidth/2+halfwidth*(j-1)]='o';
                else c[halflength][halfwidth/2+halfwidth*(j-1)]='k';
            }
            else
            {   
                int l=-1+((j+1)/2*2)+(j/2*4);
                if(a[i][j]==0) c[halflength][l]='o';
                else c[halflength][l]='k';
            }
        }
        halfwidth= halfwidth>>1;
        halflength= halflength>>1;
        //cout<<halflength<<halfwidth<<endl;
    }
    innovate();
    print();
    system("pause");
    return 0;
}
/*


           o           
          / \          
         /   \         
        /     \        
       /       \       
      /         \      
     o           o     
    / \         / \    
   /   \       /   \   
  o     o     o     o  
 / \   / \   / \   / \ 
o   o o   o o   o o   o
4 3
3 2
4 1
3 4
*/