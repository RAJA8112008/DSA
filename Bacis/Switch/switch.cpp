int getPivot(vector<int>& arr,int n){
    int s=0;
    int e=n-1;
    while(s<e){
        int mid=s+(e-s)/2;
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    return s;
}
int binarySearch(vector<int>& arr,int start,int end,int key){
    int s =start;
    int e =end;
    while(s<=e){
        int mid=s+ (e-s)/2;
        if(arr[mid]>key){
            e=mid-1;
        }
        else if(arr[mid]<key){
            s=mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int search(vector<int>& arr, int n, int k)
{
   int pivot=getPivot(arr,n);
  if(k>=arr[pivot] && k<=arr[n-1]) {
       return binarySearch(arr,pivot,n-1,k);
   }
   else{
       return binarySearch(arr,0,pivot-1,k);
   }
}
