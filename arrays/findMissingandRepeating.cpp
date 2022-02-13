      
       //useing bitset 
       int r=0;
       for(int i=0;i<n;i++)
       r=r^arr[i];
       for(int i=1;i<=n;i++)
       r=r^i;
       int sb=r&(~(r-1));
       int fst=0,snd=0;
       for(int i=0;i<n;i++)
       {
           if((arr[i]&sb)!=0)
           fst=fst^arr[i];
           else
           snd=snd^arr[i];
           if(((i+1)&sb)!=0)
           fst=fst^(i+1);
           else
           snd=snd^(i+1);
       }
       bool flag=false;
       for(int i=0;i<n;i++)
       {
           if(arr[i]==fst)
           {
               flag=true;
               break;
           }
       }
       int ar[2];
       if(flag)
       {
           ar[0]=fst;
           ar[1]=snd;
       }
       else
       {
           ar[0]=snd;
           ar[1]=fst;
       }
       int *p=ar;
       return p;
