// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution {
  public:

    void heapify(int index,vector<int>&arr,int size)
    {
      //now apply heappify for index also make sure u dont need any while loop to execute the proccess just keep calling it at the end with updated values , so the flow of the heapify func does not gets break
      int biggest = index;
      int left = index*2+1;
      int right = index*2+2;
      // since it is a 0 based indexded so we will be looking for the right and left child like this
      //if the child are short , small just swap them 
      if(left < size && arr[left] > arr[biggest]) biggest=left;
      if(right < size && arr[right] > arr[biggest]) biggest=right;
      //if possibly any of the chenges have been made in the variables that means it is not in its correct place
      if(biggest!=index)
      {
        swap(arr[biggest],arr[index]);
        //call heapify for the changed index now
        heapify(biggest,arr,size);
      }
    }
    //done and dusted


    // Function to sort an array using Heap Sort.
    void heapSort(vector<int>& arr) {
        // code here
      //first task is o create a max heap using heapify function
      // here we know that there are leaf nodes from  n/2 to last so no need to process them , go for building the heap from n/2 nodes and heapify it up
      int n =arr.size();
      for(int i = n/2-1 ; i>=0; i--)
        {
          heapify(i,arr,n);
        }
      //for now you have created  the max heap task is to now sort the avaliable node using heap sort
      //what is heapsort ?
      // full fledge sorting algorithm that sorts the entire array with 0(nlogn) time complexity and uses heapify as a routine multiple times
      // start sorting from the back of the array 
      for(int i=n-1;i>0;i--)
        {
          //swap the content
          swap(arr[0],arr[i]);
          //now heapify it
          heapify(0,arr,i);    //why did we passed 0 as the index cause it will allow you to start heapify from the first node 
          //why first node > because since it was a maxheap it would have contained largest in the 0 index so we have directly moved it up to the last position and now applying heapify from the first position 
          //ensure thet heapify down goes correct till the size also keeps decrementing on its on
        }
    }
};
