public class SortOnPerm {
	public static void main(String[] arg){
		int[] x = {0,3,5,1,4,2};//{0,17,5,1,9};
		int[] a = {0,4,2,3,1,5};//{0,3,2,4,1};
		
		mergeSort(a,x,1,a.length-1);
		for(int i=1;i<x.length;i++)
			System.out.print(x[i]+" ");
	}
	
	public static void mergeSort(int[] a,int[] x,int low,int high){
		if(low>=high)
			return;
		int mid = (low+high)/2;
		mergeSort(a,x,low,mid);
		mergeSort(a,x,mid+1,high);
		merge(a,x,low,mid,high);		
	}
	
	public static void merge(int[] a,int[] x,int low,int mid ,int high){
		for(int i=low,j=mid+1;i<=high&&j<=high;j++){
			if(i<=high && j<=high){
				if(a[j]<a[i]){
					int tmp = x[i];
					x[i] = x[j];
					x[j] = tmp;
					tmp = a[i];
					a[i] =a[j];
					a[j] = tmp;
					i++;j--;
				}
			}
		}
	}
}
