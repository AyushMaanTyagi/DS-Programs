 #include <bits/stdc++.h >
 #include <iostream>
struct triplet
{
    int x,y,g;
};
typedef struct triplet triplet;
triplet EEuclediaan(int a,int b)
{
    triplet ans,Int_ans;
    if(b==0)
    {
        ans.x=1;
        ans.y=0;
        ans.g=a;
    }
    else
    {
    Int_ans=EEuclediaan(b,a%b);
    ans.x=Int_ans.y;
    ans.y=Int_ans.x-(a/b)*(Int_ans.y);
    ans.g=Int_ans.g;
    return ans;
    }
}
int MMinverse(int a,int m)
{
   triplet mmi;
   mmi=EEuclediaan(a,m);
   if(mmi.x<0)
   {
     mmi.x=mmi.x+m;
   }
   cout<<mmi.x; 
   return 1;
}
int main()
{
    // triplet ans;
    // ans=EEuclediaan(4,8);
    // printf("%d %d %d",ans.x,ans.y,ans.g);
    // printf("\n\n");
    // ans=EEuclediaan(5,7);
    // printf("%d %d %d",ans.x,ans.y,ans.g);
     MMinverse(17,6);
     MMinverse(23,4);

}