#include <iostream>  
using namespace std; 

/*
QUESTION:
Compare Bubble sort and Selection sort based on the following:
1. Number of comparisons
2. Number of swaps
3. Inplace and Outplace implementations
*/


//SOLUTION

//Function Implementing Bubble Sort Algorithm
void bubble_sort(int arr[],int n){
    int i=0,j=1,t=n-1;
    int no_of_swap=0;
    int no_of_comp=0;
    while(t>0){
        while(j<=t){
            if(arr[i]>arr[j]){swap(arr[i],arr[j]);no_of_swap++;}
            i++,j++;
            no_of_comp++;
        }
        t--;
        i=0,j=1;
    }
    cout<<" . Number of SWAP:"<<no_of_swap<<endl;
    cout<<" . Number of COMPARISON:"<<no_of_comp<<endl;
    cout<<" . [INPLACE SORTING ALGORITHM USED]"<<endl;
}

//Function that returns index of minimum value in an array
int min_ind(int arr[],int si,int ei){
    //Initialising minimum value as first element of array
    int m=arr[si];             //m=minimum value in array
    int min_ind=si;           //min_ind=index holding minimum value
    for(int i=si;i<=ei;i++){
        int min_prev=m;
        m=min(m,arr[i]);
        if(m<min_prev){min_ind=i;}
    }
    return min_ind;
}

//Function Implementing Selection-Sort Algorithm
void selection_sort(int arr[],int n){
    //si=starting index
    //ei=ending index
    int si=0,ei=n-1;
    int no_of_swap=0;
    int no_of_comp=0;
    while(si<ei){
    int mi=min_ind(arr,si,ei);  //mi=index holding minimum value
    no_of_comp=no_of_comp+(ei-si+1);
    if(si!=mi){swap(arr[si],arr[mi]);
    no_of_swap++;}
    si++;
    }
    cout<<" . Number of SWAP:"<<no_of_swap<<endl;
    cout<<" . Number of COMPARISON:"<<no_of_comp<<endl;
    cout<<" . [INPLACE SORTING ALGORITHM USED]"<<endl;
}

//Function to print the array
void pfun(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    //n=number of elements in the array
    int n;
    //taking number of elements as input from the user
    cout<<"Enter number of elements in array:";cin>>n;
    //array of size n
    int arr1[n];int arr2[n];
    //taking array as input from the user
    cout<<"Enter elements of array:";
    for(int i=0;i<n;i++){int a;cin>>a;arr1[i]=a;arr2[i]=a;}
    //printing array before sorting
    cout<<"\nARRAY before sorting:";pfun(arr1,n);
    cout<<endl;
    //sorting array using bubble sort and printing it
    cout<<"BUBBLE SORT"<<endl;
    bubble_sort(arr1,n);
    cout<<" . ARRAY After Sorting Using Bubble Sorting:";pfun(arr1,n);
    cout<<endl;
    //sorting array using insertion sort and printing it
    cout<<"SELECTION SORT"<<endl;
    selection_sort(arr2,n);
    cout<<" . ARRAY After Sorting Using Selection Sorting:";pfun(arr2,n);
}
/*

BONUS QUESTION

TIME COMPLEXITY OF BUBBLE SORT
   From the above code of BUBBLE SORT we can see that there are two
   while loops which will we executed.First while loop will run n-1
   times and second while loop will run n-2 times and so on till 1 time.
   Time Complexity=(n-1)+(n-2)+(n-3)....+2+1=(n-1)(n)/2
                  =O(n^2)

TIME COMPLEXITY OF SELECTION SORT
    In selection sort the main time consuming task is finding minimum 
    element from the array.We have to scan all the elements of the
    array to find the minimum element.
    With reference to the above code of SELECTION SORT,first we will 
    search for minimum element in array of size n,then in the same array of size n-1,and so on till array of size 1.
    Time Complexity=(n)+(n-1)+(n-2)...1=(n)(n+1)/2
                   =O(n^2)



Sid - 21105118
Rajdeep Singh
*/