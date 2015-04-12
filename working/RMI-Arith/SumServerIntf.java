import java.rmi.*;

public interface SumServerIntf extends Remote{
	int sum(int m, int n) throws RemoteException;
	int sub(int m, int n) throws RemoteException;
	int mul(int m, int n) throws RemoteException;
	int div(int m, int n) throws RemoteException;
	int exp(int m, int n) throws RemoteException;
}
