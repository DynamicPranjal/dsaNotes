    // code here
    int indf=-1,inds=-1;
    int s=0,e=n-1;
    while(s<=e){
        int mid=(e-s)/2+s;
        if(arr[mid]==x){
            indf=mid;
            e=mid-1;
        }
        else if(arr[mid]<x){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    
    s=0,e=n-1;
    while(s<=e){
        int mid=(e-s)/2+s;
        if(arr[mid]==x){
            inds=mid;
            s=mid+1;
        }
        else if(arr[mid]<x){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    
    return {indf,inds};
