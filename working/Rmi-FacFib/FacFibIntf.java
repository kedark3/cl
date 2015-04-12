import java.rmi.*;
public interface FacFibIntf extends Remote{
	int factorial(int m) throws RemoteException;
	int[] fibonacci(int m) throws RemoteException;
}
