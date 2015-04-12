import java.rmi.*;
import java.rmi.server.*;

public class FacFibImpl extends UnicastRemoteObject implements FacFibIntf{
	public FacFibImpl() throws RemoteException{
	}
	public int[] fibonacci(int m) throws RemoteException{
		int i,a=1,b=1,c=0,t;

		int arr[]=new int[10];
		arr[0]=a;
		arr[1]=b;

		for(i=0;i<m-2;i++) {
			c=a+b;
			a=b;
			b=c;
			arr[i+2]=c;
		}
		return arr;
	}
	public int factorial(int m) throws RemoteException{
		int fact=1;
		for(int k=1;k<=m;k++)
		{
			fact=fact*k;
		}
		return fact;
	}
}
