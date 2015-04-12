import java.rmi.*;
import java.rmi.server.*;

public class SumServerImpl extends UnicastRemoteObject implements SumServerIntf {
	public SumServerImpl() throws RemoteException {
	
	}
	public int sum(int m,int n) throws RemoteException {
		return m+n;
	}
	public int sub(int m,int n) throws RemoteException {
		return m-n;
	}
	public int mul(int m,int n) throws RemoteException {
		return m*n;
	}
	public int div(int m,int n) throws RemoteException {
		return m/n;
	}
	public int exp(int m,int n) throws RemoteException {
		return m^n;
	}

}
